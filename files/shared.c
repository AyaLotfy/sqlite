#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

// int *
void listenToPort()
{
    int maxTemp = 2;
    int tmp[maxTemp];
    int pos = 0;
    size_t lastPos = 0;
    int val = 9;
    pid_t server, client;

    server = fork();
    //server
    if (server == 0)
    {
        printf("before assign\n");
        pos = 5;
        printf("after\n");
       
    }
    else
    {
        client = fork();
        //client
        if (client == 0)
        {
            while (pos <3){
 //printf("hello\n");
            }
            printf("pos %d\n", pos);
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