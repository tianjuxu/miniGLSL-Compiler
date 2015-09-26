/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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

/***********************************************************************
 * --YOUR GROUP INFO SHOULD GO HERE--
 * 
 *   Interface to the parser module for CSC467 course project.
 * 
 *   Phase 2: Implement context free grammar for source language, and
 *            parse tracing functionality.
 *   Phase 3: Construct the AST for the source language program.
 ***********************************************************************/

/***********************************************************************
 *  C Definitions and external declarations for this module.
 *
 *  Phase 3: Include ast.h if needed, and declarations for other global or
 *           external vars, functions etc. as needed.
 ***********************************************************************/

#include <string.h>

#include "common.h"
#include "ast.h"
#include "symbol.h"
#include "semantic.h"

#define YYERROR_VERBOSE
#define yTRACE(x)    { if (traceParser) fprintf(traceFile, "%s\n", x); }

void yyerror(const char* s);    /* what to do in case of error            */
int yylex();              /* procedure for calling lexical analyzer */
extern int yyline;        /* variable holding current line number   */
extern node *ast;
extern stack_el *stack;
/*enum {
  DP3 = 0, 
  LIT = 1, 
  RSQ = 2
};
*/
#line 58 "parser.y" /* yacc.c:339  */

#define YYDEBUG 1

#line 110 "y.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE = 258,
    FLOAT_T = 259,
    INT_T = 260,
    BOOL_T = 261,
    CONST = 262,
    FALSE_C = 263,
    TRUE_C = 264,
    FUNC = 265,
    IF = 266,
    ELSE = 267,
    AND = 268,
    OR = 269,
    NEQ = 270,
    EQ = 271,
    LEQ = 272,
    GEQ = 273,
    DP3_F = 274,
    LIT_F = 275,
    RSQ_F = 276,
    VEC2_T = 277,
    VEC3_T = 278,
    VEC4_T = 279,
    IVEC2_T = 280,
    IVEC3_T = 281,
    IVEC4_T = 282,
    BVEC2_T = 283,
    BVEC3_T = 284,
    BVEC4_T = 285,
    FLOAT_C = 286,
    INT_C = 287,
    ID = 288,
    EXPR = 289,
    DECLARE = 290,
    DECLARES = 291,
    STATEMENTS = 292,
    STATEMENT = 293,
    VARIABLE = 294,
    SCOPE = 295,
    ASSIGN = 296,
    INTEGER = 297,
    BOOLEAN = 298,
    FLOAT = 299,
    DEC_SCALAR = 300,
    DEC_CONST = 301,
    PARAMETERS = 302,
    PARAM_SCALAR = 303,
    ARGUMENTS = 304,
    UNARY_MINUS = 305,
    LOGICAL_NOT = 306,
    LOGICAL_AND = 307,
    LOGICAL_OR = 308,
    CMP_EQ = 309,
    CMP_NE = 310,
    CMP_LT = 311,
    CMP_LE = 312,
    CMP_GT = 313,
    CMP_GE = 314,
    IF_STMT = 315,
    IF_ELSE = 316,
    CONSTRUCTOR_CALL = 317,
    WHILE_LOOP = 318,
    PARENTHESIS = 319,
    VEC2 = 320,
    VEC3 = 321,
    VEC4 = 322,
    IVEC2 = 323,
    IVEC3 = 324,
    IVEC4 = 325,
    BVEC2 = 326,
    BVEC3 = 327,
    BVEC4 = 328,
    MAT2 = 329,
    MAT3 = 330,
    MAT4 = 331,
    CONST_FLOAT = 332,
    FUNCTION_CALL = 333,
    DP3 = 334,
    LIT = 335,
    RSQ = 336,
    UMINUS = 337,
    WITHOUT_ELSE = 338,
    WITH_ELSE = 339
  };
