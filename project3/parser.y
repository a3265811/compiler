%{
#include "symbolTable.h"
#define typeError() printf("line : %d ,warning : type doesn't compatible and implicit casting\n",linenum-1) //id type does not compatible
#define idError() printf("line : %d ,error :identifier is undeclared\n",linenum-1) //id does not be define
#define searchID(id) lookup(tableList,id,0) //deep search
#define typeCheck(a,b) a == b ? : typeError() //type checking
int yyerror(char *s);
void compare(char *s);
int yylex();
int linenum;
int main_check = 0;
int def_func_args[256]={0};
int invo_func_args[256]={0};
int count = 0;	//counting function parameters
int now_func_type; // now def function type
int else_if_check = 0; //handling else if problem
int pos = 0; //check wether is in global(0) region or local(1) region
int value = -1;	//store integer and boolean value
int flowCount = 0;	//label flow count
int labelCheck = 0;	//check wether label is output, preventing empty label
int is_val_assign = 0; //check wether is val assign
int is_main = 0;	//check function definition name wether is main
int return_check = 0;	//check wether return is output
char* value_str;	//store string value
char* className;	//store object name
char* now_func_id;	//store now definition function id name
node *temp_node;
FILE* fout = NULL;
%}
/* -----union type----- */
%union{
	int integer;
	char *string;
}
/* -----tokens----- */
%token <integer> COMMA COLON PERIOD SEMICOLON LEFT_PARENTHESE RIGHT_PARENTHESE LEFT_SQUARE RIGHT_SQUARE LEFT_CURLY RIGHT_CURLY ASSIGN
%token <integer> FOR REPEAT DO WHILE FOR_ASSIGN
%token <integer> VAL VAR
%token <integer> CHAR INT FLOAT STRING BOOLEAN VOID
%token <integer> OBJECT DEF
%token <integer> PRINT PRINTLN READ
%token <integer> TRUE FALSE
%token <integer> IF ELSE 
%token <integer> CONTINUE BREAK EXIT TO CASE RETURN TYPE NULL_LITERAL
%token <integer> CLASS
%token <string> ID 
%token <integer> INT_LITERAL REAL_LITERAL STRING_LITERAL
%left  <integer> OR 
%left  <integer> AND 
%left  <integer> '!' 
%left  <integer> LT GT LE GE EQ NE 
%left  <integer> '-' '+' 
%left  <integer> '*' '/'
%nonassoc <integer> UMINUS
%type <integer> types literals 
%type <string> identifier array_id 
%type <integer> stmt read_stmt print_stmt func_invo_stmt assign_stmt return_stmt if_cond while_loop for_loop
%type <integer> func_def_remain 
%type <integer> program 
%type <integer> val_dec var_dec array_dec
%type <integer> expr
%%
/*
	Program begin
*/
program: OBJECT {createTable();} identifier {
			fprintf(fout,"class %s \n{\n",$3);
			className = malloc(sizeof(char)*strlen($3)+1);
			strcpy(className,$3);
		 } LEFT_CURLY program_body RIGHT_CURLY {
			if (main_check == 0)
				printf("doesn't have main function\n");
			fprintf(fout,"}");
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
val_dec: VAL identifier ASSIGN {is_val_assign = 1;} expr{
			 if($5 == 5)
				 insert(tableList,$2,$5,-1,-1,value_str);
			 else
				 insert(tableList,$2,$5,-1,value,"");
			 value = -1;
			 value_str = NULL;
			 is_val_assign = 0;
		 }
		 | VAL identifier COLON types ASSIGN {is_val_assign = 1;} expr{
			 if($4 == 5)
				 insert(tableList,$2,$4,-1,-1,value_str);
			 else
				 insert(tableList,$2,$4,-1,value,"");
			 value = -1;
			 value_str = NULL;
			 if($4 != $7)
				 typeError();
			 is_val_assign = 0;
		 }
		 ;

var_dec: VAR identifier {
			 if(pos == 0){
				 fprintf(fout,"field static int %s\n",$2);
			 	 insert(objectTable,$2,3,-2,-1,"");
			 }
			 else{
			 	 insert(tableList,$2,3,tableList->tableIndex,-1,"");
				 tableList->tableIndex++;
			 }
		 }
	    | VAR identifier COLON types {
			 if(pos == 0){
				 fprintf(fout,"field static %s %s\n",int2type($4),$2);
			 	 insert(objectTable,$2,$4,-2,-1,"");
			 }
			 else{
			 	 insert(tableList,$2,$4,tableList->tableIndex,-1,"");
				 tableList->tableIndex++;
			 }
		 }
		 | VAR identifier ASSIGN expr {
			 if(pos == 0){
				 fprintf(fout,"field static %s %s\n",int2type($4),$2);
				 fprintf(fout,"putstatic %s\n",$2);
			 	 insert(objectTable,$2,$4,-2,-1,"");
			 }
			 else{
			 	 insert(tableList,$2,$4,tableList->tableIndex,-1,"");
				 fprintf(fout,"istore %d\n",tableList->tableIndex);
				 tableList->tableIndex++;
			 }
		 }
	    | VAR identifier COLON types ASSIGN expr{
			 if(pos == 0){
				 fprintf(fout,"field static %s %s\n",int2type($4),$2);
				 fprintf(fout,"putstatic %s %s.%s\n",int2type($4),className,$2);
			 	 insert(objectTable,$2,$4,-2,-1,"");
			 }
			 else{
			 	 insert(tableList,$2,$4,tableList->tableIndex,-1,"");
				 fprintf(fout,"istore %d\n",tableList->tableIndex);
				 tableList->tableIndex++;
			 }
			 if($4 != $6)
				 typeError();
		 }
		 ;

array_dec: VAR identifier COLON types LEFT_SQUARE INT_LITERAL RIGHT_SQUARE {
				  insert(tableList,$2,$4,-1,-1,"");
			}
		   ;


/*
	function definition
*/
func_def: DEF identifier {
				 now_func_id = malloc(sizeof(char)*strlen($2)+1);
				 strcpy(now_func_id,$2);
				 if(strcmp($2,"main") == 0)
					 is_main = 1;
		  } LEFT_PARENTHESE {
				 createTable(); 
				 pos = 1;
		  } func_args RIGHT_PARENTHESE func_def_remain {
				 if(strcmp($2,"main") == 0)
					 main_check = 1;
				 temp_node = insert(objectTable,$2,now_func_type,-3,-1,"");
				 for(int i = 0; i < count; i++){
					 temp_node -> args[i] = def_func_args[i];
					 def_func_args[i] = 0;
				 }
				 count = 0;
				 printf("%s function symbol table:\n",$2);
				 dump(tableList);
				 deleteTable();
				 pos = 0;
				 is_main = 0;
		  }
		  ;

func_args: func_arg_list
			| %empty
			;

func_arg_list: func_arg 
		   	 | func_arg_list func_arg
				 ;	
func_arg: identifier COLON types {
				 								insert(tableList,$1,$3,tableList->tableIndex,-1,"");
												tableList->tableIndex++;
												def_func_args[count] = $3;
												count = count + 1;
		  }
		  | COMMA identifier COLON types {
			  											insert(tableList,$2,$4,tableList->tableIndex,-1,"");
														tableList->tableIndex++;
														def_func_args[count] = $4;
														count = count + 1;
		  }
		  ;
func_def_remain: def_func_asm LEFT_CURLY RIGHT_CURLY {
						  if(return_check == 0)
							  fprintf(fout,"return\n");
						  return_check = 0;
						  fprintf(fout,"}\n");
					}
					| def_func_asm LEFT_CURLY  block_body RIGHT_CURLY {
						  if(return_check == 0)
							  fprintf(fout,"return\n");
						  return_check = 0;
						  fprintf(fout,"}\n");
					}
					;

def_func_asm: %empty{
						  now_func_type = 3;
						  if(is_main == 0){
						  	  fprintf(fout,"method public static int %s(",now_func_id);
							  for(int i = 0 ; i < count ; i++){
								  if(i == 0)
									  fprintf(fout,"%s",int2type(def_func_args[i]));
							  	else
									  fprintf(fout,", %s",int2type(def_func_args[i]));
							  }
						  }
						  else if(is_main == 1){
						  	  fprintf(fout,"method public static void %s(java.lang.String[]",now_func_id);
						  }
						  fprintf(fout,")\n");
						  fprintf(fout,"max_stack 15\n");
						  fprintf(fout,"max_locals 15\n");
						  fprintf(fout,"{\n");
				
				}
				| COLON types{
						  now_func_type = $2;
						  if(is_main == 0){
							  fprintf(fout,"method public static %s %s(",int2type($2),now_func_id);
							  for(int i = 0 ; i < count ; i++){
								  if(i == 0)
									  fprintf(fout,"%s",int2type(def_func_args[i]));
							  	  else
								  	  fprintf(fout,", %s",int2type(def_func_args[i]));
							  }
						  }
						  else if(is_main == 1){
						  	  fprintf(fout,"method public static void %s(java.lang.String[]",now_func_id);
						  }
						  fprintf(fout,")\n");
						  fprintf(fout,"max_stack 15\n");
						  fprintf(fout,"max_locals 15\n");
						  fprintf(fout,"{\n");
				}
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
				  temp_node = searchID($1);
				  if(temp_node == NULL){
                 idError();
                 $$ = 0;
              }
				  else{
					  typeCheck(temp_node->type,$3);
					  if(temp_node->index == -2)
						  fprintf(fout,"putstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
					  else if(temp_node->index >= 0)
						  fprintf(fout,"istore %d\n",temp_node->index);
				  }
			  }
			  | array_id ASSIGN expr{
				  if(searchID($1) == NULL){                                         
                 idError();
                 $$ = 0;
              }
				  else{
	              typeCheck(searchID($1)->type,$3);
				  }
			  }
			  ;


print_stmt: PRINT LEFT_PARENTHESE {fprintf(fout,"getstatic java.io.PrintStream java.lang.System.out\n");} expr RIGHT_PARENTHESE{
					if($4 == 5){
						fprintf(fout,"invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
					}
					else if($4 == 2){
						fprintf(fout,"invokevirtual void java.io.PrintStream.print(boolean)\n");
					}
					else if($4 == 3){
						fprintf(fout,"invokevirtual void java.io.PrintStream.print(int)\n");
					}
			 }
			 | PRINTLN LEFT_PARENTHESE {fprintf(fout,"getstatic java.io.PrintStream java.lang.System.out\n");} expr RIGHT_PARENTHESE{
					if($4 == 5){
						fprintf(fout,"invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
					}
					else if($4 == 2){
						fprintf(fout,"invokevirtual void java.io.PrintStream.println(boolean)\n");
					}
					else if($4 == 3){
						fprintf(fout,"invokevirtual void java.io.PrintStream.println(int)\n");
					}
			 }
			 ;

return_stmt: RETURN return_body
			  ;

return_body: expr {
					 if($1 != now_func_type)
						 printf("line : %d ,error :return argument doesn't match function type\n",linenum-1);
					 fprintf(fout,"ireturn\n");
					 return_check = 1;
			  }
			  | %empty{
				    fprintf(fout,"return\n");
					 return_check = 1;
			  }
			  ;

read_stmt: READ identifier {
				  if(searchID($2) == NULL)
					  idError();
				  else
					  $$ = searchID($2)->type;
			}
			| READ array_id{
				  if(searchID($2) == NULL)
					  idError();
				  else
					  $$ = searchID($2)->type;
			}
			;

/*
	func_invo_stmt
*/
func_invo_stmt: identifier LEFT_PARENTHESE func_invo_args RIGHT_PARENTHESE {
						 temp_node = searchID($1);
						 if(temp_node == NULL){
							 idError();
							 $$ = 0;
						 }
						 else{
						 	fprintf(fout,"invokestatic %s %s.%s(",int2type(temp_node->type),className,$1);
						 	for(int i = 0 ; i < count ; i++){
								 if(temp_node->args[i] != invo_func_args[i])
									 printf("function invocation arguments can't match function formal parameters\n");
								 if(i == 0)
									 fprintf(fout,"%s",int2type(temp_node->args[i]));
								 else
									 fprintf(fout,", %s",int2type(temp_node->args[i]));
							 	 invo_func_args[i] = 0;
							 }
						 	count = 0;
							fprintf(fout,")\n");
						 	$$ = temp_node->type;
						 }
				  } 
				  ;

func_invo_args: func_invo_arg
				  | func_invo_args COMMA func_invo_arg
				  ;

func_invo_arg: expr {
						invo_func_args[count] = $1;
						count = count + 1;
				 }
				 ;

/*
	if_cond
*/
if_cond: IF {fprintf(fout,"/* if start */\n");} LEFT_PARENTHESE expr if_asm RIGHT_PARENTHESE if_remain
		 ;

if_asm:%empty {
			 fprintf(fout,"ifeq L%d\n",flowCount++);
		}
	   ;

if_remain:cond_body {
				 fprintf(fout,"/* if end */\n");
				 fprintf(fout,"L%d:\n",flowCount-1);
				 labelCheck = 1;
			}
			|cond_body ELSE {
          	else_if_check = 1;
				fprintf(fout,"goto L%d\n",flowCount);
          	fprintf(fout,"L%d:\n",flowCount-1);
      	} cond_body {
				else_if_check = 0;
				fprintf(fout,"/* if end */\n");
          	fprintf(fout,"L%d:\n",flowCount++);
				labelCheck = 1;
      	}
		   ;

cond_body:{createTable();} block{
				printf("dump IF block symbol table\n");
				dump(tableList);
				deleteTable();
			}
			|{createTable();} stmt{
				if(else_if_check = 1){
					else_if_check = 0;
				}
				else{
					printf("dump IF block symbol table\n");
					dump(tableList);
				}
				deleteTable();
			}
			;

/*
	while_loop
*/
while_loop: WHILE {
					fprintf(fout,"/* while start */\n");
					if(labelCheck == 0)
						fprintf(fout,"L%d:\n",flowCount++);
					else
						labelCheck = 0;
			 } LEFT_PARENTHESE expr RIGHT_PARENTHESE {fprintf(fout,"ifeq L%d\n",flowCount);} while_body{
				fprintf(fout,"goto L%d\n",flowCount-3);
				fprintf(fout,"/* while end */\n");
				fprintf(fout,"L%d:\n",flowCount++);
				labelCheck = 1;
				printf("dump While block symbol table\n");
				dump(tableList);
				deleteTable();
			 }
			 ;

while_body:{createTable();}block
			 |{createTable();}stmt
			 ;

/*
	for_loop
*/
for_loop: FOR {fprintf(fout,"/* for start */\n");} LEFT_PARENTHESE identifier FOR_ASSIGN INT_LITERAL {
				 temp_node = searchID($4);
				 if(temp_node == NULL){
                idError();
             }
				 else{
				  typeCheck(temp_node->type,$6);
				  fprintf(fout,"sipush 1\n");
				  if(temp_node->index == -2)
					  fprintf(fout,"putstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
				  else if(temp_node->index >= 0)
					  fprintf(fout,"istore %d\n",temp_node->index);
				 }

				 if(labelCheck == 0)
					 fprintf(fout,"L%d:\n",flowCount++);
				 else
					 labelCheck = 0;
		  } TO INT_LITERAL {
				 fprintf(fout,"getstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
				 fprintf(fout,"sipush %d\n",yylval.integer);
			  	 compare("ifle");
				 fprintf(fout,"ifeq L%d\n",flowCount);
		  } RIGHT_PARENTHESE loop_body{
				 temp_node = searchID($4);
				 fprintf(fout,"sipush 1\n");
				 fprintf(fout,"getstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
				 fprintf(fout,"iadd\n");
				 fprintf(fout,"putstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
			  	 fprintf(fout,"goto L%d\n",flowCount-3);
				 fprintf(fout,"/* for end */\n");
				 fprintf(fout,"L%d:\n",flowCount++);
				 labelCheck = 1;
				 printf("dump For block symbol table\n");
			 	 dump(tableList);
				 deleteTable();
		  }
		  ;

loop_body:{createTable();}block
			|{createTable();} stmt
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
	 | '-' expr %prec UMINUS {
		 $$ = $2;
		 if($2 != 3)
			 printf("line : %d ,warning : type is not compatible with operator\n",linenum-1);
		 else
			 fprintf(fout,"ineg\n");

	 }
	 | '!' expr {
		 $$ = $2;
		 if($2 != 2){
			 printf("line : %d ,warning : type is not compatible with operator\n",linenum-1);
		 }
		 else{
			 fprintf(fout,"sipush 1\n");
			 fprintf(fout,"ixor\n");
		 }
	 }
	 | expr '*' expr { 
		 typeCheck($1,$3);
		 $$ = $1;
		 fprintf(fout,"imul\n");
	 }
	 | expr '/' expr{
		 typeCheck($1,$3);
		 $$ = $1; 
		 fprintf(fout,"idiv\n");
	 }
	 | expr '+' expr{
		 typeCheck($1,$3);
		 $$ = $1;  
		 fprintf(fout,"iadd\n");
	 }
	 | expr '-' expr{ 
		 typeCheck($1,$3);
       $$ = $1;
		 fprintf(fout,"isub\n");
	 }
	 | expr LT expr{
		 typeCheck($1,$3);
       $$ = $1;
		 compare("iflt");
	 }
	 | expr LE expr{
		 typeCheck($1,$3);
       $$ = $1; 
		 compare("ifle");
	 }
	 | expr EQ expr{ 
		 typeCheck($1,$3);
       $$ = $1; 
		 compare("ifeq");
	 }
	 | expr GE expr{
		 typeCheck($1,$3);
       $$ = $1; 
		 compare("ifge");
	 }
	 | expr GT expr{
		 typeCheck($1,$3);
       $$ = $1;
		 compare("ifgt");
	 }
	 | expr NE expr{
		 typeCheck($1,$3);
       $$ = $1;
		 compare("ifne");
	 }
	 | expr AND expr{
		 typeCheck($1,$3);
       $$ = $1; 	 
		 fprintf(fout,"iand\n");
	 }
	 | expr OR expr{
		 typeCheck($1,$3);
       $$ = $1; 
		 fprintf(fout,"ior\n");
	 }
	 | literals {
		 $$ = $1;
		 if($1 == 2 || $1 == 3){
			 value = yylval.integer;
		 }
		 else if($1 = 5){
			 value_str = malloc(sizeof(char)*strlen(yylval.string)+1);
			 strcpy(value_str,yylval.string);
		 }
		 if(is_val_assign == 0){
			 if(value == 1 && $1 == 2){
				 fprintf(fout,"iconst_1\n");
			 }
			 else if(value == 0 && $1 == 2){
				 fprintf(fout,"iconst_0\n");
			 }
			 else if($1 == 3 && (value > 32767 || value < -32767)){
				 fprintf(fout,"ldc %d\n",value);
			 }
			 else if($1 == 3){
				 fprintf(fout,"sipush %d\n",value);
			 }
		 	else if($1 == 5){
				 fprintf(fout,"ldc \"%s\"\n",value_str);
			 }
		 }

	 }
	 | identifier {
		 temp_node = searchID($1);
		 if(temp_node == NULL){
			 idError();
			 $$ = 0;
		 }
		 else{
			 $$ = temp_node->type;
			 if(temp_node->index == -2){
				 fprintf(fout,"getstatic %s %s.%s\n",int2type(temp_node->type),className,temp_node->idName);
			 }
			 else if(temp_node->index == -1){
				 if(temp_node->value == 1 && temp_node->type == 2)
					 fprintf(fout,"iconst_1\n");
		 		 else if(temp_node->value == 0 && temp_node->type == 2)
			 		 fprintf(fout,"iconst_0\n");
				 else if(temp_node->type == 3 && (temp_node->value > 32767 || temp_node->value < -32767))
			  		 fprintf(fout,"ldc %d\n",temp_node->value);
		 		 else if(temp_node->type == 3)
			 	    fprintf(fout,"sipush %d\n",temp_node->value);
		 		 else if(temp_node->type == 5)
			 		 fprintf(fout,"ldc \"%s\"\n",temp_node->value_str);
			 }
			 else{
				 fprintf(fout,"iload %d\n",temp_node->index);
			 }
		 }
	 }
	 | array_id {
		 if(searchID($1) == NULL){
			 idError();
		 	 $$ = 0;
		 }
		 else{
		 	 $$ = searchID($1)->type;
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
array_id: identifier LEFT_SQUARE expr RIGHT_SQUARE {
				 if($3 != 3){
					 printf("line : %d ,error :array index need to be integer\n",linenum-1);
				 	 $$ = $1;
		  		 }
		  }
		  ;
/*
	types
*/
types: CHAR {$$ = 1;}
	  | BOOLEAN {$$ = 2;}
     | INT  {$$ = 3;}
	  | VOID {$$ = 3;}
	  | FLOAT {$$ = 4;}
	  | STRING {$$ = 5;}
	  ;

/*
	Literals
*/
literals: INT_LITERAL {$$ = 3;}
		  | REAL_LITERAL {$$ = 4;}
		  | STRING_LITERAL {$$ = 5;}
		  | TRUE {$$ = 2;}
		  | FALSE {$$ = 2;}
		  ;

%%
int yyerror(char *s)
{
    fprintf(stderr, "line:%d,%s\n",linenum-1, s);
	 return 0;
}

//reusing in operator compare
void compare(char* asm_code){
	fprintf(fout,"isub\n");
	fprintf(fout,"%s L%d\n",asm_code,flowCount++);
	fprintf(fout,"iconst_0\n");
	fprintf(fout,"goto L%d\n",flowCount);
	fprintf(fout,"L%d:\n",flowCount-1);
	fprintf(fout,"iconst_1\n");
	fprintf(fout,"L%d:\n",flowCount);
	labelCheck = 1;
	flowCount++;
	return;
}

int main(int argc,char *argv[])
{
	//output filestream open
	 fout = fopen("example.jasm","w");
	 if(fout == NULL){
		 printf("file open error\n");
	 }
	 else{
		 yyparse();
	 	 printf("object symbol table:\n"); 
	    dump(tableList);
	 	 fclose(fout);
	 }
	 return 0;
}

