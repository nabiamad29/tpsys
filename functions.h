//
// Created by nabiamad29 on 29/11/23.
//
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#ifndef TP_SYSV2_FUNCTIONS_H
#define TP_SYSV2_FUNCTIONS_H

#endif //TP_SYSV2_FUNCTIONS_H

#define welcome "Bienvenue dans le Shell ENSEA.\n\r"
#define prompt "enseash % "
#define SIZE_FUNCTION 512
#define exitMessage "Bye bye...\n"
#define delay 0
#define MILLION 1000000L;
void display_msg(void);
void display_prompt(int);
int commande (void);
void first_display_prompt();