%{
	#include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    int yylex (void);
    void yyerror (char const *);
	
    extern FILE *yyin;
	extern FILE *yyout;
    extern int yylineno;
    extern char* yytext;
    extern int line;
    extern int col;

    struct indirectTriple {
        int index;
        char *op;
        char *arg1;
        char *arg2;
    } instructions[128];

    struct symbol {
        char *name;
        char *type;
        int line;
        int col;
    } symbolTable[128];
    
    void insertNewSymbol(char*, char*);
    int findSymbolPostion(char *);
    char* newTemp();
    void gen(char*, char*, char*);
    void displaySymbolTable();
    void displayTriples();
    int isSameType(char*, char*);
    int isUndeclared(char*); 
    int* makeList(int);
    int* makeEmptyList();
    int nextQuad(); 
    void backPatch(int *, int);
    int* merge(int*, int*);
    void threeAddressCode();    

    int tripleNumber = -1;
    int symbolNumber = -1;
%}

%union {
    struct s1 {
        char* place;
        char* mode;
        int* TRUE;
        int* FALSE;
        int quad;
        int* next;
    } attributes;
}

%token BOOL INT FLOAT CHAR STRING DATATYPE VOID
%token LPAREN RPAREN LBRACE RBRACE LBOX RBOX SEMICOLON COLON DOT COMMA DOLLAR 
%token HASH TILDE ARROW
%token WITH LOOP UNTIL WHILE UPDATE EXIT SKIP
%token IF ELSE
%token RETURN ID ALLOC _NULL
%token TRUE FALSE INTLIT FLOATLIT CHARLIT STRINGLIT 
%token ASSIGN EQUALS NEQUALS LT GT LTE GTE PLUS MINUS MUL DIV MOD AND OR 
%token PLUSEQUALS MINUSEQUALS MULEQUALS DIVEQUALS MODEQUALS 
%token NOT INCR DECR

%type <attributes> program datatype body with until update else condition m 
%type <attributes> statement unary expression relop value id n

%left PLUS MINUS
%left MUL DIV MOD

%start program


%%
program: program body  
        |
;

datatype: INT   { $$.mode = "INT";                                            }

| FLOAT         { $$.mode = "FLOAT";                                          } 
| CHAR          { $$.mode = "CHAR";                                           }
| VOID          { $$.mode = "VOID";                                           }
| BOOL          { $$.mode = "BOOL";                                           }
| STRING        { $$.mode = "STRING";                                         }
| DATATYPE      { $$.mode = "DATATYPE";                                       }
;

body: with LOOP WHILE m LPAREN condition RPAREN m LBRACE body RBRACE
                { 
                  /*backPatch($10.next, $4.quad);*/
                  backPatch($6.TRUE, $8.quad);
                  $$.next = $6.FALSE;
                  char m_quad[32];
                  snprintf(m_quad, 32, "%d", $4.quad);
                  gen("goto", "", m_quad);
                }

| IF LPAREN condition RPAREN m LBRACE body RBRACE n ELSE m LBRACE body RBRACE       
                { 
                  backPatch($3.TRUE, $5.quad);
                  backPatch($3.FALSE, $11.quad);
                  $3.next = merge($7.next, merge($9.next, $13.next));
                }

| IF LPAREN condition RPAREN m LBRACE body RBRACE 
                { 
                  backPatch($3.TRUE, $5.quad); 
                  $7.next = merge($3.FALSE, $7.next);
                }

| statement SEMICOLON 
                { $$.next = makeEmptyList();  }

| body body     { $$.next = $2.next;  }
;

n:              {   
                  $$.next = makeList(nextQuad()); 
                  gen("goto", "", "");    
                }

with: WITH LPAREN statement RPAREN
|
;

condition: id relop id 
                { 
                  $$.TRUE = makeList(nextQuad()); 
                  $$.FALSE = makeList(nextQuad()+1);
                  char idRelopId[32]; 
                  snprintf(idRelopId, 32, "%s%s%s", $1.place, $2.place, $3.place);
                  tripleNumber++; 
                  gen("if_goto", idRelopId, "");
                  tripleNumber++; 
                  gen("goto", "", "");
                }

| condition AND m condition 
                { 
                  backPatch($1.TRUE, $3.quad); 
                  $$.TRUE = $4.TRUE;
                  $$.FALSE = merge($1.FALSE, $4.FALSE);
                }
| condition OR m condition 
                { 
                  backPatch($1.FALSE, $3.quad); 
                  $$.TRUE = merge($1.TRUE, $4.TRUE);
                  $$.FALSE = $4.FALSE;
                }
| NOT condition
                { $$.TRUE = $2.FALSE; $$.FALSE = $2.TRUE;                     }

| LPAREN condition RPAREN    
                { $$.TRUE = $2.TRUE; $$.FALSE = $2.FALSE;                     }

