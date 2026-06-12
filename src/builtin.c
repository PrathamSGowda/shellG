/*********************************************/
/*                                           */
/*  builtin.c                                */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */
/*                                           */
/*  Created: 03/06/2026 by Pratham           */
/*  Updated: 03/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include "builtin.h"

#include <stdio.h>

/*
    Command : echo
    prints its arguments and adds a new line character
    at the end
*/
void run_echo(Command *cmd)
{
    for (int i = 0; i < cmd->argc; i++)
    {
        printf("%s", cmd->argv[i]);
        if (i != cmd->argc - 1)
            printf(" ");
    }
    printf("\n");
}
