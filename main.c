#include <stdio.h>
#include <wait.h>
#include "functions.h"

int main() {
    display_msg();
    first_display_prompt();
    while (1){
        display_prompt(commande());
    }
}
