#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUF 1024

int main(int argc, char* args[]){
    // fail fifo try
    //   int fd;
    //   printf("came!");
    // char * myfifo = "/tmp/myfifo";
    // char* buf[MAX_BUF];

    // /* open, read, and display the message from the FIFO */
    // fd = open(myfifo, O_RDONLY);
    // read(fd, buf, MAX_BUF);
    // printf("Received: %s\n", buf);
    // close(fd);

    //Addition
    int a = atoi(args[0]);
    int b = atoi(args[1]);
    int result = a + b;
    printf("%d + %d = %d \n", a, b, result);
    return 0;
}
