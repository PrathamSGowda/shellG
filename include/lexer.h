/*********************************************/
/*                                           */
/*  lexer.h                                  */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 02/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#ifndef LEXER_H
#define LEXER_H
#include <stddef.h>

typedef enum TokenType
{
    TOKEN_WORD,
    TOKEN_END,
}TokenType;

typedef struct TokenData
{
    TokenType type;
    char *val;
}TokenData;

typedef struct Lexer
{
    char *start;
    char *cur;
    TokenData *tokens;
    int tok_count;
    size_t capacity;
}Lexer;

int lex(Lexer *lexer);
void free_lexer(Lexer *lexer);
char *token_to_string(TokenType token);

#endif