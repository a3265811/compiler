%{
#include <stdio.h>
#include "symbolTable.h"
#define typeError() printf("line : %d ,warning : type doesn't compatible and implicit casting\n",linenum-1)
#define typeCheck(id) lookup(tableList,id,0)->type
#define non_declaration(t) yyerror(t);
int yyerror(char *s);
int yylex();
int linenum;
int main_check = 0;
char *temp_ID;
char *ID_name;
node *temp_node;
%}
/* tokens */
%union{
	int integer;
	char *string;
}

%token <string> COMMA COLON PERIOD SEMICOLON LEFT_PARENTHESE RIGHT_PARENTHESE LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY ASSIGN
%token <string>FOR REPEAT DO WHILE FOR_ASSIGN
%token <string>VAL VAR
%token <string> CHAR INT FLOAT STRING BOOLEAN VOID
%token <string> OBJECT DEF
%token <string> PRINT PRINTLN READ
%token <string> TRUE FALSE
%token <string> IF ELSE 
%token <string> CONTINUE BREAK EXIT TO CASE RETURN TYPE NULL_LITERAL
%token <string> CLASS
%token <string> ID 
%token <string>INT_LITERAL REAL_LITERAL STRING_LITERAL
%left  <string> OR 
%left  <string> AND 
%left  <string> '!' 
%left  <string> LT GT LE GE EQ NE 
%left  <string> '-' '+' 
%left  <string> '*' '/'
%nonassoc <string> UMINUS
%type <string> types identifier expr literals array_id read_stmt print_stmt func_invo_stmt assign_stmt func_def_remain stmt program
%%
/*
	Program begin
*/
program: OBJECT{createTable();} identifier LEFT_CURLY program_body RIGHT_CURLY {
			if (main_check == 0)
				printf("doesn't have main function\n");
			insert(tableList,$3,"Object");
		 }
		 ;

program_body: val_dec
				| program_body val_dec
				| var_dec
				| program_body var_dec
				| array_dec
				| program_body array_dec
				| func_def
				| program_body func_def
				;
/*				
	Declarations
*/
val_dec: VAL identifier ASSIGN expr{insert(tableList,$2,$4);}
		 | VAL identifier COLON types ASSIGN expr{
			 insert(tableList,$2,$4);
			 if(strcmp($4,$6))
				 typeError();
		 }
		 ;

var_dec: VAR identifier {insert(tableList,$2,"Unknown");}
	    | VAR identifier COLON types {insert(tableList,$2,$4);}
		 | VAR identifier ASSIGN expr {insert(tableList,$2,$4);}
	    | VAR identifier COLON types ASSIGN expr{
			 insert(tableList,$2,$4);
			 if(strcmp($4,$6))
				 typeError();
		 }
		 ;

array_dec: VAR identifier COLON types LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {insert(tableList,$2,$4);}
		   ;


/*
	function definition
*/
func_def: DEF identifier LEFT_PARENTHESE {createTable();} func_args RIGHT_PARENTHESE func_def_remain {
				 if(strcmp($2,"main") == 0)
					 main_check = 1;
				 temp_node = insert(tableList->pre,$2,$7);
				 printf("%s function symbol table:\n",$2);
				 dump(tableList);
				 deleteTable();
		  }
		  ;

func_def_remain: LEFT_CURLY RIGHT_CURLY {$$ = "Unknown";}
					| LEFT_CURLY  block_body RIGHT_CURLY {$$ = "Unknown";}
					| COLON types LEFT_CURLY block_body RIGHT_CURLY {$$ = $2;}
					;
func_args: func_arg_list
			| %empty
			;

func_arg_list: func_arg 
		   	 | func_arg_list func_arg
				 ;	

func_arg: identifier COLON types {insert(tableList,$1,$3);}
		  | COMMA identifier COLON types {insert(tableList,$2,$4);}
		  ;

/*
	Statements
*/
stmt: assign_stmt
	 | print_stmt
	 | return_stmt
	 | read_stmt
	 | func_invo_stmt {$$ = $1;}
	 | if_cond
	 | while_loop
	 | for_loop
    ;

assign_stmt: identifier ASSIGN expr {
				  if(typeCheck($1)==NULL){
					  non_declaration($1);
				  }
				  else{
					  if(strcmp(typeCheck($1),$3))
						  typeError();
					  strcpy($$,typeCheck($1));
				  }
			  }
			  | array_id ASSIGN expr{
				  if(typeCheck($1)==NULL){
					  non_declaration($1);
				  }
				  else{
					  if(strcmp(typeCheck($1),$3))
						  typeError();
					  strcpy($$,typeCheck($1));
				  }
			  }
			  ;


