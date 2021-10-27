#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
int push(int arr[], int value, size_t size, size_t *current)
{
    if (*current < size)
    {
        arr[(*current)++] = value;
        return 0;
    }
    else
    {
        /* array is full */
        return -1;
    }
}

 int *
 listenToPort()
{
    int maxTemp = 2;
    int tmp[maxTemp];

    // int tmp = mmap(NULL, maxTemp * sizeof(int),
    //                PROT_READ | PROT_WRITE,
    //                MAP_SHARED | MAP_ANONYMOUS,
    //                0, 0);

    size_t pos = 0;
    size_t lastPos = 0;
    int val = 9;
    pid_t server, client;

    server = fork();
    //server
    if (server == 0)
    {
        int sockfd, newsockfd, portno, clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0)
        {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *)&serv_addr, sizeof(serv_addr));
        portno = 5005;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */
        while (1 > 0)
        {
            listen(sockfd, 5);
            clilen = sizeof(cli_addr);

            /* Accept actual connection from the client */
            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

            if (newsockfd < 0)
            {
                perror("ERROR on accept");
                exit(1);
            }

            /* If connection is established then start communicating */
            int value;
            read(newsockfd, &value, sizeof(int));   // &value returns the address to value
            read(newsockfd, &value, sizeof(value)); // Alternative version always using the proper type
            if (pos < maxTemp)
            {
                lastPos = pos;
                printf("%d\n", pos);
                push(tmp, value, sizeof(tmp) / sizeof(tmp[0]), &pos);
            }

            if (pos == maxTemp)
            {
                printf("tmp:");
                for (size_t i = 0; i < maxTemp; i++)
                {
                    printf(" %d", tmp[i]);
                }
                printf("\n");
            }

            printf("value is %d\n", value);

            /* Write a response to the client */
            n = write(newsockfd, "I got your message", 18);

            if (n < 0)
            {
                perror("ERROR writing to socket");
                exit(1);
            }
            else
            {
                printf("n>0 after writing\n");
            }
            close(newsockfd);
            //usleep(400000);
        }
        //       return 0;
    }
    else
    {
        client = fork();
        //client
        if (client == 0)
        {
            printf("client-------\n");
            printf("pos %d\n", pos);
            while (pos<maxTemp)
            {
                
            }

            if (pos == maxTemp)
            {
                printf("pos %d\n", pos);
                printf("hellooooooo\n");
                for (size_t i = 0; i < maxTemp; i++)
                {
                    printf(" %d", tmp[i]);
                }
                printf("\n");
            }
            printf("I will return tmp\n");
            //return tmp;
        }
        else
        {
            printf("parent-------\n");
            //return 0;
        }
    }
}
int main(int argc, char *argv[])
{
    // int *p;
    // int i;

    // p =
    listenToPort();

    // for (i = 0; i < 4; i++)
    // {
    //     printf("*(p + %d) : %d from main\n", i, *(p + i));
    // }
    printf("I am back again\n");
}