#include<stdio.h>
#include<stdlib.h>

int isDigitParam(char* input);

int main(int argc, char * args[]) {
  int i;
  if (isDigitParam(args[1]) == 0) { // parameter type check
    printf("Yanlis Parametre girildi: \n \t Tekrar edilmesi için: \n \t tekrar [tekrar edilecek] [tekrar sayisi]\n");
  } else {
    int repeatCount = atoi(args[1]);
    for (i = 0; i < repeatCount; i++) {
      printf("%s \n", args[0]);
    }
  }
  return 0;
}

int isDigitParam(char* input) {

  int index = 0;
  int isIt = 1;
  while (input[index] != '\0') {
    if (isdigit(input[index++]) == 0) { // check if input is digit
      isIt = 0;
      break;
    } 
  }
  return isIt;
}
