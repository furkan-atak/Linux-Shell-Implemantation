#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int isDigitParam(char* inp);

int main(int argc, char* argv[]) {

  if (isDigitParam(argv[1]) == 0 || isDigitParam(argv[2]) == 0) { // parameter type check
    printf("Yanlis Parametre girildi: \n \t Islem yapilmasi için sayi giriniz!\n");
  } else {
    int islemType;	
    char * theArgs[4];	// args declaration to call necessary program
    theArgs[0] = argv[1];
    theArgs[1] = argv[2];
    theArgs[2] = argv[3];
    theArgs[3] = NULL;

    //unsuccessfull fifo try
    //  int fd;
    // char * myfifo = "/tmp/myfifo";

    // /* create the FIFO (named pipe) */
    // mkfifo(myfifo, 0666);

    // /* write "Hi" to the FIFO */
    // fd = open(myfifo, O_WRONLY);
    // write(fd, "he", sizeof("he"));
    // close(fd);

    // /* remove the FIFO */
    // unlink(myfifo);

    int forkInt = fork();

    if (forkInt == 0) { // the arg at the 0. index works when forked
      islemType = execv(argv[0], theArgs);
    } else if (forkInt < 0) {
      exit(EXIT_FAILURE);
    } else {
      wait( & islemType); // wait for child to end its job
    }
  }
  return 0;
}

int isDigitParam(char* input) {

  int index = 0;

  while (input[index] != '\0') {
    if (isdigit(input[index++]) == 0) return 0; // checking if the input is digit or not
  }
  return 1;
}


