/*********************************************/
/*                                           */
/*  parser.c                                 */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 03/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

Parser init(TokenData *tokens)
{
    Parser parser;
    parser.tokens = tokens;
    parser.current = 0;
    return parser;
}

Command *parse_command(Parser *parser)
{
    Command *cmd = malloc(sizeof(Command));
    cmd->name = NULL;
    cmd->argv = NULL;
    cmd->argc = 0;

    if(parser->tokens[0].type == TOKEN_END) // handles empty input
        return cmd; 
    cmd->name = parser->tokens[parser->current].val; // first word is the command name
    parser->current = 1;
    while(parser->tokens[parser->current].type!=TOKEN_END)
    {
        parser->current++;
    }
    cmd->argc = parser->current-1;
    if(cmd->argc>0)
    {
        cmd->argv = malloc(cmd->argc*sizeof(char *));
        for(int i=0; i<cmd->argc; i++)
        {
            cmd->argv[i] = parser->tokens[i+1].val;
        }
    }
    return cmd;
}

void free_command(Command *cmd)
{
    free(cmd->argv);
    free(cmd);
}