/*********************************************/
/*                                           */
/*  lexer.c                                  */
/*                                           */
/*  By: Pratham <prathampsg2007@gmail.com>   */                               
/*                                           */
/*  Created: 02/06/2026 by Pratham           */
/*                                           */
/*********************************************/

#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void add_token(Lexer *lexer, TokenType type, char *val);

int lex(Lexer *lexer)
{
    while(*lexer->cur != '\0')
    {
        while(isspace(*lexer->cur)) // skips all the whitespaces
            lexer->cur++;
        if(*lexer->cur == '\0')
            break;
        lexer->start = lexer->cur;
        while(*lexer->cur != '\0' && !isspace(*lexer->cur)) // finding end of word
            lexer->cur++;
        int len = lexer->cur - lexer->start; //size of the token
        char *word = malloc(len+1); // to include \0 as well
        strncpy(word,lexer->start,len);
        word[len] = '\0';
        add_token(lexer,TOKEN_WORD,word);        
    }
    add_token(lexer,TOKEN_END,NULL);
    return 0;
}

void add_token(Lexer *lexer, TokenType type, char *val)
{
    if(lexer->tok_count >= (int)lexer->capacity) // checks if there is enough space to store tokens
    {
        /*
            initially it allocates 8 times the size of the structure as
            the capacity and when more is needed it doubles the capacity
        */
        size_t new_capacity = lexer->capacity == 0 ? 8:lexer->capacity*2;
        lexer->tokens = realloc(lexer->tokens,new_capacity*sizeof(TokenData));
        lexer->capacity = new_capacity;
    }
    lexer->tokens[lexer->tok_count].type = type;
    lexer->tokens[lexer->tok_count].val = val;
    lexer->tok_count++;
}

void free_lexer(Lexer *lexer)
{
    for(int i=0; i<lexer->tok_count; i++)
    {
        free(lexer->tokens[i].val);
    }
    free(lexer->tokens);
}

char *token_to_string(TokenType token)
{
    switch(token)
    {
        case TOKEN_WORD:
            return "TOKEN_WORD";
        case TOKEN_END:
            return "TOKEN_END";
        default:
            return "UNKNOWN";
    }
}