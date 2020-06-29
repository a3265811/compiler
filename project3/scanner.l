%{
#include "symbolTable.h" //symbol table header file
#include "y.tab.h"
#define MAX_LINE_LENG 256 //max string length
#define LIST strcat(buf,yytext)  //string concatenation function
int linenum = 1; //line countier
char buf[MAX_LINE_LENG]; //output string
char outputStr[MAX_LINE_LENG];//extra output string for recognizing string
char c; //for string detecting
FILE* fout;//.jasm file output
%}
digit [0-9]+
letter [A-Za-z]+
%x COMMENT
%x oneCOMMENT
%x STRING_STATE

%%
 /* -----whilespace and tabspace------ */
[ ]*	 LIST;;
[ \t]* LIST;;
 /* -----Delimiters----- */
","	 {LIST; return COMMA;}
":"	 {LIST; return COLON;}
"."	 {LIST; return PERIOD;}
";"	 {LIST; return SEMICOLON;}
"("    {LIST; return LEFT_PARENTHESE;}
")"	 {LIST; return RIGHT_PARENTHESE;}
"["	 {LIST; return LEFT_SQUARE;}
"]"	 {LIST; return RIGHT_SQUARE;}
"{"	 {LIST; return LEFT_CURLY;}
"}"	 {LIST; return RIGHT_CURLY;}
"="	 {LIST; return ASSIGN;}
 /* -----Arithmetic,Rational, and Logical Operators----- */
"+"	 {LIST; return '+';}
"-"	 {LIST; return '-';}
"*"	 {LIST; return '*';}
"/"	 {LIST; return '/';}
"%"	 {LIST; return '%';}
"<"	 {LIST; return LT;}
"<="	 {LIST; return LE;}
">="	 {LIST; return GE;}
">"	 {LIST; return GT;}
"=="	 {LIST; return EQ;}
"!="	 {LIST; return NE;}
"&&"	 {LIST; return AND;}
"||"	 {LIST; return OR;}
"<-"   {LIST; return FOR_ASSIGN;}
"!"	 {LIST; return '!';}
 /* -----Keywords----- */
"val"	 {LIST; return VAL;}
"var"	 {LIST; return VAR;}
"char"	 {
			  LIST;
			  yylval.integer = 1; 
			  return CHAR;
			 }
"boolean" {
			  LIST;
			  yylval.integer = 2;
  			  return BOOLEAN;
			 }
"int"     {
			  LIST;
			  yylval.integer = 3; 
			  return INT;
			 }
"void"    {
			  LIST;
			  yylval.integer = 3; 
			  return VOID;
			 }
"float"	 {
	        LIST;
			  yylval.integer = 4; 
			  return FLOAT;
			 }
"string"	 {
			  LIST;
			  yylval.integer = 5;  
			  return STRING;
			 }
"break"	 {LIST; return BREAK;}
"case"	 {LIST; return CASE;}     
"class"	 {LIST; return CLASS;}     
"continue"	 {LIST; return CONTINUE;}     
"def"	 {LIST; return DEF;}
"do"	 {LIST; return DO;}                        
"else"	 {LIST; return ELSE;}     
"exit"	 {LIST; return EXIT;}     
"for"	 {LIST; return FOR;}     
"if"	 {LIST; return IF;}     
"null"	 {LIST; return NULL_LITERAL;}     
"object"	 {LIST; return OBJECT;}     
"print"	 {LIST; return PRINT;}     
"println"	 {LIST; return PRINTLN;}     
"repeat"	 {LIST; return REPEAT;}     
"return"	 {LIST; return RETURN;}     
"to"	 {LIST; return TO;}     
"type"	 {LIST; return TYPE;}     
"while"	 {LIST; return WHILE;}
"read" {LIST; return READ;}
 /* -----Boolean Constants----- */
"true" {
			LIST;
		   yylval.integer = 1;
			return TRUE;
		 }
"false" {
			LIST;
			yylval.integer = 0;
			return FALSE;
		  }
 /* -----newline----- */
\n 	 {
			fprintf(fout,"/* %d: %s */\n",linenum,buf);
			buf[0] = '\0';
			linenum++;
		 }
 /* -----constant----- */
{digit} {
			LIST;
			yylval.integer = atoi(yytext);
			return INT_LITERAL;
		  }
{digit}("."{digit})?("E"[+-]?{digit})? {
													  LIST;
													  yylval.integer = 4;
													  return REAL_LITERAL;
													}
 /* -----Identifiers----- */ 
{letter}({letter}|{digit})*	{
										 LIST;
										 yylval.string = malloc(sizeof(char)*(strlen(yytext)+1));
										 strcpy(yylval.string,yytext);
										 return ID;
									   }
 /* -----String----- */
"\""	{
		LIST;
		outputStr[0]='\0';		
		BEGIN STRING_STATE;
		}
<STRING_STATE>"\"" {
				 LIST;
				 c = input();
				 if(c == '\"'){
					 LIST;
					 strcat(outputStr,"\"");
				  }
				 else{
			 	 	 unput(c);
				 	 yytext = "\"";
					 yylval.string = malloc(sizeof(char)*strlen(outputStr)+1);
					 strcpy(yylval.string,outputStr);
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
			 LIST;
			 strcat(outputStr,yytext);
			 } /*any character put into output string*/

 /*-----Comments----- */
"//"	{
		strcat(buf,"#");
		BEGIN oneCOMMENT;
		} /*switch to one line comment state*/
<oneCOMMENT>. LIST; //any character
<oneCOMMENT>\n {
					fprintf(fout,"/* %d: %s */\n",linenum, buf);
					linenum++;
					buf[0]='\0';
					BEGIN 0;
					} /*end of one line commend and show the output string and back to initial state*/

"/*"  {
		strcat(buf,"#");
		BEGIN COMMENT;
		} /*switch to cross-line comment state*/
<COMMENT>\n {
		      fprintf(fout,"/* %d: %s */\n", linenum, buf);
				linenum++;
				buf[0]='#';
				buf[1]='\0';
				} /*if get \n and let the line counter plus one*/ 
<COMMENT>"*/" {
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
