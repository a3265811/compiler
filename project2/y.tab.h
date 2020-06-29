/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMA = 258,
    COLON = 259,
    PERIOD = 260,
    SEMICOLON = 261,
    LEFT_PARENTHESE = 262,
    RIGHT_PARENTHESE = 263,
    LEFT_SQUARE = 264,
    RIGHT_SQUARE = 265,
    LEFT_CURLY = 266,
    RIGHT_CURLY = 267,
    ASSIGN = 268,
    FOR = 269,
    REPEAT = 270,
    DO = 271,
    WHILE = 272,
    FOR_ASSIGN = 273,
    VAL = 274,
    VAR = 275,
    CHAR = 276,
    INT = 277,
    FLOAT = 278,
    STRING = 279,
    BOOLEAN = 280,
    VOID = 281,
    OBJECT = 282,
    DEF = 283,
    PRINT = 284,
    PRINTLN = 285,
    READ = 286,
    TRUE = 287,
    FALSE = 288,
    IF = 289,
    ELSE = 290,
    CONTINUE = 291,
    BREAK = 292,
    EXIT = 293,
    TO = 294,
    CASE = 295,
    RETURN = 296,
    TYPE = 297,
    NULL_LITERAL = 298,
    CLASS = 299,
    ID = 300,
    INT_LITERAL = 301,
    REAL_LITERAL = 302,
    STRING_LITERAL = 303,
    OR = 304,
    AND = 305,
    LT = 306,
    GT = 307,
    LE = 308,
    GE = 309,
    EQ = 310,
    NE = 311,
    UMINUS = 312
  };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define PERIOD 260
#define SEMICOLON 261
#define LEFT_PARENTHESE 262
#define RIGHT_PARENTHESE 263
#define LEFT_SQUARE 264
#define RIGHT_SQUARE 265
#define LEFT_CURLY 266
#define RIGHT_CURLY 267
#define ASSIGN 268
#define FOR 269
#define REPEAT 270
#define DO 271
#define WHILE 272
#define FOR_ASSIGN 273
#define VAL 274
#define VAR 275
#define CHAR 276
#define INT 277
#define FLOAT 278
#define STRING 279
#define BOOLEAN 280
#define VOID 281
#define OBJECT 282
#define DEF 283
#define PRINT 284
#define PRINTLN 285
#define READ 286
#define TRUE 287
#define FALSE 288
#define IF 289
#define ELSE 290
#define CONTINUE 291
#define BREAK 292
#define EXIT 293
#define TO 294
#define CASE 295
#define RETURN 296
#define TYPE 297
#define NULL_LITERAL 298
#define CLASS 299
#define ID 300
#define INT_LITERAL 301
#define REAL_LITERAL 302
#define STRING_LITERAL 303
#define OR 304
#define AND 305
#define LT 306
#define GT 307
#define LE 308
#define GE 309
#define EQ 310
#define NE 311
#define UMINUS 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:1909  */

	int integer;
	char *string;

#line 173 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