print_stmt: PRINT LEFT_PARENTHESE expr RIGHT_PARENTHESE
			 | PRINTLN LEFT_PARENTHESE expr RIGHT_PARENTHESE
			 ;

return_stmt: RETURN return_body
			  ;

return_body: expr
			  | %empty
			  ;

read_stmt: READ identifier {
				  if(typeCheck($2) == NULL){
					  non_declaration($2);
				  }
				  else{
					  strcpy($$,typeCheck($2));
				  }
			}
			;
/*
	func_invo_stmt
*/
func_invo_stmt: identifier LEFT_PARENTHESE func_invo_args RIGHT_PARENTHESE {
						 if(typeCheck($1) == NULL){
							 non_declaration($1);
						 }
						 else{
						 	 $$ = typeCheck($1);
						 }
				  } 
				  ;

func_invo_args: func_invo_arg
				  | func_invo_args COMMA func_invo_arg
				  ;

func_invo_arg: expr
				 ;

/*
	if_cond
*/
if_cond: IF LEFT_PARENTHESE expr RIGHT_PARENTHESE cond_body
		 | IF LEFT_PARENTHESE expr RIGHT_PARENTHESE cond_body ELSE cond_body
		 ;

cond_body: block
			| stmt
			;

/*
	while_loop
*/
while_loop: WHILE LEFT_PARENTHESE expr RIGHT_PARENTHESE while_body
			 ;

while_body: block
			 | stmt
			 ;

/*
	for_loop
*/
for_loop: FOR LEFT_PARENTHESE identifier FOR_ASSIGN INT_LITERAL TO INT_LITERAL RIGHT_PARENTHESE loop_body
		  ;

loop_body: block
			| stmt
			;
/*
	Bracket block
*/
block: LEFT_CURLY block_body RIGHT_CURLY
	  ;

block_body: val_dec
			 | block_body val_dec 
			 | var_dec 
			 | block_body var_dec 
			 | stmt 
			 | block_body stmt
		    ;

/*
	Expressions
*/
expr: LEFT_PARENTHESE expr RIGHT_PARENTHESE {$$ = $2;}
	 | '-' expr %prec UMINUS {$$ = $2;}
	 | expr '*' expr {
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr '/' expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 } 
	 | expr  '+' expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr '-' expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr LT expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr LE expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr EQ expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr GE expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr GT expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr NE expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | '!' expr {strcpy($$,$2);}
	 | expr AND expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | expr OR expr{
		 if(strcmp(typeCheck($1),typeCheck($3)) != 0)
			 typeError();
		 strcpy($$,typeCheck($1));
	 }
	 | literals {$$ = $1;}
	 | identifier {
		 if(typeCheck($1) == NULL){
			 non_declaration($1);
		 }
		 else{
			 $$ = $1;
		 }
	 }
	 | array_id {$$ = $1;}
	 | func_invo_stmt {$$ = $1;}
	 | print_stmt
	 | read_stmt
	 ;

/*
	Identifier
*/
identifier: ID {$$ = $1;}
			 ;

/*
	array[integer_expr]
*/
array_id: identifier LEFT_SQUARE expr RIGHT_SQUARE {
				 if(typeCheck($1) == NULL){
					 non_declaration($1);
				 }
				 else{
					 strcpy($$,typeCheck($1));
				 }
		  }
		  ;
/*
	types
*/
types: CHAR {$$ = $1;}
     | INT  {$$ = $1;}
	  | FLOAT {$$ = $1;}
	  | STRING {$$ = $1;}
	  | BOOLEAN {$$ = $1;}
	  | VOID {$$ = $1;}
	  ;
/*
	Literals
*/
literals: INT_LITERAL {$$ = $1;}
		  | REAL_LITERAL {$$ = $1;}
		  | STRING_LITERAL {$$ = $1;}
		  ;

%%
extern char *yytext;
int yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
	 printf("line:%d ,error token : %s\n",linenum,yytext);
	 return 0;
}

int main(int argc,char *argv[])
{
	 yyparse();
	 printf("dump object symbol table:\n"); 
	 dump(tableList);
	 return 0;
}

