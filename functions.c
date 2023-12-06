//
// Created by nabiamad29 on 29/11/23.
//
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include "sys/wait.h"

struct timespec start,end;

void display_msg (void)
{
    write(STDOUT_FILENO,welcome,strlen(welcome));
}

void first_display_prompt(){
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

void display_prompt (int status) {
    u_int64_t t;
    char bufferPrompt[16]={0};
    t= (end.tv_sec-start.tv_sec)*1000+(end.tv_nsec-start.tv_nsec)/BILLION;
    sprintf(bufferPrompt,"enseash[exit:%d|%llu ms] %% ", WEXITSTATUS(status),  (long long unsigned) t);
    write(STDOUT_FILENO, bufferPrompt, strlen(bufferPrompt));
}

int commande (void){
    pid_t pid;
    int status;
    char bufferPrompt[16]={0};
    int exitValue;
    double t;
    const char *arg[SIZE_FUNCTION]={0};
    char *token;
    char readFunction[SIZE_FUNCTION] = {0};
    read(STDIN_FILENO, readFunction, SIZE_FUNCTION);
    clock_gettime(CLOCK_REALTIME,&start);
    int deletableChar = strlen(readFunction) - 1;
    int deletableChar2 = strlen(arg) - 1;
    readFunction[deletableChar] = '\0';
    arg[deletableChar2] = '\0';
    if (strcmp(readFunction, "exit") == 0) {
        write(STDOUT_FILENO, exitMessage, strlen(exitMessage));
        exit (EXIT_SUCCESS);
    }
    if ((pid = fork()) == 0) {
        execlp(readFunction,readFunction,NULL);
        exit(EXIT_FAILURE);
    }
    else {
        wait(&status);
    }
    // To stop the clock, we should do it here, not in the IF
    clock_gettime(CLOCK_REALTIME,&end);
    return status;
}