#endif
/* Tokens.  */
#define WHILE 258
#define FLOAT_T 259
#define INT_T 260
#define BOOL_T 261
#define CONST 262
#define FALSE_C 263
#define TRUE_C 264
#define FUNC 265
#define IF 266
#define ELSE 267
#define AND 268
#define OR 269
#define NEQ 270
#define EQ 271
#define LEQ 272
#define GEQ 273
#define DP3_F 274
#define LIT_F 275
#define RSQ_F 276
#define VEC2_T 277
#define VEC3_T 278
#define VEC4_T 279
#define IVEC2_T 280
#define IVEC3_T 281
#define IVEC4_T 282
#define BVEC2_T 283
#define BVEC3_T 284
#define BVEC4_T 285
#define FLOAT_C 286
#define INT_C 287
#define ID 288
#define EXPR 289
#define DECLARE 290
#define DECLARES 291
#define STATEMENTS 292
#define STATEMENT 293
#define VARIABLE 294
#define SCOPE 295
#define ASSIGN 296
#define INTEGER 297
#define BOOLEAN 298
#define FLOAT 299
#define DEC_SCALAR 300
#define DEC_CONST 301
#define PARAMETERS 302
#define PARAM_SCALAR 303
#define ARGUMENTS 304
#define UNARY_MINUS 305
#define LOGICAL_NOT 306
#define LOGICAL_AND 307
#define LOGICAL_OR 308
#define CMP_EQ 309
#define CMP_NE 310
#define CMP_LT 311
#define CMP_LE 312
#define CMP_GT 313
#define CMP_GE 314
#define IF_STMT 315
#define IF_ELSE 316
#define CONSTRUCTOR_CALL 317
#define WHILE_LOOP 318
#define PARENTHESIS 319
#define VEC2 320
#define VEC3 321
#define VEC4 322
#define IVEC2 323
#define IVEC3 324
#define IVEC4 325
#define BVEC2 326
#define BVEC3 327
#define BVEC4 328
#define MAT2 329
#define MAT3 330
#define MAT4 331
#define CONST_FLOAT 332
#define FUNCTION_CALL 333
#define DP3 334
#define LIT 335
#define RSQ 336
#define UMINUS 337
#define WITHOUT_ELSE 338
#define WITH_ELSE 339

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 63 "parser.y" /* yacc.c:355  */

  int as_int;
  int as_vec;
  float as_float;
  char *as_str;
  int as_func;
  node *as_ast;
 

