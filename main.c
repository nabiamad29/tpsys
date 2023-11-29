#include <stdio.h>
#include <wait.h>
#include "functions.h"

int main() {
    pid_t pid;
    int status;
    display_msg();
    while (1){
        display_prompt();
        if ((pid = fork()) == 0) {
            commande();
        }
        else
        {
            wait(&status);
        }
    }

    return 0;
}
