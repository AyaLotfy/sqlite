#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
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
int *fun()
{
    int maxTemp = 2;
    //int tmp[maxTemp];

    int *tmp = mmap(NULL, maxTemp * sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);
    int *pos = mmap(NULL, sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);

    size_t pos2 = 0;
    int val = 9;

    if (tmp == MAP_FAILED)
    {
        printf("Mapping Failed\n");
        return 1;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     ptr[i] = i + 1;
    // }

    // printf("Initial values of the array elements :\n");
    // for (int i = 0; i < N; i++)
    // {
    //     printf(" %d", ptr[i]);
    // }
    // printf("\n");

    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        //child
        // for (int i = 0; i < N; i++)
        // {
        //     ptr[i] = ptr[i] * 10;
        // }
        // *pos = 50;
        // while (1 > 0)
        // {
        //     printf("hello\n");
        //     usleep(400000);
        // }
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
        portno = 5021;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("ERROR on binding");
            exit(1);
        }
        while (1 > 0)
        {
            listen(sockfd, 5);
            clilen = sizeof(cli_addr);

            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

            if (newsockfd < 0)
            {
                perror("ERROR on accept");
                exit(1);
            }

            int value;
            read(newsockfd, &value, sizeof(int));   // &value returns the address to value
            read(newsockfd, &value, sizeof(value)); // Alternative version always using the proper type
            // printf("starfirst pos %d\n", *pos);
            // printf("pos2 first %d\n", pos2);
            if (*pos == 0)
            {
                pos2 = 0;
            }
            if (pos2 < maxTemp)
            {
                push(tmp, value, sizeof(tmp) / sizeof(tmp[0]), &pos2);
                //printf("value %d\n", value);
                *pos = pos2;
                // printf("star pos %d\n", *pos);
                // printf("pos2 %d\n", pos2);

                if (pos2 == maxTemp)
                {
                    // printf("tmp:");
                    // for (size_t i = 0; i < maxTemp; i++)
                    // {
                    //     printf(" %d", tmp[i]);
                    // }
                    // printf("\n");
                }
            }

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
        }
    }
    else
    {
        //parent
        //waitpid(child_pid, NULL, 0);

        //LOOP:
        do
        {
            while (*pos < maxTemp)
            {
                /* code */
            }

            //printf("\nParent:\n");

            //printf("Updated values of the array elements :\n");
            // for (int i = 0; i < maxTemp; i++)
            // {
            //     printf(" %d", tmp[i]);
            // }
            // printf("pos %d\n", *pos);
            // printf("\n");
            pid_t child_pid2 = fork();
            if (child_pid2 == 0)
            {
                return tmp;
            }
            else
            {
                // pos2 = 0;
                *pos = 0;
                // goto LOOP;
            }

        } while (1 > 0);
    }

    return 0;
}

int main()
{
    int *p;
    int i;

    p = fun();
    for (i = 0; i < 2; i++)
    {
        printf("*( %d) : %d \n", i, *(p + i));
    }
    //  listenToPort();
}