| id            { 
                  $$.TRUE = makeList(nextQuad());
                  $$.FALSE = makeList(nextQuad()+1);
                  tripleNumber++;
                  gen("if_goto", $1.place, "");
                  tripleNumber++;
                  gen("goto", "", "");
                }
;

m:              { $$.quad = nextQuad();                                       }
;

statement: id datatype ASSIGN expression 
                { 
                  if(isSameType($2.mode, $4.mode)) {
                    $1.mode = $2.mode;
                    insertNewSymbol($1.place, $1.mode);
                    tripleNumber++;
                    gen("=", $1.place, $4.place);
                  }
                }

| id datatype
                { $1.mode = $2.mode; insertNewSymbol($1.place, $1.mode);      }

| id ASSIGN expression 
                { 
                  if(!isUndeclared($1.place) && isSameType($1.mode, $3.mode) ) {
                    tripleNumber++;
                    gen("=", $1.place, $3.place);
                  }
                }

| id unary      { if(!isUndeclared($1.place)) {
                    char* t = newTemp(); 
                    insertNewSymbol(t, $1.mode); 
                    char op[2] = {$2.place[0], '\0'};
                    gen(op, $1.place, "1");
                    tripleNumber++;
                    gen("=", $1.place, t);
                  }
                }

| unary id      { 
                  if(!isUndeclared($2.place)) {
                    char* t = newTemp(); 
                    insertNewSymbol(t, $2.mode);
                    char op[2] = {$1.place[0], '\0'};
                    gen(op, $2.place, "1");
                    tripleNumber++;
                    gen("=", $2.place, t);
                  }
                }
;

id: ID          { 
                  $$.place = strdup(yytext);
                  int symbolPosition = findSymbolPostion(yytext);
                  if(symbolPosition != -1)
                    $$.mode = symbolTable[findSymbolPostion(yytext)].type;
                  else
                    $$.mode = "";                
                }
;


unary: INCR     { $$.place = strdup(yytext); $$.mode = "UNARY";               }
| DECR          { $$.place = strdup(yytext); $$.mode = "UNARY";               }
;

