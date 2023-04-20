%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"
    #define INC l.col += yyleng
    #define TOK(t) Token(t, yytext)
    
    void yyerror(const char*);
    extern FILE *yyin;
    extern FILE *yyout;

    enum TokenType {
        /* datatypes */
        BOOL, INT, FLOAT, CHAR, STRING, DATATYPE, VOID,

        /* punctuation */
        LPAREN, RPAREN, LBRACE, RBRACE, LBOX, RBOX, SEMICOLON, COLON, DOT, 
        COMMA, DOLLAR, HASH, TILDE, ARROW,

        /* loops */
        WITH, LOOP, UNTIL, UPDATE, EXIT, SKIP,

        /* conditional */
        IF, ELSE, 

        /* others */
        RETURN, ID, ALLOC, _NULL,

        /* literals */
        TRUE, FALSE, INTLIT, FLOATLIT, CHARLIT, STRINGLIT,
      
        /* binary operations */
        ASSIGN, EQUALS, NEQUALS, LT, GT, LTE, GTE, PLUS, MINUS, MUL, DIV, MOD, 
        AND, OR, PLUSEQUALS, MINUSEQUALS, MULEQUALS, DIVEQUALS, MODEQUALS, 

        /* unary operators */
        NOT, INCR, DECR

    };

    struct Loc {
        int col = 0, line = 0;
    } l;

    struct Token {
        TokenType type;
        char lexeme[32];
        Loc location;
        Token(TokenType type , char* lexeme) {
            this->type = type;
            strcpy(this->lexeme, lexeme);
            location = l;
        }
    };
%}

%option yylineno

%%

[\t\f]                                      {  l.col++;                       }
[\n]|[#].*\n                                {  l.line++; l.col = 0;           }


"<bool>"                                    {  INC; return TOK(BOOL);         }
"<int>"                                     {  INC; return TOK(INT);          }
"<float>"                                   {  INC; return TOK(FLOAT);        }
"<char>"                                    {  INC; return TOK(CHAR);         }
"<string>"                                  {  INC; return TOK(STRING);       }
"<datatype>"                                {  INC; return TOK(DATATYPE);     }
"<void>"                                    {  INC; return TOK(VOID);         }


"if"                                        {  INC; return TOK(IF);           }
"else"                                      {  INC; return TOK(ELSE);         }


"with"                                      {  INC; return TOK(WITH);         }
"loop"                                      {  INC; return TOK(LOOP);         }
"until"                                     {  INC; return TOK(UNTIL);        }
"while"                                     {  INC; return TOK(WHILE);        }
"update"                                    {  INC; return TOK(UPDATE);       }
"exit"                                      {  INC; return TOK(EXIT);         }
"skip"                                      {  INC; return TOK(SKIP);         }


"true"                                      {  INC; return TOK(TRUE);         }
"false"                                     {  INC; return TOK(FALSE);        }
[0-9]+                                      {  INC; return TOK(INTLIT);       }
[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?         {  INC; return TOK(FLOATLIT);     }
\"([^\\\"]|\\.)*\"                          {  INC; return TOK(STRINGLIT);    }
\'([^\\\"]|\\.)\'                           {  INC; return TOK(CHARLIT);      }


"return"                                    {  INC; return TOK(RETURN);       }
"alloc"                                     {  INC; return TOK(ALLOC);        }
"null"                                      {  INC; return TOK(_NULL);        }
[_A-Za-z][_A-Za-z0-9]*                      {  INC; return TOK(ID);           }


"("                                         {  INC; return TOK(LPAREN);       }
")"                                         {  INC; return TOK(RPAREN);       }
"{"                                         {  INC; return TOK(LBRACE);       }
"}"                                         {  INC; return TOK(RBRACE);       }
"["                                         {  INC; return TOK(LBOX);         }
"]"                                         {  INC; return TOK(RBOX);         }
";"                                         {  INC; return TOK(SEMICOLON);    }
":"                                         {  INC; return TOK(COLON);        }
"."                                         {  INC; return TOK(DOT);          }
","                                         {  INC; return TOK(COMMA);        }
"$"                                         {  INC; return TOK(DOLLAR);       }
"#"                                         {  INC; return TOK(HASH);         }
"~"                                         {  INC; return TOK(TILDE);        }
"->"                                        {  INC; return TOK(ARROW);        }


"="                                         {  INC; return TOK(ASSIGN);       }
"=="                                        {  INC; return TOK(EQUALS);       }
"!="                                        {  INC; return TOK(NEQUALS);      }
"<"                                         {  INC; return TOK(LT);           }
">"                                         {  INC; return TOK(GT);           }   
"<="                                        {  INC; return TOK(LTE);          }
">="                                        {  INC; return TOK(GTE);          }
"+"                                         {  INC; return TOK(PLUS);         }
"-"                                         {  INC; return TOK(MINUS);        }
"*"                                         {  INC; return TOK(MUL);          }
"/"                                         {  INC; return TOK(DIV);          }
"%"                                         {  INC; return TOK(MOD);          }
"+="                                        {  INC; return TOK(PLUSEQUALS);   }
"-="                                        {  INC; return TOK(MINUSEQUALS);  }
"*="                                        {  INC; return TOK(MULEQUALS);    }
"/="                                        {  INC; return TOK(DIVEQUALS);    }
"%="                                        {  INC; return TOK(MODEQUALS);    }
"&&"                                        {  INC; return TOK(AND);          }
"||"                                        {  INC; return TOK(OR);           }


"!"                                         {  INC; return TOK(NOT);          }
"++"                                        {  INC; return TOK(INCR);         }
"--"                                        {  INC; return TOK(DECR);         }

%%
