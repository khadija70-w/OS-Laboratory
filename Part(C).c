
#define _POSIX_SOURCE
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH (70)

#define MAX_NUM_ARGS (5)

void ignoreSignal(int);
void resetSignal(int);
void readCommand(char*, int);
void parseCommand(char*, char**, char**);
void cd(char*);
void goHome();
void quit(int);
void runCommand(char*, char*[]);
unsigned long getTimestamp();