expression: expression PLUS expression
                { 
                  $$.place = newTemp(); 
                  $$.mode = strdup($1.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("+", $1.place, $3.place);                          
                }

| expression: expression MINUS expression
                { 
                  $$.place = newTemp(); 
                  $$.mode = strdup($1.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("-", $1.place, $3.place);                          
                }

| expression: expression MUL expression
                { 
                  $$.place = newTemp(); 
                  $$.mode = strdup($1.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("*", $1.place, $3.place);                          
                }

| expression: expression DIV expression
                { 
                  $$.place = newTemp(); 
                  $$.mode = strdup($1.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("/", $1.place, $3.place);                          
                }

| expression: expression MOD expression
                { $$.place = newTemp(); 
                  $$.mode = strdup($1.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("%", $1.place, $3.place);                          
                }

| MINUS expression %prec MOD
                { $$.place = newTemp(); 
                  $$.mode = strdup($2.mode);
                  insertNewSymbol($$.place, $$.mode);
                  gen("-", $2.place, "");                                    
                }

| LPAREN expression RPAREN
                { $$.place = strdup($2.place); $$.mode = strdup($2.mode);     }

| value         { $$.place = strdup($1.place); $$.mode = strdup($1.mode);     }        
| 
;

relop: LT       { $$.place = strdup(yytext); $$.mode = "RELOP";               }
| GT            { $$.place = strdup(yytext); $$.mode = "RELOP";               }
| LTE           { $$.place = strdup(yytext); $$.mode = "RELOP";               }
| GTE           { $$.place = strdup(yytext); $$.mode = "RELOP";               }
| EQUALS        { $$.place = strdup(yytext); $$.mode = "RELOP";               }
| NEQUALS       { $$.place = strdup(yytext); $$.mode = "RELOP";               }
;

value: INTLIT   { $$.place = strdup(yytext); $$.mode = "INT";                 }
| FLOATLIT      { $$.place = strdup(yytext); $$.mode = "FLOAT";               }
| CHARLIT       { $$.place = strdup(yytext); $$.mode = "CHAR";                }
| STRINGLIT     { $$.place = strdup(yytext); $$.mode = "STRING";              }
| id            {   
                  $$.place = $1.place; $$.mode = $1.mode;
                  isUndeclared($$.place);
                }

| TRUE          { $$.place = strdup(yytext); $$.mode = "BOOL";                }
| FALSE         { $$.place = strdup(yytext); $$.mode = "BOOL";                }
;

%%

int main (int argc, char *argv[]){
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
    displaySymbolTable();
    displayTriples();
    threeAddressCode();
	return flag;
}

void displayTriples() {
    printf("\n\nINDIRECT TRIPLES\n\nIndex\t\tOp\t\tArg1\t\tArg2\n-----\t\t--\t"
    "\t----\t\t----\n");
    for(int i = 0; i <= tripleNumber; ++i) {
        printf("%d\t\t%s\t\t%s\t\t%s\n", i, instructions[i].op, 
        instructions[i].arg1, instructions[i].arg2);
    }
}

void displaySymbolTable() {
    printf("\n\nSYMBOL TABLE\n\nName\t\tType\t\tLine\t\tCol\n----\t\t----\t\t"
    "----\t\t---\n");
    for(int i = 0; i <= symbolNumber; ++i) {
        printf("%s\t\t%s\t\t%d\t\t%d\n", symbolTable[i].name, 
        symbolTable[i].type, symbolTable[i].line, symbolTable[i].col);
    }
}

void yyerror (char const *str) {
    fprintf(stderr,"Line: %d | Col: %d | Error: %s\n",line, col, str);
}

void insertNewSymbol(char* name, char* type) {
    int i = findSymbolPostion(name);
    if (i == -1) {
        symbolNumber++;
        symbolTable[symbolNumber].name = strdup(name);
        symbolTable[symbolNumber].type = strdup(type);
        symbolTable[symbolNumber].line = line;
        symbolTable[symbolNumber].col = col;
    }
    else  {
        char *errorMsg = malloc(128);
        snprintf(errorMsg, 128, "Redeclaration of symbol %s "
        "first declared at line: %d, col: %d\n", symbolTable[i].name,
        symbolTable[i].line, symbolTable[i].col);
        yyerror(errorMsg);
    }
}

int findSymbolPostion(char *name) {
    for(int i = 0; i <= symbolNumber; ++i) {
        if(strcmp(name, symbolTable[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

char* newTemp() {
    tripleNumber++;
    int length = snprintf( NULL, 0, "%d", tripleNumber );
    char* numBuf = malloc( length + 1 );
    snprintf( numBuf, length + 1, "%d", tripleNumber );
    char tempName[5] = "T";
    strcat(tempName, numBuf);
    return strdup(tempName);
}

void gen(char* op, char *arg1, char *arg2) {
    instructions[tripleNumber].op = strdup(op);
    instructions[tripleNumber].arg1 = strdup(arg1);
    instructions[tripleNumber].arg2 = strdup(arg2);
}

int isSameType(char* type1, char* type2) {
    if(strcmp(type1, type2) == 0)
        return 1;
    yyerror("Type mismatch during assignment\n");
    return 0;
}

int isUndeclared(char* name) {
    if(findSymbolPostion(name) == -1) {
        char *errorMsg = malloc(128);
        snprintf(errorMsg, 128, "Undeclared name %s ", name);
        yyerror(errorMsg);
        return 1;
    }
    return 0;
}

int* makeList(int quad) {
    int *quadList = calloc(32, sizeof(int));
    quadList[0] = quad;
    for(int i = 1; i < 32; ++i)
        quadList[i] = -1;
    return quadList;
}

int* makeEmptyList() {
    int *quadList = calloc(32, sizeof(int));
    for(int i = 0; i < 32; ++i)
        quadList[i] = -1;
    return quadList;
}


void backPatch(int *quadList, int quad) {
    for(int i = 0; quadList[i] != -1 && i < 32; ++i) {
        instructions[quadList[i]].arg2 = malloc(8);
        snprintf(instructions[quadList[i]].arg2, 8, "%d", quad);
    }
}

int* merge(int* quadList1, int* quadList2) {
    int i;
    for(i = 0; quadList1[i] != -1 && i < 32; ++i);
    if(i == 32)
        yyerror("quadList1 full!");
    else {
        int j;
        for(j = 0; quadList2[j] != -1 && j < 32; ++j)
            quadList1[i+j] = quadList2[j];
        if(j == 32)
            yyerror("quadList1 overflow!");
    }
    return quadList1;
}

int nextQuad() { 
    return tripleNumber + 1; 
}

void threeAddressCode() {
    printf("\n\nTHREE ADDRESS CODE\n------------------\n");
    for(int i = 0; i <= tripleNumber; ++i) {
        printf("\n%d: ", i);
        if(strcmp(instructions[i].op, "=") == 0) {
            printf("%s = %s", instructions[i].arg1, instructions[i].arg2);
        }
        else if(strcmp(instructions[i].op, "if_goto") == 0) {
            printf("if %s goto %s", instructions[i].arg1, instructions[i].arg2);
        }
        else if(strcmp(instructions[i].op, "goto") == 0) {
            printf("goto %s", instructions[i].arg2);
        }
        else
            printf("T%d = %s %s %s ", i, instructions[i].arg1, 
        instructions[i].op, instructions[i].arg2);
        printf("\n");
    }

}
