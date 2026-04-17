#include <stdio.h>
#include <string.h>

int main()
{ 
    while(1) // keeps the shell running (REPL)
    {
/*
    printing a prompt for shell
*/
    printf("$ ");

    char ch[100];
    scanf(" %[^\n]s",ch);
/*
    implementing exit from the loop
*/
    if (strcmp(ch, "exit") == 0)
            break;
/*
    printing error messages for invalid commands
*/
    printf("%s: command not found\n", ch);
    }

    return 0;
}