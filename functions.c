//
// Created by nabiamad29 on 29/11/23.
//
#include <string.h>
#include "sys/wait.h"
#include "functions.h"

void display_msg (void)
{
    write(STDOUT_FILENO,welcome,strlen(welcome));


}

void display_prompt (void)
{
    write(STDOUT_FILENO,prompt,strlen(prompt));
}

void commande (void){
    char readFunction[512];
    read(STDIN_FILENO,readFunction,sizeof(readFunction));
    write(STDOUT_FILENO,readFunction, sizeof(readFunction));
}