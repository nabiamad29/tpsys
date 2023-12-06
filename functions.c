//
// Created by nabiamad29 on 29/11/23.
//
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"
#include "sys/wait.h"

struct timespec start,end;

void display_msg (void){
    write(STDOUT_FILENO,welcome,strlen(welcome));
}

void first_display_prompt(){
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

void display_prompt (int status) {
    u_int64_t t;
    char bufferPrompt[16]={0};
    char bufferPrompt2[16]={0};
    if(WIFEXITED(status))
    {t= (end.tv_sec-start.tv_sec)*1000+(end.tv_nsec-start.tv_nsec)/MILLION;
    sprintf(bufferPrompt,"enseash[exit:%d|%llu ms] %% ", WEXITSTATUS(status),  (long long unsigned) t);
    write(STDOUT_FILENO, bufferPrompt, strlen(bufferPrompt));}

    else if(WIFSIGNALED(status))
    {
        t= (end.tv_sec-start.tv_sec)*1000+(end.tv_nsec-start.tv_nsec)/MILLION;
        sprintf(bufferPrompt2,"enseash[sign:%d|%llu ms] %% ", WTERMSIG(status),  (long long unsigned) t);
        write(STDOUT_FILENO, bufferPrompt2, strlen(bufferPrompt2));
    }
}

int commande (void){
    pid_t pid;
    int status;
    char bufferPrompt[16]={0};
    int exitValue;
    double t;
    char *token;
    char readFunction[SIZE_FUNCTION] = {0};
    //char function[SIZE_FUNCTION] = {0};
    char* args [10]={0};
    int m = 0;
    /*int i=0;
    int j=0;
    int k=0;*/
    read(STDIN_FILENO, readFunction, SIZE_FUNCTION);
    clock_gettime(CLOCK_REALTIME,&start);
    /*while (readFunction[i] != "\n"){
        if ((strcmp(readFunction[i],"-") != 0) && (j==0)){
            function[i] = readFunction[i];
            i++;
        }
        else if ((strcmp(readFunction[i],"-") != 0) && (j!=0)){
            args [j] [k] = readFunction[i];
            k++;
        }
        else if (strcmp(readFunction[i],"-") == 0 ) {
            j++;
            k=0;
            args [j] [k] = readFunction[i];
        }
        else{printf("erreur");}
    }*/
    int deletableChar = strlen(readFunction) - 1;
    readFunction[deletableChar] = '\0';
    args[m] = strtok(readFunction," ");
    while(args[m] != NULL){
        m++;
        args[m] = strtok (NULL," ");
    }
    if (strcmp(readFunction, "exit") == 0) {
        write(STDOUT_FILENO, exitMessage, strlen(exitMessage));
        exit (EXIT_SUCCESS);
    }

    if ((pid = fork()) == 0) {
        /*for (int n = 0; n < 10; ++n) {
            if(strcmp(args[n],">")==0){
                char writeDirectory = args[n+1];
                args[n] = NULL;
                args[n+1] = NULL;
                execlp(writeDirectory,args);
            }
            else if(strcmp(args[n],"<")==0){
                char readDirectory = args[n+1];
                args[n] = NULL;
                args[n+1] = NULL;
                execlp(readDirectory,args);
            }
            else {

            }
        }*/
        execvp(args[0],args);
        exit(EXIT_FAILURE);
    }
    else {
        wait(&status);
    }
    clock_gettime(CLOCK_REALTIME,&end); // To stop the clock, we should do it here, not in the IF ! Because it will kill the child only !
    return status;
}

