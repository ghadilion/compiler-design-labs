%{
	#include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
    #include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char* yytext;
    extern int line;
    extern int col;

    struct indirectTriple {
        int index;
        char op[8];
        char arg1[8];
        char arg2[8];
    } instructions[128];

    struct symbol {
        char *name;
        char *type;
        char *val;
        int line;
        int col;
    } symbolTable[128];
    
    void insertNewSymbol(struct s1);
    bool isDuplicateSymbol(char *);

    int tripleNumber = 0;
    int symbolNumber = 0;
%}

%union {
    struct s1 {
        char* place;
        char* mode;
        char* val;
    } attributes;
}


%token BOOL INT FLOAT CHAR STRING DATATYPE VOID
%token LPAREN RPAREN LBRACE RBRACE LBOX RBOX SEMICOLON COLON DOT COMMA DOLLAR HASH TILDE ARROW
%token WITH LOOP UNTIL WHILE UPDATE EXIT SKIP
%token IF ELSE
%token RETURN ID ALLOC _NULL
%token TRUE FALSE INTLIT FLOATLIT CHARLIT STRINGLIT 
%token ASSIGN EQUALS NEQUALS LT GT LTE GTE PLUS MINUS MUL DIV MOD AND OR PLUSEQUALS MINUSEQUALS MULEQUALS DIVEQUALS MODEQUALS 
%token NOT INCR DECR

%type <attributes> program datatype body with until update else condition m statement assign unary init expression arithmetic relop value

%left PLUS MINUS
%left MUL DIV MOD

%right UMINUS

%start program


%%
program: program body  
        |
;

datatype: INT 
| FLOAT 
| CHAR
| VOID
| BOOL 
| STRING 
| DATATYPE
;

body: with LOOP until update LBRACE body RBRACE
| IF LPAREN condition RPAREN LBRACE body RBRACE else
| statement SEMICOLON 
| body body
;

with: WITH LPAREN statement RPAREN
|
;

until: UNTIL LPAREN condition RPAREN
| WHILE LPAREN condition RPAREN 
|
;

update: UPDATE LPAREN statement RPAREN
|
;

else: ELSE LBRACE body RBRACE
|
;

condition: ID relop ID
| expression AND m expression
| expression OR m expression
| NOT expression
| expression
;

m: 
;

statement: ID datatype init 
| ID assign expression 
| ID relop expression
| ID unary
| unary ID
;

assign: ASSIGN
| PLUSEQUALS 
| MINUSEQUALS
| MULEQUALS
| DIVEQUALS
| MODEQUALS
;

unary: INCR
| DECR
;

init: ASSIGN value 
| ASSIGN expression
|
;

expression: expression arithmetic expression
                { $$.vale
| MINUS expression
| LPAREN expression RPAREN
| value         
| 
;

arithmetic: PLUS
                { $$.val = strdup(yytext); $$.mode = "ARITH";               } 
| MINUS         { $$.val = strdup(yytext); $$.mode = "ARITH";               } 
| MUL           { $$.val = strdup(yytext); $$.mode = "ARITH";               } 
| DIV           { $$.val = strdup(yytext); $$.mode = "ARITH";               } 
| MOD           { $$.val = strdup(yytext); $$.mode = "ARITH";               } 
;

relop: LT       { $$.val = strdup(yytext); $$.mode = "RELOP";               }
| GT            { $$.val = strdup(yytext); $$.mode = "RELOP";               }
| LTE           { $$.val = strdup(yytext); $$.mode = "RELOP";               }
| GTE           { $$.val = strdup(yytext); $$.mode = "RELOP";               }
| EQUALS        { $$.val = strdup(yytext); $$.mode = "RELOP";               }
| NEQUALS       { $$.val = strdup(yytext); $$.mode = "RELOP";               }
;

value: INTLIT   { $$.val = strdup(yytext); $$.mode = "INT";                 }
| FLOATLIT      { $$.val = strdup(yytext); $$.mode = "FLOAT";               }
| CHARLIT       { $$.val = strdup(yytext); $$.mode = "CHAR";                }
| STRINGLIT     { $$.val = strdup(yytext); $$.mode = "STRING";              }
| ID            { $$.place = strdup(yytext);                                }
| TRUE          { $$.val = strdup(yytext); $$.mode = "BOOL";                }
| FALSE         { $$.val = strdup(yytext); $$.mode = "BOOL";                }
;
/*
return: RETURN value SEMICOLON 
|
;
*/


%%

int main (int argc, char *argv[]){

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	printf("Successfully analyzed syntax and found 0 errors!");
	return flag;
}

void yyerror (char const *str) {
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,str);
}

void newSymbol(struct s1 attributes) {
    if (!isDuplicateSymbol(attributes.place)) {
        symbolNumber++;
        symbolTable[symbolNumber].name = attributes.place;
        symbolTable[symbolNumber].type = attributes.mode;
        symbolTable[symbolNumber].val = attributes.val;
        symbolTable[symbolNumber].line = line;
        symbolTable[symbolNumber].col = col;
    }
}

bool isDuplicateSymbol(char *name) {
    for(int i = 0; i < symbolNumber; ++i) {
        if(strcmp(name, symbolTable[i].name) == 0) {
            printf("Error: redeclaration of symbol %s at line: %d, col: %d. First declared at line: %d, col: %d\n", symbolTable[i].name, line, col, symbolTable[i].line, symbolTable[i].col);
            return false;
        }
    }
    return true;
}

