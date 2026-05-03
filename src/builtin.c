#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
    searches for the path of the executable file passed 
    as an argument to the type command
*/
char *find_in_path(char *path, char *cmd)
{
    if (path == NULL || cmd == NULL)
        return NULL;
    char path_copy[1026];
    strncpy(path_copy, path, sizeof(path_copy));
    char *dir = strtok(path_copy, ";");
    while (dir != NULL)
    {
        static char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s\\%s.exe", dir, cmd);
        if (access(fullpath, X_OK) == 0)
        {
            return fullpath;
        }
        dir = strtok(NULL, ";");
    }
    return NULL;
}

/*
    Command : type
    determines what category the command falls under
*/
void run_type(char *ch)
{
    char *cmd = ch + 5;

    // built-in function check
    if (strcmp(cmd,"exit") == 0 || strcmp(cmd,"echo") == 0 ||
        strcmp(cmd,"type") == 0)
        {
            printf("%s is a built-in command in shellG\n",cmd);
            return;
        }

    // executable check
    char *path = getenv("PATH");
    char *location;
    if((location = find_in_path(path,cmd)) != NULL)
    {
        printf("%s is in %s\n",cmd,location);
        return;
    }
    
    printf("%s: command not found\n",cmd);
}

/*
    Command : pwd
    prints the working directory
*/
void run_pwd()
{
    char wd[1024];
    if(getcwd(wd,sizeof(wd)) != NULL)
    {
        printf("%s\n",wd);
    }
}

/*
    Command : cd
    this command can be used to change directory
*/
void run_cd(char *cmd)
{
    char *path = cmd + 3;
    // absolute path check
    if ((path[0] >= 'A' && path[0] <= 'Z' && path[1] == ':') || path[0] == '\\')
    {
        if (chdir(path) != 0)
        {
            printf("cd: %s: No such file or directory\n", path);
            return;
        }
    }
    // relative path checks
    else if (path[0] == '.')
    {
        if (chdir(path) != 0)
        {
            printf("cd: %s: No such file or directory\n", path);
            return;
        }
    }
    else if (path[0] == '.' && path[1] == '.')
    {
        if (chdir(path) != 0)
        {
            printf("cd: %s: No such file or directory\n", path);
            return;
        }
    }
    // home directory check
    else if (path[0] == '~')
    {
        if (chdir(getenv("USERPROFILE")) != 0)
        {
            printf("cd: %s: Home directory not found\n", path);
            return;
        }
    }
}     
