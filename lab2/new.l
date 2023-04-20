%option noyywrap
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "new.tab.h"
	extern FILE *yyin;
	extern FILE *yyout;
	
	int lineno = 1; // initialize to 1
	void ret_print(char *token_type);
	void yyerror();
%}

%%

[\t\r\f]+|[#].*\r


"<bool>"				{  return BOOL; }
"<int>"					{  return INT; }
"<float>"				{  return FLOAT;}
"<char>"				{  return CHAR;}
"<string>"			{  return STRING; }
"<datatype>"		{  return DATATYPE;}
"<void>"				{  return VOID;}


"if"					{  return IF;}
"else"					{  return ELSE;}


"with"					{  return WITH;}
"loop"					{  return LOOP; }
"until"					{  return UNTIL; }
"update"				{  return UPDATE; }
"exit"					{  return EXIT; }
"skip"					{  return SKIP; }


"true"					{  return TRUE; }
"false"					{  return FALSE; }
[0-9]+					{  return INTLIT; }
[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?	{  return FLOATLIT; }
\"([^\\\"]|\\.)*\"			{  return STRINGLIT; }
\'([^\\\"]|\\.)\'			{  return CHARLIT; }


"return" 				{  return RETURN; }
"alloc"					{  return ALLOC; }
"null"					{  return _NULL; }
[_A-Za-z][_A-Za-z0-9]*			{  return ID; }


"("					{  return LPAREN; }
")"					{  return RPAREN; }
"{"					{  return LBRACE; }
"}"					{  return RBRACE; }
"["					{  return LBOX; }
"]"					{  return RBOX; }
";"					{  return SEMICOLON; }
":"					{  return COLON; }
"."					{  return DOT; }
","					{  return COMMA; }
"$"					{  return DOLLAR; }
"#"					{  return HASH; }
"~"					{  return TILDE; }
"->"					{  return ARROW; }


"="					{  return ASSIGN; }
"=="					{  return EQUALS; }
"!="					{  return NEQUALS; }
"<"					{  return LT; }
">"					{  return GT; }
"<="					{  return LTE; }
">="					{  return GTE; }
"+"					{  return PLUS; }
"-"					{  return MINUS; }
"*"					{  return MUL; }
"/"					{  return DIV; }
"%"					{  return MOD; }
"+="					{  return PLUSEQUALS; }
"-="					{  return MINUSEQUALS; }
"*="					{  return MULEQUALS; }
"/="					{  return DIVEQUALS; }
"%="					{  return MODEQUALS; }
"&&"					{  return AND; }
"||"					{  return OR; }


"!"					{  return NOT; }
"++"					{  return INCR; }
"--"					{  return DECR; }

%%
