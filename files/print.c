#include <stdio.h>

int push(int arr[], int value, size_t size, size_t *current) {
    if (*current < size) {
        arr[(*current)++] = value;
        return 0;
    } else {
        /* array is full */
        return -1;
    }
}
int getLength(int arr[]){
    int *p;
    int count=0;

    for(p=arr;p<&arr+1;p++)
        count++;
    return count;
}
int main(void) { 
    int temp[10] = { 1, 2, 0, 0, 5, 6, 0, 8, 0, 0 };
    int tmp[5];
    size_t pos = 0;
    int val = 9;
    

    for (size_t i = 0; i < 100; i++) {
       // if (temp[i])
            if (pos < 4){ 
                printf("%d\n", pos);
            push(tmp, val, sizeof(tmp) / sizeof(tmp[0]), &pos);
            }else
            {
                break;
            }
            
    }
    printf("%d\n", pos);

    printf("tmp:");
    for (size_t i = 0; i < pos; i++) {
        printf(" %d", tmp[i]);
    }
    printf("\n");
    return 0;
}

// #define _GNU_SOURCE
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #ifndef MAX
// #define MAX 100
// #endif

// int main(int argc, char *argv[]) {
//     const char* str1 = "hello there";
//     int n1 = 1234;

//     char *num;
//     char buffer[MAX];

//     if (asprintf(&num, "%d", n1) == -1) {
//         perror("asprintf");
//     } else {
//         strcat(strcpy(buffer,  str1), num);
//         //strcat(buffer, "! continued");
//         printf("%s\n", buffer);
//         free(num);
//     }

//     // exit(EXIT_SUCCESS);

// }