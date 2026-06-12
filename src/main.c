/*********************************************/
/*                                           */
/*  main.c                                   */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 17/04/2026 by Pratham           */
/*  Updated: 03/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"
#include "builtin.h"

int main()
{
    while (1)
    {
        char ch[1024];
        printf("[shellG] ");
        fgets(ch, sizeof(ch), stdin);
        if (strcmp(ch, "exit\n") == 0)
            break;
        Lexer lexer = {.start = ch,.cur = ch,.tokens = NULL,.tok_count = 0,.capacity = 0};
        lex(&lexer);
        Parser parser = init(lexer.tokens);
        Command *cmd = parse_command(&parser);
        
        if (strcmp(cmd->name, "echo") == 0)
        {
            run_echo(cmd);
        }
        else
        {
            printf("%s: not a valid command in shellG\n",cmd->name);
        }

        free_command(cmd);
        free_lexer(&lexer);
    }
    return 0;
}