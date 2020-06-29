/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 84 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 19 "parser.y" /* yacc.c:355  */

	int integer;
	char *string;

#line 243 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,    60,    59,     2,    58,     2,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    52,    53,    54,    55,
      56,    57,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    54,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    74,    78,    86,    90,    94,    98,
     106,   116,   116,   131,   132,   133,   135,   136,   139,   140,
     142,   147,   157,   158,   159,   160,   161,   162,   163,   164,
     167,   175,   187,   188,   191,   194,   195,   198,   206,   218,
     233,   234,   237,   248,   253,   256,   257,   263,   266,   267,
     273,   276,   277,   282,   285,   286,   287,   288,   289,   290,
     291,   292,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   322,
     330,   331,   332,   338,   344,   349,   350,   351,   352,   353,
     354,   359,   360,   361
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "PERIOD", "SEMICOLON",
  "LEFT_PARENTHESE", "RIGHT_PARENTHESE", "LEFT_SQUARE", "RIGHT_SQUARE",
  "LEFT_CURLY", "RIGHT_CURLY", "ASSIGN", "FOR", "REPEAT", "DO", "WHILE",
  "FOR_ASSIGN", "VAL", "VAR", "CHAR", "INT", "FLOAT", "STRING", "BOOLEAN",
  "VOID", "OBJECT", "DEF", "PRINT", "PRINTLN", "READ", "TRUE", "FALSE",
  "IF", "ELSE", "CONTINUE", "BREAK", "EXIT", "TO", "CASE", "RETURN",
  "TYPE", "NULL_LITERAL", "CLASS", "ID", "INT_LITERAL", "REAL_LITERAL",
  "STRING_LITERAL", "OR", "AND", "'!'", "LT", "GT", "LE", "GE", "EQ", "NE",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "$accept", "program", "$@1",
  "program_body", "val_dec", "var_dec", "array_dec", "func_def", "$@2",
  "func_def_remain", "func_args", "func_arg_list", "func_arg", "stmt",
  "assign_stmt", "print_stmt", "return_stmt", "return_body", "read_stmt",
  "func_invo_stmt", "func_invo_args", "func_invo_arg", "if_cond",
  "cond_body", "while_loop", "while_body", "for_loop", "loop_body",
  "block", "block_body", "expr", "identifier", "array_id", "types",
  "literals", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    33,   306,   307,   308,   309,   310,   311,    45,    43,
      42,    47,   312
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,  -140,    10,   -29,  -140,  -140,    25,   488,     6,    36,
     -29,   -29,   -29,    38,    50,   -29,    61,   317,   378,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,    49,    54,   -29,   317,    29,    42,    63,   317,
     317,    62,  -140,   317,   317,  -140,  -140,  -140,   317,   317,
    -140,  -140,  -140,  -140,   -32,    28,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,   317,   317,   317,   317,    56,    26,
      69,   317,    69,   317,  -140,    64,   205,   248,   262,   500,
    -140,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,    58,  -140,   -32,   300,   -32,   -32,    59,
     355,  -140,  -140,  -140,  -140,  -140,  -140,    75,   -32,    60,
     -32,     2,  -140,  -140,   355,  -140,   275,   500,    43,    43,
      43,    43,    43,    43,    -1,    -1,  -140,  -140,   317,  -140,
    -140,    67,   506,  -140,  -140,  -140,   317,    81,   317,   -29,
      92,     2,  -140,   103,  -140,    74,  -140,  -140,    84,  -140,
    -140,  -140,  -140,   401,   -32,   105,   -32,   130,    37,  -140,
      69,   355,   127,  -140,  -140,  -140,  -140,  -140,  -140,    69,
      69,   424,  -140,  -140,  -140,   355,  -140,   126,  -140,   447,
    -140,  -140,  -140,   506,  -140,   470,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     4,
       6,     8,    10,    12,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,     0,     0,    16,     0,     0,
       0,    47,    48,     0,     0,   101,   102,   103,     0,     0,
      91,    44,    92,    90,    45,    88,    89,    87,     3,     5,
       7,     9,    11,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,    84,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    52,     0,    40,    41,     0,
       0,    95,    96,    97,    98,    99,   100,     0,    14,    17,
      18,    27,    42,    43,     0,    72,    86,    85,    78,    82,
      79,    81,    80,    83,    77,    76,    74,    75,     0,    49,
      94,     0,     0,    59,    57,    58,     0,     0,     0,     0,
       0,    26,    28,     0,    56,    53,    55,    51,     0,    64,
      66,    68,    70,     0,    15,     0,    19,     0,     0,    29,
       0,     0,     0,    63,    65,    67,    69,    71,    20,     0,
       0,     0,    22,    30,    54,     0,    31,     0,    23,     0,
      62,    60,    61,     0,    24,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,    45,    46,    47,   121,  -140,  -140,
    -140,  -140,     0,    33,  -140,    12,  -140,  -140,    31,    32,
    -140,    14,  -140,   -18,  -140,  -140,  -140,  -140,   -98,  -139,
     202,    -3,    -4,   -71,  -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,   149,   150,   151,    22,   111,   172,
     140,   141,   142,   152,    24,    50,    26,    51,    52,    53,
      93,    94,    29,   145,    30,   134,    31,   181,   146,   153,
      95,    55,    56,   107,    57
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       6,   109,   135,    33,    32,   139,     1,    36,    37,    38,
       4,    42,    41,    34,    33,    32,     5,    81,    82,    25,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      25,    68,   179,    70,   100,    64,     7,    65,    27,    28,
      23,   170,    71,    35,   185,    39,    72,     5,   171,    27,
      28,    63,    19,    20,    21,    73,    64,    40,    65,    91,
      92,   128,    66,    59,    60,    61,   129,    67,    43,   137,
      74,    65,   112,   138,    99,    81,    82,   182,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   136,   173,
     101,   102,   103,   104,   105,   106,    33,    32,   176,   177,
     158,    89,    90,    91,    92,   131,   148,   160,   143,   161,
      33,    32,    25,    81,    82,   168,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    25,   155,    33,    32,
     162,    27,    28,   133,   169,   175,   157,   183,   143,    62,
       0,   159,   147,   174,    25,    27,    28,   144,     0,    33,
      32,     0,     0,     0,     0,     0,     0,    33,    32,     0,
       0,     0,     0,    27,    28,    25,     0,    33,    32,     0,
       0,    33,    32,    25,     0,    33,    32,     0,     0,    33,
      32,    33,    32,    25,    27,    28,   167,    25,     0,     0,
       0,    25,    27,    28,   144,    25,     0,    25,   164,   165,
     166,     0,    27,    28,     0,     0,    27,    28,   180,     0,
      27,    28,   167,   113,    27,    28,    27,    28,   167,    54,
       0,     0,     0,     0,   164,   165,   166,     0,     0,     0,
     164,   165,   166,     0,     0,     0,     0,    69,     0,     0,
       0,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,     0,     0,    81,    82,   114,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    96,    97,    98,
     115,     0,     0,   108,     0,   110,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,     0,    81,    82,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     130,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    44,    82,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,   154,     0,
     156,     0,     0,     0,     0,     0,    13,    14,    15,    81,
      82,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     5,    45,    46,    47,   132,     0,    48,     8,
       0,     0,     9,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    15,     0,     0,    16,
      58,     0,     8,     0,     0,     9,    17,    10,    11,     0,
       5,     0,     0,     0,     0,     0,    12,    13,    14,    15,
       0,     0,    16,   163,     0,     8,     0,     0,     9,    17,
      10,    11,     0,     5,     0,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,    16,   178,     0,     8,     0,
       0,     9,    17,    10,    11,     0,     5,     0,     0,     0,
       0,     0,     0,    13,    14,    15,     0,     0,    16,   184,
       0,     8,     0,     0,     9,    17,    10,    11,     0,     5,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    16,   186,     0,     8,     0,     0,     9,    17,    10,
      11,     0,     5,     0,     0,     0,     0,     0,     0,    13,
      14,    15,     8,     0,    16,     9,     0,    10,    11,     0,
       0,    17,     0,     0,     0,     5,    12,    13,    14,    15,
       8,     0,    16,     9,     0,    10,    11,     0,     0,    17,
       0,     0,     0,     5,     0,    13,    14,    15,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     5,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92
};

