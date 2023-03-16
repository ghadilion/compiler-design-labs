
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     INT = 259,
     FLOAT = 260,
     CHAR = 261,
     STRING = 262,
     DATATYPE = 263,
     VOID = 264,
     LPAREN = 265,
     RPAREN = 266,
     LBRACE = 267,
     RBRACE = 268,
     LBOX = 269,
     RBOX = 270,
     SEMICOLON = 271,
     COLON = 272,
     DOT = 273,
     COMMA = 274,
     DOLLAR = 275,
     HASH = 276,
     TILDE = 277,
     ARROW = 278,
     WITH = 279,
     LOOP = 280,
     UNTIL = 281,
     UPDATE = 282,
     EXIT = 283,
     SKIP = 284,
     IF = 285,
     ELSE = 286,
     RETURN = 287,
     ID = 288,
     ALLOC = 289,
     _NULL = 290,
     TRUE = 291,
     FALSE = 292,
     INTLIT = 293,
     FLOATLIT = 294,
     CHARLIT = 295,
     STRINGLIT = 296,
     ASSIGN = 297,
     EQUALS = 298,
     NEQUALS = 299,
     LT = 300,
     GT = 301,
     LTE = 302,
     GTE = 303,
     PLUS = 304,
     MINUS = 305,
     MUL = 306,
     DIV = 307,
     MOD = 308,
     AND = 309,
     OR = 310,
     PLUSEQUALS = 311,
     MINUSEQUALS = 312,
     MULEQUALS = 313,
     DIVEQUALS = 314,
     MODEQUALS = 315,
     NOT = 316,
     INCR = 317,
     DECR = 318,
     UMINUS = 319
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


