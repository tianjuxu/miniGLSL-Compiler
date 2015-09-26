/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 63 "parser.y" /* yacc.c:1909  */

  int as_int;
  int as_vec;
  float as_float;
  char *as_str;
  int as_func;
  node *as_ast;
 

#line 232 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
