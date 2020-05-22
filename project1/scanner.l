%{
#include "hash.h" //symbol table header file
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
[ ]*	 LIST;	//whitespace
[ \t]* LIST;	//tabspace
","	 token("\',\'");// -----Delimiters-----
":"	 token("\':\'");//			|
"."	 token("\'.\'");//			|
";"	 token("\';\'");//			|
"("    token("\'(\'");//			|
")"	 token("\')\'");//			|
"["	 token("\'[\'");//			|
"]"	 token("\']\'");//			|
"{"	 token("\'{\'");//			|
"}"	 token("\'}\'");//			|
"="	 token("\'=\'"); // --------------------
"+"	 token("\'+\'");// -----Arithmetic,Rational,and Logical Operators-----
"-"	 token("\'-\'");//								|
"*"	 token("\'*\'");//								|
"/"	 token("\'/\'");//								|
"%"	 token("\'%\'");//                        |      
"<"	 token("\'<\'");//                        |      
"<="	 token("\'<=\'");//                       |      
">="	 token("\'>=\'");//                       |      
">"	 token("\'>\'");//                        |      
"=="	 token("\'==\'");//                       |      
"!="	 token("\'!=\'");//                       |      
"&&"	 token("\'&&\'");//                       |      
"||"	 token("\'||\'");//                       |      
"!"	 token("\'!\'");// ---------------------------------------------------
"boolean"	 token("BOOLEAN");// -----Keywords-----
"break"	 token("BREAK");//					|
"char"	 token("CHAR");//               |     
"case"	 token("CASE");//               |     
"class"	 token("CLASS");//              |     
"continue"	 token("CONTINUE");//        |     
"def"	 token("DEF");//                   |     
"do"	 token("DO");//                    |     
"else"	 token("ELSE");//               |     
"exit"	 token("EXIT");//               |     
"float"	 token("FLOAT");//              |     
"for"	 token("FOR");//                   |     
"if"	 token("IF");//                    |     
"int"	 token("INT");//                   |     
"null"	 token("NULL");//               |     
"object"	 token("OBJECT");//             |     
"print"	 token("PRINT");//              |     
"println"	 token("PRINTLN");//         |     
"repeat"	 token("REPEAT");//             |     
"return"	 token("RETURN");//             |     
"string"	 token("STRING");//             |     
"to"	 token("TO");//                    |     
"type"	 token("TYPE");//               |     
"val"	 token("VAL");//                   |     
"var"	 token("VAR");//                   |     
"while"	 token("WHILE");//     -------------------
"true" token("TRUE");	//Boolean Constants
"false" token("FALSE");	//Boolean Constants
\n 	 {LIST;
		  printf("%d: %s", linenum, buf);
		  linenum++;
		  buf[0] = '\0';}	/*newline*/
{digit} tokenInteger("integer",atoi(yytext)); //interger number
{digit}("."{digit})?("E"[+-]?{digit})? tokenString("float",yytext); //real number
{letter}({letter}|{digit})*	{tokenString("id",yytext);
									    insert(yytext);					 
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
.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        } 
%%
int main()
{
	create(); //create symbol table
	yylex();
	fflush(yyout);
	dump(); //show the whole symbol table
	return 0; 
}

