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
    int N = 5; // Number of elements for the array

    int *ptr = mmap(NULL, N * sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);
    int *pos = mmap(NULL, sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);

    if (ptr == MAP_FAILED)
    {
        printf("Mapping Failed\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        ptr[i] = i + 1;
    }

    printf("Initial values of the array elements :\n");
    for (int i = 0; i < N; i++)
    {
        printf(" %d", ptr[i]);
    }
    printf("\n");

    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        //child
        for (int i = 0; i < N; i++)
        {
            ptr[i] = ptr[i] * 10;
        }
        *pos = 50;
        while (1 > 0)
        {
            printf("hello\n");
            usleep(400000);
        }
    }
    else
    {
        //parent
        //waitpid(child_pid, NULL, 0);
        while (*pos < 50)
        {
            /* code */
        }

        printf("\nParent:\n");

        printf("Updated values of the array elements :\n");
        for (int i = 0; i < N; i++)
        {
            printf(" %d", ptr[i]);
        }
        printf("pos %d\n", *pos);
        printf("\n");
        return ptr;
    }

    int err = munmap(ptr, N * sizeof(int));

    if (err != 0)
    {
        printf("UnMapping Failed\n");
        return 1;
    }
    return 0;
}
void listenToPort(

)
{
    int maxTemp = 2;
    int tmp[maxTemp];
    //int tmp[5];
    size_t pos = 0;
    int val = 9;
    // int N = 5; // Number of elements for the array

    int *tmp = mmap(NULL, maxTemp * sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);
    int *pos2 = mmap(NULL, sizeof(int),
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS,
                    0, 0);
    if (tmp == MAP_FAILED)
    {
        printf("Mapping Failed\n");
        return 1;
    }

    char *zName = "name";
    printf("start listening to port\n");
    //char *zName = "name";

    //printf("Name: %s \n", zName);
    char *s1 = "INSERTC into ";
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

            if (asprintf(&num, "%d", value) == -1)
            {
                perror("asprintf");
            }
            else
            {
                strcat(strcpy(buffer2, finalQuery), num);
                strcat(buffer2, ");");
                //printf("%s\n", buffer2);
                //sqlite3NestedParse(pParse, buffer2);

                free(num);
            }
            if (pos < 4)
            {
                printf("pos %d\n", pos);
                push(tmp, value, sizeof(tmp) / sizeof(tmp[0]), &pos);
                *pos2 = pos;
            }

            printf("hello\n");
            // sqlite3NestedParse(pParse, "INSERT into t15 values(500);");
            // sqlite3NestedParse(pParse, "SELECT * FROM t15;");
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
            printf("pos before %d\n", *pos2);
            printf("client-------\n");
            while (*pos2 < maxTemp)
            {
                //printf("pos still less than 4\n");
            }
            printf("I will return tmp\n");
            for (int i = 0; i < maxTemp; i++)
            {
                printf(" %d", tmp[i]);
            }
            printf("pos %d\n", *pos2);
            // return tmp;
        }

        else
        {
            printf("parent-------\n");
        }
    }
}

int main()
{
    // int *p;
    // int i;

    // p = fun();
    // for (i = 0; i < 4; i++)
    // {
    //     printf("*(p + %d) : %d from main\n", i, *(p + i));
    // }
    listenToPort();
}