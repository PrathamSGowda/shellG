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
        printf("-----LEXER OUTPUT-----\n");
        for (int i = 0; i < lexer.tok_count; i++)
        {
            printf("%s",token_to_string(lexer.tokens[i].type));
            if (lexer.tokens[i].val != NULL)
                printf(" -> %s",lexer.tokens[i].val);
            printf("\n");
        }
        Parser parser = init(lexer.tokens);
        Command *cmd = parse_command(&parser);
        printf("-----PARSER OUTPUT-----\n");
        if (cmd->name != NULL)
            printf("Command: %s\n", cmd->name);
        printf("argc: %d\n", cmd->argc);
        for (int i = 0; i < cmd->argc; i++)
        {
            printf("argv[%d] = %s\n", i, cmd->argv[i]);
        }
        free_command(cmd);
        free_lexer(&lexer);
    }
    return 0;
}