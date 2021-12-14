#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define commandSize 50 // max command length
#define charSize 750 // desteklenen karakter sayisi


int splitArgs(char * inp, char ** wordArr);
void splitTasks(char * inp, char ** wordArr);
void exeCommands(char * commands[]);
int isMultiTask(char * inp);
int commandLength(char * commandInput);
int clearAll(int i);
int* catLength = 0;


int main() {
  char* commandArray[commandSize];
  char* wordArray[commandSize];
  char* input[charSize];
  int i;

  while (1) {

    memset( & wordArray, 0, sizeof(wordArray)); // memory allocation for wordArray
    memset( & commandArray, 0, sizeof(commandArray)); // cemory allocation for commandArray
    int i = 0;

    printf("\nmyshell>>");
    scanf("%[^\n]%*c", input); // gets the command

    if (strcmp(input, "exit") == 0) { // exit when user input exit
      printf("\nProgram ended\n");
      exit(0);
      return 0;
    }

    if (isMultiTask(input) == 1) { // check if the task is multiple (does include "|" )

      splitTasks(input, commandArray);
      for (i = 0; i < 2; i++) {
        splitArgs(commandArray[i], wordArray); // seperating the parameters
        exeCommands(wordArray);
      }
    } else {
      int theLength = splitArgs(input, wordArray); // single task execution
      catLength = &theLength;
      exeCommands(wordArray);
      }

    }
    return 0;
  }

  int splitArgs(char* input, char** wordArr) {
    // seperating commands by space
    int i;
    for (i = 0; i < commandSize; i++) {
      wordArr[i] = strsep(&input, " ");

      if (wordArr[i] == NULL) {
        break;
      }
      if (strlen(wordArr[i]) == 0) {
        i--;
      }
    }
    return i;
  }

void splitTasks(char * input, char ** wordArr) {
  // multitasking seperation
  int i;
  for (i = 0; i < 2; i++) {
    wordArr[i] = strsep(&input, "|");

    if (wordArr[i] == NULL) {
      break;
    }
  }

}
int isMultiTask(char * inp) {
  // check if the command is multitasking
  int isMulti = 0;
  int i;
  int lengthOfCommand = strlen(inp);

  for (i = 0; i < lengthOfCommand; i++) {
    if (inp[i] == '|') {
      isMulti = 1;
      break;
    }

  }
  return isMulti;
}

void exeCommands(char * commandArr[]) {
// the main execution function for all commands except the exit
  char * theArgs[4];
  int i;
  theArgs[0] = commandArr[1];
  theArgs[1] = commandArr[2];
  theArgs[2] = commandArr[3];
  theArgs[3] = NULL;
  // there is no need to fork for this operation
  if (strcmp(commandArr[0], "cat") == 0) {
      printf("cat: ");
      int j;
      for(j = 1; j < *catLength; j++){
        printf("%s ",commandArr[j]);
      } 
      return 0;
    }
  int f = fork();

    if (f == 0) { // forking

    if (strcmp(commandArr[0], "clear") == 0) { // clear shell
      clearAll(i);
      printf("Yanlış Komut Girdiniz! \n");
    } else if (strcmp(commandArr[0], "ls") == 0) {
       i = execv("/bin/ls", commandArr);
       printf("Yanlış Komut Girdiniz! \n");
    }
    else if (strcmp(commandArr[0], "bash") == 0) {
       i = execv("/bin/bash", commandArr);
       printf("Yanlış Komut Girdiniz! \n");
    }  
    else if (strcmp(commandArr[0], "islem") == 0){
        i = execv(commandArr[0], theArgs);
        printf("Yanlış Komut Girdiniz! \n");
    }else if (strcmp(commandArr[0], "tekrar") == 0){
        i = execv(commandArr[0], theArgs);
        printf("Yanlış Komut Girdiniz! \n");
    }else{
        printf("Yanlış Komut Girdiniz! \n");
        exit(EXIT_FAILURE);
    }
  } else  if (f < 0) {	// fork fail case
    printf("\nFailed forking child..");
    exit(EXIT_FAILURE);
  } else {
    wait(&i); // wait child    
  }
}

int clearAll(int i) {
  // clear the shell
  i = execvp("clear", (char *const []) {
   "clear",NULL});
  return i;
}

