#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256]= {'a', 'b', 'c'};

    portno = atoi(argv[2]);
    char i = 0;
    char smallLoop = 0;
    int maxSmallLoop = 3;
    int sleepTime = 500000;
    int longSleepTime = 40000000;
    int counter = 0;
    int maxLoop = 2;
    while (counter < maxLoop)
    {
       // counter++;
        i = (i+1);
        smallLoop = (i+1);
        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0)
        {
            perror("ERROR opening socket");
            exit(1);
        }

        server = gethostbyname(argv[1]);

        if (server == NULL)
        {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }

        bzero((char *)&serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);

        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("ERROR connecting");
            exit(1);
        }

        /* Now ask for a message from the user, this message
        * will be read by server
        */
      
        printf("before write \n");
        /* Send message to the server */
        write(sockfd, &i, sizeof(int)); // &nread returns the address to nread
        write(sockfd, &i, sizeof(i)); // Alternative version always using the proper type
        printf("%d\n",i);
        /* Now read server response */
        bzero(buffer, 256);
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);

        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }
        else
        {
            printf("n>0 after reading\n");
        }

        printf("%s\n", buffer);
        close(sockfd);
        if(smallLoop % maxSmallLoop == 0){
            printf(" I will sleep a long time\n");
            usleep (longSleepTime);
            counter++;
            printf(" I wake up from a long time\n");

        }else
        {
            usleep (sleepTime);
        }
         
    }
    return 0;
}