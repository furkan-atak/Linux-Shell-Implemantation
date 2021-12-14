#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    // Subtraction
    int a = atoi(argv[0]);
    int b = atoi(argv[1]);
    int result = a-b;
    printf("%d - %d = %d \n",a,b,result);
    return 0;

}
