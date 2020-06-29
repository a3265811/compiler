%{
#include <stdio.h>
#include "symbolTable.h"
#define typeError() printf("line : %d ,warning : type doesn't compatible and implicit casting\n",linenum-1)
#define typeCheck(id) lookup(tableList,id,0)->type
#define non_declaration(t) yyerror(t);
int yyerror(char *s);
int yylex();
char* type_handlier();
int type2int(char*);
int linenum;
int main_check = 0;
int def_func_args[256]={0};
int invo_func_args[256]={0};
int count = 0;
node *temp_node;
%}
/* -----union type----- */
%union{
	int integer;
	char *string;
}
/* -----tokens----- */
%token <string> COMMA COLON PERIOD SEMICOLON LEFT_PARENTHESE RIGHT_PARENTHESE LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY ASSIGN
%token <string> FOR REPEAT DO WHILE FOR_ASSIGN
%token <string> VAL VAR
%token <string> CHAR INT FLOAT STRING BOOLEAN VOID
%token <string> OBJECT DEF
%token <string> PRINT PRINTLN READ
%token <string> TRUE FALSE
%token <string> IF ELSE 
%token <string> CONTINUE BREAK EXIT TO CASE RETURN TYPE NULL_LITERAL
%token <string> CLASS
%token <string> ID 
%token <string> INT_LITERAL REAL_LITERAL STRING_LITERAL
%left  <string> OR 
%left  <string> AND 
%left  <string> '!' 
%left  <string> LT GT LE GE EQ NE 
%left  <string> '-' '+' 
%left  <string> '*' '/'
%nonassoc <string> UMINUS
%type <string> types literals 
%type <string> identifier array_id 
%type <string> stmt read_stmt print_stmt func_invo_stmt assign_stmt return_stmt if_cond while_loop for_loop
%type <string> func_def_remain 
%type <string> program 
%type <string> val_dec var_dec array_dec
%type <string> expr
%%
/*
	Program begin
*/
program: OBJECT{createTable();} identifier LEFT_CURLY program_body RIGHT_CURLY {
			if (main_check == 0)
				printf("doesn't have main function\n");
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
				| stmt
				| program_body stmt
				;
/*				
	Declarations
*/
val_dec: VAL identifier ASSIGN expr{
			 insert(tableList,$2,$4);
			 $$ = $4;
		 }
		 | VAL identifier COLON types ASSIGN expr{
			 insert(tableList,$2,$4);
			 if(strcmp($4,$6))
				 typeError();
			 $$ = $4;
		 }
		 ;

var_dec: VAR identifier {
			 insert(tableList,$2,"Unknown");
			 $$ = "Unknown";
		 }
	    | VAR identifier COLON types {
			 insert(tableList,$2,$4);
			 $$ = $4;
		 }
		 | VAR identifier ASSIGN expr {
			 insert(tableList,$2,$4);
			 $$ = $4;
		 }
	    | VAR identifier COLON types ASSIGN expr{
			 insert(tableList,$2,$4);
			 if(strcmp($4,$6))
				 typeError();
			 $$ = $4;
		 }
		 ;

array_dec: VAR identifier COLON types LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {
			 insert(tableList,$2,$4);
			 $$ = $4;
			}
		   ;


/*
	function definition
*/
func_def: DEF identifier LEFT_PARENTHESE {createTable();} func_args RIGHT_PARENTHESE func_def_remain {
				 if(strcmp($2,"main") == 0)
					 main_check = 1;
				 temp_node = insert(tableList->pre,$2,$7);
				 for(int i = 0; i < count; i++){
					 temp_node -> args[i] = def_func_args[i];
					 def_func_args[i] = 0;
				 }
				 count = 0;
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
func_arg: identifier COLON types {
				 								insert(tableList,$1,$3);
												def_func_args[count] = type2int($3);
												count = count + 1;
		  }
		  | COMMA identifier COLON types {
			  											insert(tableList,$2,$4);
														def_func_args[count] = type2int($4);
														count = count + 1;
		  }
		  ;

/*
	Statements
*/
stmt: assign_stmt
	 | print_stmt
	 | return_stmt {$$ = $1;}
	 | read_stmt {$$ = $1;}
	 | func_invo_stmt {$$ = $1;}
	 | if_cond {$$ = $1;}
	 | while_loop {$$ = $1;}
	 | for_loop {$$ = $1;}
    ;

assign_stmt: identifier ASSIGN expr {
				  if(lookup(tableList,$1,0)==NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  $$ = type_handlier($1,$3);
				  }
			  }
			  | array_id ASSIGN expr{
				  printf("123");
				  if(lookup(tableList,$1,0)==NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  $$ = type_handlier($1,$3);
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
				  if(lookup(tableList,$2,0) == NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  $$ = typeCheck($2);
				  }
			}
			| READ array_id{
				  if(lookup(tableList,$2,0) == NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  $$ = typeCheck($2);
				  }
			}
			;
/*
	func_invo_stmt
*/
func_invo_stmt: identifier LEFT_PARENTHESE func_invo_args RIGHT_PARENTHESE {
						 temp_node = lookup(tableList,$1,0);
						 for(int i = 0 ; i < count ; i++){
							 if(temp_node->args[i] != invo_func_args[i])
								 yyerror("function invocation arguments can't match function formal parameters");
							 invo_func_args[i] = 0;
						 }
						 count = 0;
						 if(temp_node == NULL){
			 		 		 non_declaration("identifier is undeclared");
						 }
						 $$ = typeCheck($1);
				  } 
				  ;

func_invo_args: func_invo_arg
				  | func_invo_args COMMA func_invo_arg
				  ;

func_invo_arg: expr {
						if(lookup(tableList,$1,0)!=NULL){
							invo_func_args[count]=type2int(typeCheck($1));
							count = count + 1;
						}
				 }
				 ;

/*
	if_cond
*/
if_cond: IF LEFT_PARENTHESE expr RIGHT_PARENTHESE cond_body{
				//printf("dump IF block symbol table\n");
				//dump(tableList);
				//deleteTable();
		 }
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
			 | array_dec
			 | block_body array_dec 
			 | stmt 
			 | block_body stmt
		    ;

/*
	Expressions
*/
expr: LEFT_PARENTHESE expr RIGHT_PARENTHESE {$$ = $2;}
	 | '-' expr %prec UMINUS {$$ = $2;}
	 | expr '*' expr { $$ = type_handlier($1,$3);}
	 | expr '/' expr{ $$ = type_handlier($1,$3);}
	 | expr '+' expr{ $$ = type_handlier($1,$3);}
	 | expr '-' expr{ $$ = type_handlier($1,$3);}
	 | expr LT expr{ $$ = type_handlier($1,$3);}
	 | expr LE expr{ $$ = type_handlier($1,$3);}
	 | expr EQ expr{ $$ = type_handlier($1,$3);}
	 | expr GE expr{ $$ = type_handlier($1,$3);}
	 | expr GT expr{ $$ = type_handlier($1,$3);}
	 | expr NE expr{ $$ = type_handlier($1,$3);}
	 | '!' expr {strcpy($$,$2);}
	 | expr AND expr{ $$ = type_handlier($1,$3);}
	 | expr OR expr{ $$ = type_handlier($1,$3);}
	 | literals {$$ = $1;}
	 | identifier {
		 if(lookup(tableList,$1,0) == NULL){
			 non_declaration("identifier is undeclared");
		 }
		 else{
			 $$ = $1;
		 }
	 }
	 | array_id {
		 if(lookup(tableList,$1,0) == NULL){
			 non_declaration("identifier is undeclared");
		 }
		 else{
		 	 $$ = $1;
		 }
	 }
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
array_id: identifier LEFT_SQUARE expr RIGHT_SQUARE {$$ = $1;}
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
    fprintf(stderr, "line:%d,%s\n",linenum-1, s);
	 return 0;
}

/*
	char 1
	boolean 2
	int 3
	float 4
	string 5
	this function is for type string to int
*/
int type2int(char* type){
	if(strcmp(type,"char") == 0)
		return 1;
	else if(strcmp(type,"boolean") == 0)
		return 2;
	else if(strcmp(type,"int") == 0)
		return 3;
	else if(strcmp(type,"float") == 0)
		return 4;
	else if(strcmp(type,"string") == 0)
		return 5;
	else
		return 0;
}

/*
	this function is for check two parameter wether is identifier
*/
char* type_handlier(char* a,char* b){
	char* result;
	if((lookup(tableList,a,0)!=NULL) && (lookup(tableList,b,0)!= NULL)){
		if(strcmp(typeCheck(a),typeCheck(b)) != 0)
			typeError();
		result = malloc(sizeof(char)*(strlen(a)+1));
		strcpy(result,a);	
	}
	else if((lookup(tableList,a,0)!=NULL) && (lookup(tableList,b,0)== NULL)){
		if(strcmp(typeCheck(a),b) != 0)
			typeError();
		result = malloc(sizeof(char)*(strlen(a)+1));
		strcpy(result,a);
	}
	else if((lookup(tableList,a,0)==NULL) && (lookup(tableList,b,0)!= NULL)){
		if(strcmp(a,typeCheck(b)) != 0)
			typeError();
		result = malloc(sizeof(char)*(strlen(b)+1));
		strcpy(result,b);
	}
	else{
		if(strcmp(a,b) != 0)
			typeError();
		result = malloc(sizeof(char)*(strlen(a)+1));
		strcpy(result,a);
	}
	return result;
}

int main(int argc,char *argv[])
{
	 yyparse();
	 printf("object symbol table:\n"); 
	 dump(tableList);
	 return 0;
}

