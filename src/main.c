/*********************************************/
/*                                           */
/*  main.c                                   */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 17/04/2026 by Pratham           */
/*  Updated: 02/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include <stdio.h>
#include <string.h>
#include "lexer.h"

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
        for (int i = 0; i < lexer.tok_count; i++)
        {
            printf("%s",token_to_string(lexer.tokens[i].type));
            if (lexer.tokens[i].val != NULL)
                printf(" -> %s",lexer.tokens[i].val);
            printf("\n");
        }
        free_lexer(&lexer);
    }
    return 0;
}