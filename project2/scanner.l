%{
#include "symbolTable.h" //symbol table header file
#include "y.tab.h"
#define MAX_LINE_LENG 256 //max string length
#define LIST strcat(buf,yytext)  //string concatenation function
#define token(t) {LIST;sprintf(result,"%d",t); printf("<%s>\n",result);return t;} //print keyword and some operators
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);} //print interger number 
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);} //print float number and string
int linenum = 1; //line counter
char buf[MAX_LINE_LENG]; //output string
char outputStr[MAX_LINE_LENG];//extra output string for recognizing stringi
char result[MAX_LINE_LENG];
char *temp_string;
char c;
%}
digit [0-9]+
letter [A-Za-z]+
%x COMMENT
%x oneCOMMENT
%x STRING_STATE

%%
[ ]*	 ;	//whitespace
[ \t]* ;	//tabspace
","	 return COMMA;// -----Delimiters-----
":"	 return COLON;//			|
"."	 return PERIOD;//			|
";"	 return SEMICOLON;//			|
"("    return LEFT_PARENTHESE;//			|
")"	 return RIGHT_PARENTHESE;//			|
"["	 return LEFT_SQUARE;//			|
"]"	 return RIGHT_SQUARE;//			|
"{"	 return LEFT_CURLY;//			|
"}"	 return RIGHT_CURLY;//			|
"="	 return ASSIGN; // --------------------
"+"	 return '+';// -----Arithmetic,Rational,and Logical Operators-----
"-"	 return '-';//								|
"*"	 return '*';//								|
"/"	 return '/';//								|
"%"	 return '%';//                        |      
"<"	 return LT;//                        |      
"<="	 return LE;//                       |      
">="	 return GE;//                       |      
">"	 return GT;//                        |      
"=="	 return EQ;//                       |      
"!="	 return NE;//                       |      
"&&"	 return AND;//                       |      
"||"	 return OR;//                       |      
"<-"   return FOR_ASSIGN;//
"!"	 return '!';// ---------------------------------------------------
"val"	 return VAL;//                   |     
"var"	 return VAR;//                   |     
"boolean" {yylval.string = "boolean"; return BOOLEAN;}// -----Keywords-----
"int"     {yylval.string = "int"; return INT;}     
"char"	 {yylval.string = "char"; return CHAR;}//               |     
"string"	 {yylval.string = "string";  return STRING;}//             |     
"float"	 {yylval.string = "float"; return FLOAT;}//              |     
"void"    {yylval.string = "void"; return VOID;}
"break"	 return BREAK;//					|
"case"	 return CASE;//               |     
"class"	 return CLASS;//              |     
"continue"	 return CONTINUE;//        |     
"def"	 {return DEF;}//                   |     
"do"	 return DO;//                    |     
"else"	 return ELSE;//               |     
"exit"	 return EXIT;//               |     
"for"	 return FOR;//                   |     
"if"	 return IF;//                    |     
"null"	 return NULL_LITERAL;//               |     
"object"	 return OBJECT;//             |     
"print"	 return PRINT;//              |     
"println"	 return PRINTLN;//         |     
"repeat"	 return REPEAT;//             |     
"return"	 return RETURN;//             |     
"to"	 return TO;//                    |     
"type"	 return TYPE;//               |     
"while"	 return WHILE;//     -------------------
"true" return TRUE;	//Boolean Constants
"false" return FALSE;	//Boolean Constants
"read" return READ;
\n 	 linenum++;	/*newline*/
{digit} {
			yylval.string = "int";
			return INT_LITERAL;
		  }
{digit}("."{digit})?("E"[+-]?{digit})? {
													  yylval.string = "float";
													  return REAL_LITERAL;
													}
{letter}({letter}|{digit})*	{
									    //insert(tableList,yytext, 0);
										 yylval.string = malloc(sizeof(char)*(strlen(yytext)+1));
										 /*for(int i = 0; i < strlen(yytext);i++){
										 	temp_string[i] = yytext[i];
										 }*/
										 strcpy(yylval.string,yytext);
										 return ID;
									   } /*Identifiers, and insert into symbol table*/
"\""	{
		LIST;
		outputStr[0]='\0';		
		BEGIN STRING_STATE;
		} /*switch to string state*/
<STRING_STATE>"\"" {
				 c = input();
				 if(c == '\"'){
					 strcat(outputStr,"\"");
				  }
				 else{
			 	 	 unput(c);
				 	 yytext = "\"";
				  	 BEGIN 0;
					 yylval.string = "string";
					 return STRING_LITERAL;
				  }
				 } /*solving the extra \" and back to initial state. If get more character then yytext will be wrong,so we need to set yytext back to last charater.*/
<STRING_STATE>\n {
			  unput(yytext[0]);
			  if(outputStr[0]!='\0'){
			  	for(int i = 0 ; i < strlen(outputStr); i++)
				  unput(buf[strlen(buf)-i-1]);
			  }
			  buf[strlen(buf)-strlen(outputStr)]='\0';
			  BEGIN 0;
			  printf("bad string\n");
			  } /*some foolproof design and back to initial state*/
<STRING_STATE>. {
			 strcat(outputStr,yytext);
			 } /*any character put into output string*/

"//"	{
		LIST;
		BEGIN oneCOMMENT;
		} /*switch to one line comment state*/
<oneCOMMENT>. LIST; //any character
<oneCOMMENT>\n {
					LIST;
					printf("%d: %s",linenum, buf);
					linenum++;
					buf[0]='\0';
					BEGIN 0;
					} /*end of one line commend and show the output string and back to initial state*/

"/*"  {
		LIST;
		BEGIN COMMENT;
		} /*switch to cross-line comment state*/
<COMMENT>\n {
				LIST;
		      printf("%d: %s", linenum, buf);
				linenum++;
				buf[0]='\0';
				} /*if get \n and let the line counter plus one*/ 
<COMMENT>"*/" {
				  LIST;
				  BEGIN 0;
				  } /*end of cross-line commend and back to initial state*/
<COMMENT>. LIST; //any character put into output string

	/*any other charactor will be discard*/
.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        return yytext[0];
        } 
%%
/*int main(){
	yylex();
	return 0;
}*/
