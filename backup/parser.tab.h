/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BOOL = 258,                    /* BOOL  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    CHAR = 261,                    /* CHAR  */
    STRING = 262,                  /* STRING  */
    DATATYPE = 263,                /* DATATYPE  */
    VOID = 264,                    /* VOID  */
    LPAREN = 265,                  /* LPAREN  */
    RPAREN = 266,                  /* RPAREN  */
    LBRACE = 267,                  /* LBRACE  */
    RBRACE = 268,                  /* RBRACE  */
    LBOX = 269,                    /* LBOX  */
    RBOX = 270,                    /* RBOX  */
    SEMICOLON = 271,               /* SEMICOLON  */
    COLON = 272,                   /* COLON  */
    DOT = 273,                     /* DOT  */
    COMMA = 274,                   /* COMMA  */
    DOLLAR = 275,                  /* DOLLAR  */
    HASH = 276,                    /* HASH  */
    TILDE = 277,                   /* TILDE  */
    ARROW = 278,                   /* ARROW  */
    WITH = 279,                    /* WITH  */
    LOOP = 280,                    /* LOOP  */
    UNTIL = 281,                   /* UNTIL  */
    WHILE = 282,                   /* WHILE  */
    UPDATE = 283,                  /* UPDATE  */
    EXIT = 284,                    /* EXIT  */
    SKIP = 285,                    /* SKIP  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    RETURN = 288,                  /* RETURN  */
    ID = 289,                      /* ID  */
    ALLOC = 290,                   /* ALLOC  */
    _NULL = 291,                   /* _NULL  */
    TRUE = 292,                    /* TRUE  */
    FALSE = 293,                   /* FALSE  */
    INTLIT = 294,                  /* INTLIT  */
    FLOATLIT = 295,                /* FLOATLIT  */
    CHARLIT = 296,                 /* CHARLIT  */
    STRINGLIT = 297,               /* STRINGLIT  */
    ASSIGN = 298,                  /* ASSIGN  */
    EQUALS = 299,                  /* EQUALS  */
    NEQUALS = 300,                 /* NEQUALS  */
    LT = 301,                      /* LT  */
    GT = 302,                      /* GT  */
    LTE = 303,                     /* LTE  */
    GTE = 304,                     /* GTE  */
    PLUS = 305,                    /* PLUS  */
    MINUS = 306,                   /* MINUS  */
    MUL = 307,                     /* MUL  */
    DIV = 308,                     /* DIV  */
    MOD = 309,                     /* MOD  */
    AND = 310,                     /* AND  */
    OR = 311,                      /* OR  */
    PLUSEQUALS = 312,              /* PLUSEQUALS  */
    MINUSEQUALS = 313,             /* MINUSEQUALS  */
    MULEQUALS = 314,               /* MULEQUALS  */
    DIVEQUALS = 315,               /* DIVEQUALS  */
    MODEQUALS = 316,               /* MODEQUALS  */
    NOT = 317,                     /* NOT  */
    INCR = 318,                    /* INCR  */
    DECR = 319                     /* DECR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser.y"

    struct s1 {
        char* place;
        char* mode;
    } attributes;

#line 135 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
