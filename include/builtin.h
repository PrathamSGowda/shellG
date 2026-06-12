#ifndef BUILTIN_H
#define BUILTIN_H

#include "parser.h"

void run_echo(Command *cmd);
void run_type(Command *cmd);
void run_pwd(void);
void run_cd(Command *cmd);
char *find_in_path(char *path, char *cmd);

#endif