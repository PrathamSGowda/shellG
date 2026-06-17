/*********************************************/
/*                                           */
/*  builtin.c                                */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */
/*                                           */
/*  Created: 03/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include "builtin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
    searches for the path of the executable file passed 
    as an argument to the type command
*/
char *find_in_path(char *path, char *cmd)
{
    if (path == NULL || cmd == NULL)
        return NULL;
    char path_copy[1024];
    snprintf(path_copy, sizeof(path_copy), "%s", path);
    char *dir = strtok(path_copy, ";");
    static char fullpath[1024];
    while (dir != NULL)
    {
        snprintf(fullpath,sizeof(fullpath),"%s\\%s.exe",dir,cmd);
        if (access(fullpath, F_OK) == 0)
            return fullpath;
        dir = strtok(NULL, ";");
    }
    return NULL;
}

/*
    Command: type
    prints whether the command is a builtin
    function or not
*/
void run_type(Command *cmd)
{
    if(cmd->argc == 0)
    {
        printf("type: missing argument\n");
        return;
    }
    char *target = cmd->argv[0];
    if(strcmp(target, "echo") == 0 ||
        strcmp(target, "cd") == 0 ||
        strcmp(target, "pwd") == 0 ||
        strcmp(target, "type") == 0 ||
        strcmp(target, "exit") == 0)
    {
        printf("%s is a shellG builtin\n", target);
        return;
    }
    char *location = find_in_path(getenv("PATH"), target);
    if (location != NULL)
    {
        printf("%s is %s\n",target,location);
        return;
    }
    printf("%s: command not found\n", target);
}

/*
    Command: echo
    prints its arguments and adds a new line character
    at the end
*/
void run_echo(Command *cmd)
{
    for(int i = 0; i < cmd->argc; i++)
    {
        printf("%s", cmd->argv[i]);
        if (i != cmd->argc - 1)
            printf(" ");
    }
    printf("\n");
}

/*
    Command: pwd
    prints the current working directory
*/
void run_pwd(void)
{
    char pwd[1024];
    if(getcwd(pwd,sizeof(pwd)) != NULL)
    {
        printf("%s\n",pwd);
    } 
}

/*
    Command: cd
    changes directory to the path mentioned
*/
void run_cd(Command *cmd)
{
    if (cmd->argc == 0)
    {
        printf("cd: missing argument\n");
        return;
    }
    char *path = cmd->argv[0];
    if (path[0] == '~')
    {
        char *home = getenv("USERPROFILE");
        if (home != NULL)
        {
            if (chdir(home) != 0)
            {
                printf("cd: home directory not found\n");
            }
        }
        return;
    }
    if (chdir(path) != 0)
    {
        printf("cd: No such file or directory named %s\n",path);
    }
}