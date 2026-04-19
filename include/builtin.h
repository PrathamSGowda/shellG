#define BUILTIN_H

void run_echo(char *);
void run_type(char *);
char *find_in_path(char *path, char *cmd);
void run_pwd();
void run_cd(char *);