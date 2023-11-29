//
// Created by nabiamad29 on 29/11/23.
//
#include <string.h>
#include "sys/wait.h"
#include "functions.h"
#include <unistd.h>
void display_msg (void)
{
    write(STDOUT_FILENO,welcome,strlen(welcome));


}

void display_prompt (void)
{
    write(STDOUT_FILENO,prompt,strlen(prompt));
}

int commande (void){
    pid_t pid;
    int status;
    int exitValue;
    char readFunction[SIZE_FUNCTION] = {0};
    read(STDIN_FILENO, readFunction, SIZE_FUNCTION);
    int deletableChar = strlen(readFunction) - 1;
    readFunction[deletableChar] = '\0';
    if (strcmp(readFunction, "exit") == 0) {
        write(STDOUT_FILENO, exitMessage, strlen(exitMessage));
        exit (EXIT_SUCCESS);
    }
    if ((pid = fork()) == 0) {
        execlp(readFunction,readFunction,(char) NULL);
    }
        else {
            wait(&status);
        }
    }

