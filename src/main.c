#include <stdio.h>
#include <string.h>
#include "builtin.h"

int main()
{ 
    while(1) // keeps the shell running (REPL)
    {

    printf("$ "); // prompt for shell

    char ch[1024];
    scanf(" %[^\n]s",ch);

    if (strcmp(ch, "exit") == 0)  // exit command
            break;

    else if (strncmp(ch,"echo ",5) == 0)
    {
        run_echo(ch);
    }

    else if (strncmp(ch,"type ",5) == 0)
    {
        run_type(ch);
    }

    else
        printf("%s: command not found\n",ch);
    }

    return 0;
}
