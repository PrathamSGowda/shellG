/*********************************************/
/*                                           */
/*  parser.h                                 */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 03/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct Parser
{
    TokenData *tokens;
    int current;
}Parser;

typedef struct Command
{
    char *name;
    char **argv;
    int argc;
}Command;

Parser init(TokenData *tokens);
Command *parse_command(Parser *parser);
void free_command(Command *cmd);

#endif