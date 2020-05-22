%{
#include <stdio.h>
#include "symbolTable.h"
int yyerror(char *s);
int yylex();
%}
/* tokens */

%token  ',' ':' '.' ';' '(' ')' '[' ']' '{' '}' '=' '\n'
%token BOOLEAN CHAR CASE CLASS CONTINUE DEF DO ELSE EXIT FALSE FLOAT FOR IF INT OBJECT PRINT PRINTLN REPEAT RETURN TO TRUE TYPE VAL VAR WHILE BREAK NULL_NUM
%token ID NUM REAL STRING_LETTER
%left'-' '+' '%' '*' '/' '<' '>' LE GE EE NE AA OO
%nonassoc UMINUS '!'
%%

startSymbol: statement '\n'
			  ;
statement: expression
			;
expression: expression '+' NUM 
			 | expression '-' NUM 
			 | NUM					
			 ;
%%
extern char *yytext;
int yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
	 printf("%s\n",yytext);
	 return 0;
}

int main(int argc,char *argv[])
{
    createTable();
	 yyparse();
	 return 0;
}

