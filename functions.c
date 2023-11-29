//
// Created by nabiamad29 on 29/11/23.
//
#include "sys/wait.h"
#include "functions.h"

void display_msg (void)
{
    write(1,welcome,sizeof(welcome));


}

void display_prompt (void)
{
    write(1,prompt,sizeof(prompt));


}