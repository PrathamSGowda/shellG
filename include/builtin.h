/*********************************************/
/*                                           */
/*  builtin.h                                */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 18/04/2026 by Pratham           */
/*                                           */
#ifndef BUILTIN_H
#define BUILTIN_H

#include "parser.h"

void run_echo(Command *cmd);
void run_type(Command *cmd);
void run_pwd(void);
void run_cd(Command *cmd);
char *find_in_path(char *path, char *cmd);

#endif