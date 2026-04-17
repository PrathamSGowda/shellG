#include <stdio.h>
#include <string.h>

int main()
{ 
    while(1) // keeps the shell running (REPL)
    {

    printf("$ "); // prompt for shell

    char ch[1024];
    scanf(" %[^\n]s",ch);

    if (strcmp(ch, "exit") == 0)  // exit command
            break;

/*
    Command : echo
    prints its arguments and adds a new line character
    at the end
*/
    else if (strncmp(ch,"echo ",5) == 0)
        printf("%s\n",ch+5);
    else
        printf("%s: command not found\n",ch);
    }

    return 0;
}