#line 328 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 343 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   321

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,     2,     2,     2,
      91,    99,    86,    84,   100,    85,     2,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    97,
      82,    98,    83,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,   101,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    95,     2,    96,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    90,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   150,   160,   161,   165,   168,   173,   178,
     184,   185,   188,   189,   192,   197,   202,   209,   215,   217,
     222,   227,   232,   233,   237,   241,   248,   258,   260,   262,
     264,   266,   268,   270,   272,   274,   276,   278,   280,   282,
     284,   286,   288,   290,   292,   294,   296,   298,   300,   302,
     307,   309,   314,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   338,   340,   346,   352,   354,   356
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "FLOAT_T", "INT_T", "BOOL_T",
  "CONST", "FALSE_C", "TRUE_C", "FUNC", "IF", "ELSE", "AND", "OR", "NEQ",
  "EQ", "LEQ", "GEQ", "DP3_F", "LIT_F", "RSQ_F", "VEC2_T", "VEC3_T",
  "VEC4_T", "IVEC2_T", "IVEC3_T", "IVEC4_T", "BVEC2_T", "BVEC3_T",
  "BVEC4_T", "FLOAT_C", "INT_C", "ID", "EXPR", "DECLARE", "DECLARES",
  "STATEMENTS", "STATEMENT", "VARIABLE", "SCOPE", "ASSIGN", "INTEGER",
  "BOOLEAN", "FLOAT", "DEC_SCALAR", "DEC_CONST", "PARAMETERS",
  "PARAM_SCALAR", "ARGUMENTS", "UNARY_MINUS", "LOGICAL_NOT", "LOGICAL_AND",
  "LOGICAL_OR", "CMP_EQ", "CMP_NE", "CMP_LT", "CMP_LE", "CMP_GT", "CMP_GE",
  "IF_STMT", "IF_ELSE", "CONSTRUCTOR_CALL", "WHILE_LOOP", "PARENTHESIS",
  "VEC2", "VEC3", "VEC4", "IVEC2", "IVEC3", "IVEC4", "BVEC2", "BVEC3",
  "BVEC4", "MAT2", "MAT3", "MAT4", "CONST_FLOAT", "FUNCTION_CALL", "DP3",
  "LIT", "RSQ", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'^'", "'!'",
  "UMINUS", "'('", "'['", "WITHOUT_ELSE", "WITH_ELSE", "'{'", "'}'", "';'",
  "'='", "')'", "','", "']'", "$accept", "program", "scope",
  "declarations", "declaration", "statements", "statement",
  "statement_open", "statement_closed", "arguments_opt", "arguments",
  "argument", "expression", "variable", "constructor_call", "type",
  "function_call", "function_name", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,    60,    62,    43,    45,    42,    47,    94,    33,
     337,    40,    91,   338,   339,   123,   125,    59,    61,    41,
      44,    93
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -94,   -95,     4,   -95,    12,   -95,   -95,   -95,   -95,   231,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,    -3,   -27,   -13,   -70,   -68,   -66,   -95,   -95,   -95,
     -95,   -95,   -95,   -71,   -88,   -69,    49,    49,    -8,    49,
     -95,    49,    49,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
      49,    49,    49,    30,   -95,   -95,   -63,   -95,   -60,    70,
     -51,   106,   128,   146,   -95,   -95,    88,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       0,    49,    49,     0,   -95,   -95,   -95,   -95,   -95,   189,
     182,   -25,   -25,   -25,   -25,   -25,   -25,   -74,   -74,   -56,
     -56,   -56,   -95,   -95,   -48,   -35,   -95,   164,   -47,   -95,
      54,   -95,    49,   -95,     0,   -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,    11,     1,    55,    53,    54,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     9,
       4,     0,     0,     0,     0,     0,    50,     3,    21,    18,
      10,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       6,     0,     0,    36,    35,    66,    67,    68,    28,    27,
       0,     0,     0,     0,    47,    48,     0,    49,     0,     0,
       0,     0,     0,     0,    29,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    23,     0,    51,    17,     7,     8,    46,    38,
      39,    41,    40,    43,    45,    42,    44,    30,    31,    32,
      33,    34,    16,    19,     0,    22,    25,    26,     0,    14,
      13,    52,     0,    65,     0,    24,    15,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,    89,   -95,   -95,   -95,     7,   -65,   -58,     9,
     -95,   -12,   242,   -16,   -95,    -2,   -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    29,     4,    20,    21,    30,    31,    32,   104,
     105,   106,   107,    54,    55,    56,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,     1,    22,    24,     5,    33,    34,    23,    25,    40,
      41,    25,    77,    78,    79,   102,     6,     7,     8,     9,
      35,    36,   103,    37,    60,   110,    38,    39,    81,    42,
      26,    82,    79,    26,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    67,    68,    69,    70,    71,    72,   116,
      84,   111,   113,     6,     7,     8,   117,    43,    44,    75,
      76,    77,    78,    79,    33,   112,   114,    33,    45,    46,
      47,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      48,    49,    26,    67,    68,    69,    70,    71,    72,     3,
     109,   108,     1,    27,    28,     1,     0,    28,    33,     0,
     115,    67,    68,    69,    70,    71,    72,     0,     0,    19,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,    80,
       0,     0,     0,     0,    50,     0,     0,     0,    51,     0,
      52,    67,    68,    69,    70,    71,    72,     0,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,    83,
      73,    74,    75,    76,    77,    78,    79,    67,    68,    69,
      70,    71,    72,     0,     0,     0,     0,    88,    73,    74,
      75,    76,    77,    78,    79,    67,     0,    69,    70,    71,
      72,     0,     0,    85,    69,    70,    71,    72,     0,     0,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,    73,    74,
      75,    76,    77,    78,    79,     6,     7,     8,     0,     0,
       0,     0,     0,    87,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    73,    74,    75,    76,    77,    78,    79,    53,    59,
       0,    61,     0,    62,    63,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101
};

