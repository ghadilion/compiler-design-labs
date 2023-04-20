%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"
    #define INC col += yyleng
    void yyerror(const char*);
    extern FILE *yyin;
    extern FILE *yyout;
    int line = 1, col = 0;
    
%}

%option yylineno

%%

[ \t]                                       {  col++;                    }
[\n]|[#].*[\n]                              {  line++; col = 0;          }


"<bool>"                                    {  INC; return BOOL;         }
"<int>"                                     {  INC; return INT;          }
"<float>"                                   {  INC; return FLOAT;        }
"<char>"                                    {  INC; return CHAR;         }
"<string>"                                  {  INC; return STRING;       }
"<datatype>"                                {  INC; return DATATYPE;     }
"<void>"                                    {  INC; return VOID;         }


"if"                                        {  INC; return IF;           }
"else"                                      {  INC; return ELSE;         }


"with"                                      {  INC; return WITH;         }
"loop"                                      {  INC; return LOOP;         }
"until"                                     {  INC; return UNTIL;        }
"while"                                     {  INC; return WHILE;        }
"update"                                    {  INC; return UPDATE;       }
"exit"                                      {  INC; return EXIT;         }
"skip"                                      {  INC; return SKIP;         }


"true"                                      {  INC; return TRUE;         }
"false"                                     {  INC; return FALSE;        }
[0-9]+                                      {  INC; return INTLIT;       }
[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?         {  INC; return FLOATLIT;     }
\"([^\\\"]|\\.)*\"                          {  INC; return STRINGLIT;    }
\'([^\\\"]|\\.)\'                           {  INC; return CHARLIT;      }


"return"                                    {  INC; return RETURN;       }
"alloc"                                     {  INC; return ALLOC;        }
"null"                                      {  INC; return _NULL;        }
[_A-Za-z][_A-Za-z0-9]*                      {  INC; return ID;           }


"("                                         {  INC; return LPAREN;       }
")"                                         {  INC; return RPAREN;       }
"{"                                         {  INC; return LBRACE;       }
"}"                                         {  INC; return RBRACE;       }
"["                                         {  INC; return LBOX;         }
"]"                                         {  INC; return RBOX;         }
";"                                         {  INC; return SEMICOLON;    }
":"                                         {  INC; return COLON;        }
"."                                         {  INC; return DOT;          }
","                                         {  INC; return COMMA;        }
"$"                                         {  INC; return DOLLAR;       }
"#"                                         {  INC; return HASH;         }
"~"                                         {  INC; return TILDE;        }
"->"                                        {  INC; return ARROW;        }


"="                                         {  INC; return ASSIGN;       }
"=="                                        {  INC; return EQUALS;       }
"!="                                        {  INC; return NEQUALS;      }
"<"                                         {  INC; return LT;           }
">"                                         {  INC; return GT;           }   
"<="                                        {  INC; return LTE;          }
">="                                        {  INC; return GTE;          }
"+"                                         {  INC; return PLUS;         }
"-"                                         {  INC; return MINUS;        }
"*"                                         {  INC; return MUL;          }
"/"                                         {  INC; return DIV;          }
"%"                                         {  INC; return MOD;          }
"+="                                        {  INC; return PLUSEQUALS;   }
"-="                                        {  INC; return MINUSEQUALS;  }
"*="                                        {  INC; return MULEQUALS;    }
"/="                                        {  INC; return DIVEQUALS;    }
"%="                                        {  INC; return MODEQUALS;    }
"&&"                                        {  INC; return AND;          }
"||"                                        {  INC; return OR;           }


"!"                                         {  INC; return NOT;          }
"++"                                        {  INC; return INCR;         }
"--"                                        {  INC; return DECR;         }

%%
