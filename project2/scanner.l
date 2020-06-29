%{
#include "symbolTable.h" //symbol table header file
#include "y.tab.h"
#define MAX_LINE_LENG 256 //max string length
#define LIST strcat(buf,yytext)  //string concatenation function
int linenum = 1; //line counter
char buf[MAX_LINE_LENG]; //output string
char outputStr[MAX_LINE_LENG];//extra output string for recognizing string
char c;
%}
digit [0-9]+
letter [A-Za-z]+
%x COMMENT
%x oneCOMMENT
%x STRING_STATE

%%
 /* -----whilespace and tabspace------ */
[ ]*	 ;
[ \t]* ;
 /* -----Delimiters----- */
","	 return COMMA;
":"	 return COLON;
"."	 return PERIOD;
";"	 return SEMICOLON;
"("    return LEFT_PARENTHESE;
")"	 return RIGHT_PARENTHESE;
"["	 return LEFT_SQUARE;
"]"	 return RIGHT_SQUARE;
"{"	 return LEFT_CURLY;
"}"	 return RIGHT_CURLY;
"="	 return ASSIGN;
 /* -----Arithmetic,Rational, and Logical Operators----- */
"+"	 return '+';
"-"	 return '-';
"*"	 return '*';
"/"	 return '/';
"%"	 return '%';
"<"	 return LT;
"<="	 return LE;
">="	 return GE;
">"	 return GT;
"=="	 return EQ;
"!="	 return NE;
"&&"	 return AND;
"||"	 return OR;
"<-"   return FOR_ASSIGN;
"!"	 return '!';
 /* -----Keywords----- */
"val"	 return VAL;
"var"	 return VAR;
"boolean" {
			  yylval.string = "boolean";
  			  return BOOLEAN;
			 }
"int"     {
			  yylval.string = "int"; 
			  return INT;
			 }
"char"	 {
			  yylval.string = "char"; 
			  return CHAR;
			 }
"string"	 {
			  yylval.string = "string";  
			  return STRING;
			 }
"float"	 {
			  yylval.string = "float"; 
			  return FLOAT;
			 }
"void"    {
			  yylval.string = "void"; 
			  return VOID;
			 }
"break"	 return BREAK;
"case"	 return CASE;     
"class"	 return CLASS;     
"continue"	 return CONTINUE;     
"def"	 return DEF;
"do"	 return DO;                        
"else"	 return ELSE;     
"exit"	 return EXIT;     
"for"	 return FOR;     
"if"	 return IF;     
"null"	 return NULL_LITERAL;     
"object"	 return OBJECT;     
"print"	 return PRINT;     
"println"	 return PRINTLN;     
"repeat"	 return REPEAT;     
"return"	 return RETURN;     
"to"	 return TO;     
"type"	 return TYPE;     
"while"	 return WHILE;
"read" return READ;
 /* -----Boolean Constants----- */
"true" return TRUE;
"false" return FALSE;
 /* -----newline----- */
\n 	 {
			if(buf[0]!='\0'){
			LIST;
			printf("%d:%s",linenum,buf);
			}
			buf[0] = '\0';
			linenum++;
		 }
 /* -----constant----- */
{digit} {
			yylval.string = "int";
			return INT_LITERAL;
		  }
{digit}("."{digit})?("E"[+-]?{digit})? {
													  yylval.string = "float";
													  return REAL_LITERAL;
													}
 /* -----Identifiers----- */ 
{letter}({letter}|{digit})*	{
										 yylval.string = malloc(sizeof(char)*(strlen(yytext)+1));
										 strcpy(yylval.string,yytext);
										 return ID;
									   }
 /* -----String----- */
"\""	{
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
					 yylval.string = "string";
				  	 BEGIN 0;
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

 /*-----Comments----- */
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
