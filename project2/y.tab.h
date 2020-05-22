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
    BOOLEAN = 258,
    CHAR = 259,
    CASE = 260,
    CLASS = 261,
    CONTINUE = 262,
    DEF = 263,
    DO = 264,
    ELSE = 265,
    EXIT = 266,
    FALSE = 267,
    FLOAT = 268,
    FOR = 269,
    IF = 270,
    INT = 271,
    OBJECT = 272,
    PRINT = 273,
    PRINTLN = 274,
    REPEAT = 275,
    RETURN = 276,
    TO = 277,
    TRUE = 278,
    TYPE = 279,
    VAL = 280,
    VAR = 281,
    WHILE = 282,
    BREAK = 283,
    NULL_NUM = 284,
    ID = 285,
    NUM = 286,
    REAL = 287,
    STRING_LETTER = 288,
    LE = 289,
    GE = 290,
    EE = 291,
    NE = 292,
    AA = 293,
    OO = 294,
    UMINUS = 295
  };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define CHAR 259
#define CASE 260
#define CLASS 261
#define CONTINUE 262
#define DEF 263
#define DO 264
#define ELSE 265
#define EXIT 266
#define FALSE 267
#define FLOAT 268
#define FOR 269
#define IF 270
#define INT 271
#define OBJECT 272
#define PRINT 273
#define PRINTLN 274
#define REPEAT 275
#define RETURN 276
#define TO 277
#define TRUE 278
#define TYPE 279
#define VAL 280
#define VAR 281
#define WHILE 282
#define BREAK 283
#define NULL_NUM 284
#define ID 285
#define NUM 286
#define REAL 287
#define STRING_LETTER 288
#define LE 289
#define GE 290
#define EE 291
#define NE 292
#define AA 293
#define OO 294
#define UMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
