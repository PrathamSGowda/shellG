#include <stdio.h>
#include <string.h>
#include "builtin.h"

/*
    Command : echo
    prints its arguments and adds a new line character
    at the end
*/
void run_echo(char *ch)
{
    printf("%s\n",ch+5);
}

/*
    Command : type
    determines what category the command falls under
*/
void run_type(char *ch)
{
    char *cmd = ch + 5;
    if (strcmp(cmd,"exit") == 0 || strcmp(cmd,"echo") == 0 ||
        strcmp(cmd,"type") == 0)
        {
            printf("%s is a built-in command in shellG\n",cmd);
        }
    else
        printf("%s: command not found\n",cmd);
}