#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>
void listenToPort()
{
    printf("start listening to port\n");
    char *zName = "name";

    //printf("Name: %s \n", zName);
    char *s1 = "insertc into ";
    char *result = malloc(100); // +1 for the null-terminator
    char *finalQuery = malloc(100);
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, zName);

    strcat(result, " valuesc(");
    printf("result %s \n", result);
    printf("hello from first\n");
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
        portno = 5002;

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
            strcpy(finalQuery, result);
            printf("final query %s\n ", finalQuery);
            char *num;
            char buffer2[100];

            if (asprintf(&num, "%d", value) == -1) {
                perror("asprintf");
            } else {
                strcat(strcpy(buffer2,  finalQuery), num);
                strcat(buffer2, ");");
                printf("%s\n", buffer2);
                free(num);
            }
           
            //printf("hello\n");

            //printf("value is %d\n", value);

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
    }
    else
    {
        client = fork();
        //client
        if (client == 0)
        {
            printf("client-------\n");
        }
        else
        {
            printf("parent-------\n");
        }
    }
}

int main(int argc, char *argv[])
{   
    listenToPort();
    printf("I am back again\n");
}