static const yytype_int16 yycheck[] =
{
       3,    72,   100,     7,     7,     3,    27,    10,    11,    12,
       0,    15,    15,     7,    18,    18,    45,    49,    50,     7,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      18,    34,   171,     4,     8,     7,    11,     9,     7,     7,
       7,     4,    13,     7,   183,     7,     4,    45,    11,    18,
      18,    18,     7,     7,     7,    13,     7,     7,     9,    60,
      61,     3,    13,    18,    18,    18,     8,    13,     7,     9,
       7,     9,     8,    13,    18,    49,    50,   175,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    13,   160,
      21,    22,    23,    24,    25,    26,   100,   100,   169,   170,
       8,    58,    59,    60,    61,    46,    39,     4,   111,    35,
     114,   114,   100,    49,    50,    10,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,   114,    46,   132,   132,
      46,   100,   100,   100,     4,     8,   139,    11,   141,    18,
      -1,   141,   128,   161,   132,   114,   114,   114,    -1,   153,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   161,   161,    -1,
      -1,    -1,    -1,   132,   132,   153,    -1,   171,   171,    -1,
      -1,   175,   175,   161,    -1,   179,   179,    -1,    -1,   183,
     183,   185,   185,   171,   153,   153,   153,   175,    -1,    -1,
      -1,   179,   161,   161,   161,   183,    -1,   185,   153,   153,
     153,    -1,   171,   171,    -1,    -1,   175,   175,   175,    -1,
     179,   179,   179,     8,   183,   183,   185,   185,   185,    17,
      -1,    -1,    -1,    -1,   179,   179,   179,    -1,    -1,    -1,
     185,   185,   185,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    39,    40,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    -1,    49,    50,     8,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    65,    66,    67,
       8,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      10,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     7,    50,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    49,
      50,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    45,    46,    47,    48,    11,    -1,    51,    14,
      -1,    -1,    17,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      12,    -1,    14,    -1,    -1,    17,    41,    19,    20,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    12,    -1,    14,    -1,    -1,    17,    41,
      19,    20,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    12,    -1,    14,    -1,
      -1,    17,    41,    19,    20,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    12,
      -1,    14,    -1,    -1,    17,    41,    19,    20,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    12,    -1,    14,    -1,    -1,    17,    41,    19,
      20,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    14,    -1,    34,    17,    -1,    19,    20,    -1,
      -1,    41,    -1,    -1,    -1,    45,    28,    29,    30,    31,
      14,    -1,    34,    17,    -1,    19,    20,    -1,    -1,    41,
      -1,    -1,    -1,    45,    -1,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    64,    65,     0,    45,    94,    11,    14,    17,
      19,    20,    28,    29,    30,    31,    34,    41,    66,    67,
      68,    69,    70,    76,    77,    78,    79,    81,    82,    85,
      87,    89,    94,    95,     7,     7,    94,    94,    94,     7,
       7,    94,    95,     7,     7,    46,    47,    48,    51,    58,
      78,    80,    81,    82,    93,    94,    95,    97,    12,    67,
      68,    69,    70,    76,     7,     9,    13,    13,    94,    93,
       4,    13,     4,    13,     7,    93,    93,    93,    93,    93,
      93,    49,    50,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    83,    84,    93,    93,    93,    93,    18,
       8,    21,    22,    23,    24,    25,    26,    96,    93,    96,
      93,    71,     8,     8,     8,     8,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,     3,     8,
      10,    46,    11,    76,    88,    91,    13,     9,    13,     3,
      73,    74,    75,    94,    76,    86,    91,    84,    39,    67,
      68,    69,    76,    92,    93,    46,    93,    94,     8,    75,
       4,    35,    46,    12,    67,    68,    69,    76,    10,     4,
       4,    11,    72,    96,    86,     8,    96,    96,    12,    92,
      76,    90,    91,    11,    12,    92,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    65,    64,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    71,    70,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    85,    85,    86,    86,    87,    88,    88,
      89,    90,    90,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     4,     6,     2,     4,     4,     6,
       7,     0,     7,     2,     3,     5,     1,     0,     1,     2,
       3,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     2,     1,     0,     2,     2,     4,
       1,     3,     1,     5,     7,     1,     1,     5,     1,     1,
       9,     1,     1,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 54 "parser.y" /* yacc.c:1646  */
    {createTable();}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "parser.y" /* yacc.c:1646  */
    {
			if (main_check == 0)
				printf("doesn't have main function\n");
		 }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 74 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-2].string),(yyvsp[0].string));
			 (yyval.string) = (yyvsp[0].string);
		 }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-4].string),(yyvsp[-2].string));
			 if(strcmp((yyvsp[-2].string),(yyvsp[0].string)))
				 typeError();
			 (yyval.string) = (yyvsp[-2].string);
		 }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 86 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[0].string),"Unknown");
			 (yyval.string) = "Unknown";
		 }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-2].string),(yyvsp[0].string));
			 (yyval.string) = (yyvsp[0].string);
		 }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-2].string),(yyvsp[0].string));
			 (yyval.string) = (yyvsp[0].string);
		 }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-4].string),(yyvsp[-2].string));
			 if(strcmp((yyvsp[-2].string),(yyvsp[0].string)))
				 typeError();
			 (yyval.string) = (yyvsp[-2].string);
		 }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 106 "parser.y" /* yacc.c:1646  */
    {
			 insert(tableList,(yyvsp[-5].string),(yyvsp[-3].string));
			 (yyval.string) = (yyvsp[-3].string);
			}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "parser.y" /* yacc.c:1646  */
    {createTable();}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 116 "parser.y" /* yacc.c:1646  */
    {
				 if(strcmp((yyvsp[-5].string),"main") == 0)
					 main_check = 1;
				 temp_node = insert(tableList->pre,(yyvsp[-5].string),(yyvsp[0].string));
				 for(int i = 0; i < count; i++){
					 temp_node -> args[i] = def_func_args[i];
					 def_func_args[i] = 0;
				 }
				 count = 0;
				 printf("%s function symbol table:\n",(yyvsp[-5].string));
				 dump(tableList);
				 deleteTable();
		  }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = "Unknown";}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = "Unknown";}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-3].string);}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 142 "parser.y" /* yacc.c:1646  */
    {
				 								insert(tableList,(yyvsp[-2].string),(yyvsp[0].string));
												def_func_args[count] = type2int((yyvsp[0].string));
												count = count + 1;
		  }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "parser.y" /* yacc.c:1646  */
    {
			  											insert(tableList,(yyvsp[-2].string),(yyvsp[0].string));
														def_func_args[count] = type2int((yyvsp[0].string));
														count = count + 1;
		  }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "parser.y" /* yacc.c:1646  */
    {
				  if(lookup(tableList,(yyvsp[-2].string),0)==NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));
				  }
			  }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 175 "parser.y" /* yacc.c:1646  */
    {
				  printf("123");
				  if(lookup(tableList,(yyvsp[-2].string),0)==NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));
				  }
			  }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 198 "parser.y" /* yacc.c:1646  */
    {
				  if(lookup(tableList,(yyvsp[0].string),0) == NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  (yyval.string) = typeCheck((yyvsp[0].string));
				  }
			}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 206 "parser.y" /* yacc.c:1646  */
    {
				  if(lookup(tableList,(yyvsp[0].string),0) == NULL){
			 		  non_declaration("identifier is undeclared");
				  }
				  else{
					  (yyval.string) = typeCheck((yyvsp[0].string));
				  }
			}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 218 "parser.y" /* yacc.c:1646  */
    {
						 temp_node = lookup(tableList,(yyvsp[-3].string),0);
						 for(int i = 0 ; i < count ; i++){
							 if(temp_node->args[i] != invo_func_args[i])
								 yyerror("function invocation arguments can't match function formal parameters");
							 invo_func_args[i] = 0;
						 }
						 count = 0;
						 if(temp_node == NULL){
			 		 		 non_declaration("identifier is undeclared");
						 }
						 (yyval.string) = typeCheck((yyvsp[-3].string));
				  }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "parser.y" /* yacc.c:1646  */
    {
						if(lookup(tableList,(yyvsp[0].string),0)!=NULL){
							invo_func_args[count]=type2int(typeCheck((yyvsp[0].string)));
							count = count + 1;
						}
				 }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 248 "parser.y" /* yacc.c:1646  */
    {
				//printf("dump IF block symbol table\n");
				//dump(tableList);
				//deleteTable();
		 }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-1].string);}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 310 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 311 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.string) = type_handlier((yyvsp[-2].string),(yyvsp[0].string));}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 314 "parser.y" /* yacc.c:1646  */
    {
		 if(lookup(tableList,(yyvsp[0].string),0) == NULL){
			 non_declaration("identifier is undeclared");
		 }
		 else{
			 (yyval.string) = (yyvsp[0].string);
		 }
	 }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 322 "parser.y" /* yacc.c:1646  */
    {
		 if(lookup(tableList,(yyvsp[0].string),0) == NULL){
			 non_declaration("identifier is undeclared");
		 }
		 else{
		 	 (yyval.string) = (yyvsp[0].string);
		 }
	 }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-3].string);}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 350 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 352 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 360 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 361 "parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2017 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 364 "parser.y" /* yacc.c:1906  */

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

