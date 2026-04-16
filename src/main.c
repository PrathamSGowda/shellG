#include <stdio.h>

int main()
{ 
/*
    printing a prompt for shell
*/
    printf("$ ");

/*
    printing error messages for invalid commands
*/
    char ch[100];
    scanf("%[^\n]s",ch);
    printf("%s: command not found\n", ch);

    return 0;
}