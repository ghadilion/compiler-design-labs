%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylex();
	void yyerror();
%}

/* defining tokens ============================================*/

%token BOOL INT FLOAT CHAR STRING DATATYPE VOID
%token LPAREN RPAREN LBRACE RBRACE LBOX RBOX SEMICOLON COLON DOT COMMA DOLLAR HASH TILDE ARROW
%token WITH LOOP UNTIL UPDATE EXIT SKIP
%token IF ELSE
%token RETURN ID ALLOC _NULL
%token TRUE FALSE INTLIT FLOATLIT CHARLIT STRINGLIT 
%token ASSIGN EQUALS NEQUALS LT GT LTE GTE PLUS MINUS MUL DIV MOD AND OR PLUSEQUALS MINUSEQUALS MULEQUALS DIVEQUALS MODEQUALS 
%token NOT INCR DECR


%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'

%right UMINUS
%start program

%%
program: expr SEMICOLON           
       | program expr SEMICOLON
	   | program function
	   | program if_statement
	   | program compound_statement
	   | program return
	   | function
	   | program itr_statement
	   | itr_statement
	   | class
	   | program class
       ;

expr: comparision
	 | statement 
     ;

return : RETURN expr SEMICOLON | ;

statement : itr_statement | assignment ;

assignment : ID datatype ASSIGN expr
			| ID ASSIGN expr;
			| ID datatype
			| ID PLUSEQUALS expr
			| ID MINUSEQUALS expr
			| ID MULEQUALS expr
			| ID DIV expr
			| ID datatype ASSIGN LBOX nums RBOX
			| pointer

nums : INTLIT | FLOATLIT | nums COMMA INTLIT | nums COMMA FLOATLIT ;
if_statement : IF LPAREN expr RPAREN LBRACE program RBRACE |
				IF LPAREN expr RPAREN LBRACE program RBRACE ELSE LBRACE program RBRACE
				;

compound_statement : expr SEMICOLON 
                   | if_statement
				   ;


function : ID datatype LPAREN function_params RPAREN LBRACE program RBRACE ;

function_params : ID datatype | function_params COMMA ID datatype | ;

itr_statement : itr_with LOOP itr_loop_until itr_update itr_tail ;
itr_tail : LBRACE  program  RBRACE 
			| LBRACE RBRACE
			;

pointer : DOT ID datatype ASSIGN pointer_init | DOT ID DATATYPE ASSIGN pointer_init

pointer_init : ID | _NULL ;

itr_with : WITH LPAREN expr RPAREN | ;

itr_loop_until :  UNTIL LPAREN expr RPAREN | ;

itr_update : UPDATE LPAREN expr RPAREN | ;

datatype : BOOL | INT | FLOAT | CHAR | STRING | VOID ;

comparision: comparision comparisionop comparision 
           | unary                
           ;

unary: MINUS unary         
     | sum  
	 | ID INCR
	 | ID DECR                
     ;

sum: sum PLUS sum              
    | sum MINUS sum            
    | product                   
    ;

product: product MUL product         
       | product DIV product   
       | term                   
       ;

class : ID DATATYPE LPAREN function_params RPAREN LBRACE class_body RBRACE

class_body : 
	   | class_body function
	   | class_body assignment SEMICOLON
	   |
       ;

term : LPAREN expr RPAREN
     | INTLIT                       
     | BOOL                        
     | ID  
	 | TRUE
	 | FALSE
	 |                      
     ;
comparisionop : NEQUALS | EQUALS | LT | LTE | GT | GTE
              ;


%%

void yyerror ()
{
  fprintf(stderr, "Syntax error\n");
  exit(1);
}

int main (int argc, char *argv[]){


	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Successfully analyzed syntax and found 0 errors!");
	return flag;
}