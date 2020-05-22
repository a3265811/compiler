%{
#include "symbolTable.h" //symbol table header file
#include "y.tab.h"
#define MAX_LINE_LENG 256 //max string length
#define LIST strcat(buf,yytext)  //string concatenation function
#define token(t) {LIST; printf("<%s>\n",t);} //print keyword and some operators
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);} //print interger number 
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);} //print float number and string
int linenum = 1; //line counter
char buf[MAX_LINE_LENG]; //output string
char outputStr[MAX_LINE_LENG];//extra output string for recognizing string
char c;
%}
digit [0-9]+
letter [A-Za-z]+
%x COMMENT
%x oneCOMMENT
%x STRING

%%
[ ]*	 ;	//whitespace
[ \t]* ;	//tabspace
","	 return ',';// -----Delimiters-----
":"	 return ':';//			|
"."	 return '.';//			|
";"	 return ';';//			|
"("    return '(';//			|
")"	 return ')';//			|
"["	 return '[';//			|
"]"	 return ']';//			|
"{"	 return '{';//			|
"}"	 return '}';//			|
"="	 return '='; // --------------------
"+"	 return '+';// -----Arithmetic,Rational,and Logical Operators-----
"-"	 return '-';//								|
"*"	 return '*';//								|
"/"	 return '/';//								|
"%"	 return '%';//                        |      
"<"	 return '<';//                        |      
"<="	 return LE;//                       |      
">="	 return GE;//                       |      
">"	 return '>';//                        |      
"=="	 return EE;//                       |      
"!="	 return NE;//                       |      
"&&"	 return AA;//                       |      
"||"	 return OO;//                       |      
"!"	 return '!';// ---------------------------------------------------
"boolean"  return BOOLEAN;// -----Keywords-----
"break"	  return BREAK;//					|
"char"	  return CHAR;//               |     
"case"	  return CASE;//               |     
"class"	  return CLASS;//              |     
"continue" return CONTINUE;//        |     
"def"	 	  return DEF;//                   |     
"do"	     return DO;//                    |     
"else"	  return ELSE;//               |     
"exit"	  return EXIT;//               |     
"float"	  return FLOAT;//              |     
"for"	     return FOR;//                   |     
"if"	     return IF;//                    |     
"int"	     return INT;//                   |     
"null"	  return NULL_NUM;//               |     
"object"	  return OBJECT;//             |     
"print"	  return PRINT;//              |     
"println"  return PRINTLN;//         |     
"repeat"	  return REPEAT;//             |     
"return"	  return RETURN;//             |     
"string"	  return STRING;//             |     
"to"	     return TO;//                    |     
"type"	  return TYPE;//               |     
"val"	     return VAL;//                   |     
"var"	     return VAR;//                   |     
"while"	  return WHILE;//     -------------------
"true"     return TRUE;	//Boolean Constants
"false"    return FALSE;	//Boolean Constants
\n 	     {
				linenum++;
				return '\n';
			  }	/*newline*/
 /* interger number*/
{digit}    return NUM;
			  

	/*real number*/
{digit}("."{digit})?("E"[+-]?{digit})?		return REAL;
												
{letter}({letter}|{digit})*	{
									    insert(tableList,yytext,"Nothing");
										 return ID;					 
									   } /*Identifiers, and insert into symbol table*/
"\""	{
		LIST;
		outputStr[0]='\0';		
		BEGIN STRING;
		} /*switch to string state*/
<STRING>"\"" {
				 c = input();
				 if(c == '\"'){
					 strcat(outputStr,"\"");
				    LIST;
					 strcat(buf,"\"");}
				 else{
			 	 	 unput(c);
				 	 yytext = "\"";
					 tokenString("string",outputStr);
					 return STRING_LETTER;
				  	 BEGIN 0;
				  }
				 } /*solving the extra \" and back to initial state. If get more character then yytext will be wrong,so we need to set yytext back to last charater.*/
<STRING>\n {
			  unput(yytext[0]);
			  if(outputStr[0]!='\0'){
			  for(int i = 0 ; i < strlen(outputStr); i++)
				  unput(buf[strlen(buf)-i-1]);
			  }
			  buf[strlen(buf)-strlen(outputStr)]='\0';
			  BEGIN 0;
			  } /*some foolproof design and back to initial state*/
<STRING>. {
			 LIST;
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
"$"     return 0;
.       return yytext[0];
%%

