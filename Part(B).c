//program to mimic shell in linux 
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void){
  char *args[MAX_LINE/2 + 1]; /* command line arguments */
  int should_run = 1; /* flag to determine when to exit program */
  char user_input[MAX_LINE]; 
  int i = 0;
  
  int background = 0;//flag to update when process is background
  
  while(should_run)
  {
    printf("OSH> ");
    fflush(stdout);
    scanf ("%[^\n]%*c", user_input);//take input from user

    i = 0;
    args[i] = strtok(user_input," ");
    while (args[i] != NULL)
    {
      i++;
      args[i] = strtok(NULL, " ");
    }

    if(strcmp(args[0], "exit") == 0) // exit command 
      break;

    if(strcmp(args[i-1], "&") == 0){ /* if & is included process running in background*/ 
        printf("command run in background\n");
        args[i-1] = NULL;
        background = 1;
    } 

    pid_t pid; 
    pid = fork(); /* fork child process */
    if(pid < 0){  //if fork failed due to some reason 
        return 1;
    }
    
    if (pid == 0)
    {
        execvp(args[0],args); /* execute the command  */
        if (execvp(args[0],args) < 0) {     
           printf("ERROR: Invalid command\n");
           break;
        }
    }
    else if (!background){
        wait(NULL);
    }
  }
  return 0;
}