static const yytype_int8 yycheck[] =
{
       3,    95,     4,     3,     0,    21,    33,     9,    11,    97,
      98,    11,    86,    87,    88,    80,     4,     5,     6,     7,
      33,    91,    80,    91,    32,    83,    92,    98,    91,    98,
      33,    91,    88,    33,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    13,    14,    15,    16,    17,    18,   114,
     101,    99,    99,     4,     5,     6,   114,     8,     9,    84,
      85,    86,    87,    88,    80,   100,    12,    83,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    13,    14,    15,    16,    17,    18,     0,
      83,    82,    95,    96,    97,    95,    -1,    97,   114,    -1,
     112,    13,    14,    15,    16,    17,    18,    -1,    -1,    97,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,
      91,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    99,
      82,    83,    84,    85,    86,    87,    88,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    99,    82,    83,
      84,    85,    86,    87,    88,    13,    -1,    15,    16,    17,
      18,    -1,    -1,    97,    15,    16,    17,    18,    -1,    -1,
      82,    83,    84,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    82,    83,    84,    85,    86,    87,
      88,    82,    83,    84,    85,    86,    87,    88,    36,    37,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,   103,   104,   105,     0,     4,     5,     6,     7,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    97,
     106,   107,   117,   117,     3,    11,    33,    96,    97,   104,
     108,   109,   110,   115,    33,    33,    91,    91,    92,    98,
      97,    98,    98,     8,     9,    19,    20,    21,    31,    32,
      85,    89,    91,   114,   115,   116,   117,   118,   119,   114,
      32,   114,   114,   114,   114,   114,   114,    13,    14,    15,
      16,    17,    18,    82,    83,    84,    85,    86,    87,    88,
      99,    91,    91,    99,   101,    97,    97,    97,    99,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   109,   110,   111,   112,   113,   114,   111,   108,
     110,    99,   100,    99,    12,   113,   109,   110
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   105,   105,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     0,     3,     5,     6,     1,
       2,     0,     1,     1,     5,     7,     5,     4,     1,     5,
       7,     1,     1,     0,     3,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1
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
#line 139 "parser.y" /* yacc.c:1646  */
    { yTRACE("program -> scope");
             ast = (yyvsp[0].as_ast);
                           /* ast = $1; Done building the AST, assign to root of the tree to the global var ast for future use*/
             init_table(ast->sym_table);
             semanticCheck(ast);
             printStackNodes(stack);

          }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 151 "parser.y" /* yacc.c:1646  */
    {
              (yyval.as_ast) = make_Node(28,-1,(yyvsp[-2].as_ast),(yyvsp[-1].as_ast),NULL,NULL,0,0.0,yyline);
              build_sym_table((yyval.as_ast)->sym_table, (yyvsp[-2].as_ast));
              yTRACE("scope->{declaration statement}");
              //declarationsCheck($2);
          }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(17,-1,(yyvsp[-1].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = NULL;}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 165 "parser.y" /* yacc.c:1646  */
    { yTRACE("declaration -> type identifier"); (yyval.as_ast) = make_Node(16,(yyvsp[-2].as_int),NULL, NULL, NULL, (yyvsp[-1].as_str), 0, 0.0, yyline);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "parser.y" /* yacc.c:1646  */
    {
                               yTRACE("declaration -> type identifier = expression");
                               (yyval.as_ast) = make_Node(16,(yyvsp[-4].as_int),(yyvsp[-1].as_ast), NULL, NULL, (yyvsp[-3].as_str), 0,0.0,yyline);
                              }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 173 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.as_ast) = make_Node(15,(yyvsp[-4].as_int),(yyvsp[-1].as_ast), NULL, NULL, (yyvsp[-3].as_str), 0, 0.0, yyline);
                                        yTRACE("declaration -> const type  identifier = expression");
                                     }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 178 "parser.y" /* yacc.c:1646  */
    { 
                       (yyval.as_ast) = NULL; yTRACE("declaration -> empty"); 
                    }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(18,-1,(yyvsp[-1].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = NULL;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = (yyvsp[0].as_ast);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = (yyvsp[0].as_ast);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 192 "parser.y" /* yacc.c:1646  */
    {
                                        yTRACE("statement -> if statement");
                                        (yyval.as_ast) = make_Node(20,-1,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);
                                    }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "parser.y" /* yacc.c:1646  */
    {
                                yTRACE("statement -> if statement");
                                (yyval.as_ast) = make_Node(21,-1,(yyvsp[-4].as_ast), (yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, 0, 0.0, yyline);
                           }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 202 "parser.y" /* yacc.c:1646  */
    {
                                yTRACE("statement -> while statement");
                                (yyval.as_ast) = make_Node(22,-1,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);
                             }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 209 "parser.y" /* yacc.c:1646  */
    {
                                  yTRACE("statement -> assignment");
                                  (yyval.as_ast) = make_Node(23,-1,(yyvsp[-3].as_ast), (yyvsp[-1].as_ast), NULL, NULL, 0, 0.0, yyline);
                                }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = (yyvsp[0].as_ast); yTRACE("statement -> scope"); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 217 "parser.y" /* yacc.c:1646  */
    { 
                                  (yyval.as_ast) = make_Node(25,-1,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);
                                  yTRACE("statement -> while statement"); 
                                 }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 222 "parser.y" /* yacc.c:1646  */
    {
                                  yTRACE("statement -> if statement");
                                  (yyval.as_ast) = make_Node(26,-1,(yyvsp[-4].as_ast), (yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, 0, 0.0, yyline);
                                 }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = NULL; yTRACE("statement -> empty");    }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = (yyvsp[0].as_ast);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = NULL;}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "parser.y" /* yacc.c:1646  */
    {
                             (yyval.as_ast) = make_Node(30,-1,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);
                             (yyval.as_ast)->number_args = (yyvsp[-2].as_ast)->number_args + 1;
                           }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 241 "parser.y" /* yacc.c:1646  */
    {
                             (yyval.as_ast) = make_Node(30,-1,(yyvsp[0].as_ast), NULL, NULL, NULL, 0, 0.0, yyline);
                             (yyval.as_ast)->number_args = 1; 
                           }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = (yyvsp[0].as_ast); yTRACE("argument -> expression"); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = make_Node(2,-1,NULL, NULL, NULL, NULL, (yyvsp[0].as_int), 0.0, yyline); yTRACE("expression -> integer"); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = make_Node(3,-1,NULL, NULL, NULL, NULL, 0, (yyvsp[0].as_float), yyline); yTRACE("expression -> float"); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = make_Node(9,-1,(yyvsp[0].as_ast), NULL, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> - expression"); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(6,0,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression + expression"); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(6,1,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression - expression"); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(6,2,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression * expression"); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(6,3,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression / expression"); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(6,4,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression ^ expression"); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(4,-1,NULL, NULL, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> true"); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(5,-1,NULL, NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> false"); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(10,-1,(yyvsp[0].as_ast), NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> ! expression"); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(7,5,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression && expression"); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(7,6,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression || expression"); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,7,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression == expression"); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,8,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression != expression"); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,9,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression < expression"); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,10,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression <= expression");}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,11,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression > expression"); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(8,12,(yyvsp[-2].as_ast), (yyvsp[0].as_ast), NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression >= expression"); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(11,-1,(yyvsp[-1].as_ast), NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> ( expression )"); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = (yyvsp[0].as_ast); yTRACE("expression -> variable"); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = (yyvsp[0].as_ast); yTRACE("expression -> constructor call"); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) = (yyvsp[0].as_ast); yTRACE("expression -> function call");}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.as_ast) =make_Node(27,0,NULL, NULL, NULL, (yyvsp[0].as_str), 0, 0.0, yyline); yTRACE("variable -> identifier"); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 309 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(27,1,NULL, NULL, NULL, (yyvsp[-3].as_str), (yyvsp[-1].as_int), 0.0, yyline);yTRACE("variable -> identifier [ expression ]"); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.as_ast) = make_Node(32,(yyvsp[-3].as_int),(yyvsp[-1].as_ast), NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("constructor call -> type (arguments)");}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 1; yTRACE("type -> integer"); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 2; yTRACE("type -> boolean"); }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 3; yTRACE("type -> float"); }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 4; yTRACE("type -> vec2"); }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 5; yTRACE("type -> vec3"); }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 6; yTRACE("type -> vec4"); }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 330 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 7; yTRACE("type -> ivec2"); }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 8; yTRACE("type -> ivec3"); }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 9; yTRACE("type -> ivec4"); }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 10; yTRACE("type -> bvec2"); }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 11; yTRACE("type -> bvec3"); }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.as_int) = 12; yTRACE("type -> bvec4"); }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 346 "parser.y" /* yacc.c:1646  */
    {
                                          (yyval.as_ast) = make_Node(33,(yyvsp[-3].as_func),(yyvsp[-1].as_ast), NULL, NULL, NULL, 0, 0.0, yyline); 
                                          yTRACE("function call -> type (arguments)"); 
                                        }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.as_func) = 1; yTRACE("function name -> dp3"); }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.as_func) = 2; yTRACE("function name-> lit"); }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval.as_func) = 3; yTRACE("function name-> rsq"); }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2007 "y.tab.c" /* yacc.c:1646  */
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
#line 362 "parser.y" /* yacc.c:1906  */


/***********************************************************************ol
 * Extra C code.
 *
 * The given yyerror function should not be touched. You may add helper
 * functions as necessary in subsequent phases.
 ***********************************************************************/
void yyerror(const char* s) {
  if(errorOccurred) {
    return;    /* Error has already been reported by scanner */
  } else {
    errorOccurred = 1;
  }

  fprintf(errorFile, "\nPARSER ERROR, LINE %d", yyline);
  
  if(strcmp(s, "parse error")) {
    if(strncmp(s, "parse error, ", 13)) {
      fprintf(errorFile, ": %s\n", s);
    } else {
      fprintf(errorFile, ": %s\n", s+13);
    }
  } else {
    fprintf(errorFile, ": Reading token %s\n", yytname[YYTRANSLATE(yychar)]);
  }
}

