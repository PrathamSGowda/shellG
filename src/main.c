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

/*
    Command : type
    determines what category the command falls under
*/
    else if (strncmp(ch,"type ",5) == 0)
        {
            char *cmd = ch+5;
            if (strcmp(cmd,"exit") == 0 || strcmp(cmd,"echo") == 0 ||
                strcmp(cmd,"type") == 0)
                {
                printf("%s is a built-in command in shellG\n",cmd);
                }
            else
                printf("%s: command not found\n",cmd);
        }

    else
        printf("%s: command not found\n",ch);
    }

    return 0;
}
