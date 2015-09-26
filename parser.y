%{
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
%}

/***********************************************************************
 *  Yacc/Bison declarations.
 *  Phase 2:
 *    1. Add precedence declarations for operators (after %start declaration)
 *    2. If necessary, add %type declarations for some nonterminals
 *  Phase 3:
 *    1. Add fields to the union below to facilitate the construction of the
 *       AST (the two existing fields allow the lexical analyzer to pass back
 *       semantic info, so they shouldn't be touched).
 *    2. Add <type> modifiers to appropriate %token declarations (using the
 *       fields of the union) so that semantic information can by passed back
 *       by the scanner.
 *    3. Make the %type declarations for the language non-terminals, utilizing
 *       the fields of the union as well.
 ***********************************************************************/

%{
#define YYDEBUG 1
%}

// defines the yyval union
%union {
  int as_int;
  int as_vec;
  float as_float;
  char *as_str;
  int as_func;
  node *as_ast;
 
}
%token          WHILE
%token          FLOAT_T
%token          INT_T
%token          BOOL_T
%token          CONST
%token          FALSE_C TRUE_C
%token          FUNC
%token          IF ELSE
%token          AND OR NEQ EQ LEQ GEQ
%token          DP3_F LIT_F RSQ_F

// links specific values of tokens to yyval
%token <as_vec>   VEC2_T VEC3_T VEC4_T IVEC2_T IVEC3_T IVEC4_T BVEC2_T BVEC3_T BVEC4_T

%token <as_float> FLOAT_C
%token <as_int>   INT_C
%token <as_str>   ID

// Used for building the AST
%token EXPR DECLARE DECLARES STATEMENTS STATEMENT VARIABLE SCOPE ASSIGN
%token INTEGER BOOLEAN FLOAT DEC_SCALAR DEC_CONST
%token PARAMETERS PARAM_SCALAR
%token ARGUMENTS UNARY_MINUS LOGICAL_NOT LOGICAL_AND LOGICAL_OR CMP_EQ CMP_NE CMP_LT CMP_LE CMP_GT CMP_GE
%token IF_STMT IF_ELSE CONSTRUCTOR_CALL WHILE_LOOP PARENTHESIS
%token VEC2 VEC3 VEC4 IVEC2 IVEC3 IVEC4 BVEC2 BVEC3 BVEC4 MAT2 MAT3 MAT4 CONST_FLOAT
%token FUNCTION_CALL DP3 LIT RSQ

// operator precdence
%left     OR                        // 7
%left     AND                       // 6
%left     EQ NEQ '<' LEQ '>' GEQ    // 5
%left     '+' '-'                   // 4
%left     '*' '/'                   // 3
%right    '^'                       // 2
%right    '!' UMINUS                // 1
%left     '(' '['                   // 0

// resolve dangling else shift/reduce conflict with associativity
%left     WITHOUT_ELSE
%left     WITH_ELSE

// type declarations
// TODO: fill this out
%type <as_ast> expression declaration declarations
%type <as_ast> statements statement statement_open statement_closed
%type <as_ast> variable scope
%type <as_ast> arguments_opt arguments argument expression_opt constructor_call function_call
%type <as_int> type
%type <as_func> function_name


// expect one shift/reduce conflict, where Bison chooses to shift
// the ELSE.
%expect 1

%start    program

%%

/***********************************************************************
 *  Yacc/Bison rules
 *  Phase 2:
 *    1. Replace grammar found here with something reflecting the source
 *       language grammar
 *    2. Implement the trace parser option of the compiler
 ***********************************************************************/
program
  : scope { yTRACE("program -> scope");
             ast = $1;
                           /* ast = $1; Done building the AST, assign to root of the tree to the global var ast for future use*/
             init_table(ast->sym_table);
             semanticCheck(ast);
             printStackNodes(stack);

          }
  ;

scope
  : '{' declarations statements '}'
          {
              $$ = make_Node(28,-1,$2,$3,NULL,NULL,0,0.0,yyline);
              build_sym_table($$->sym_table, $2);
              yTRACE("scope->{declaration statement}");
              //declarationsCheck($2);
          }
  ;

declarations
  : declarations declaration {$$ = make_Node(17,-1,$1, $2, NULL, NULL, 0, 0.0, yyline);}
  | {$$ = NULL;}
  ;

declaration
  : type ID ';' { yTRACE("declaration -> type identifier"); $$ = make_Node(16,$1,NULL, NULL, NULL, $2, 0, 0.0, yyline);}

                                              
  | type ID '=' expression ';'{
                               yTRACE("declaration -> type identifier = expression");
                               $$ = make_Node(16,$1,$4, NULL, NULL, $2, 0,0.0,yyline);
                              }
                                               
  | CONST type ID '=' expression ';' {
                                        $$ = make_Node(15,$2,$5, NULL, NULL, $3, 0, 0.0, yyline);
                                        yTRACE("declaration -> const type  identifier = expression");
                                     }

  | /* empty */ ';' { 
                       $$ = NULL; yTRACE("declaration -> empty"); 
                    }
  ;

statements
  : statements statement {$$ = make_Node(18,-1,$1, $2, NULL, NULL, 0, 0.0, yyline);}
  | {$$ = NULL;}
  ;
statement
  : statement_open {$$ = $1;}
  | statement_closed {$$ = $1;}
  ;
statement_open
  : IF '(' expression ')' statement {
                                        yTRACE("statement -> if statement");
                                        $$ = make_Node(20,-1,$3, $5, NULL, NULL, 0, 0.0, yyline);
                                    }
                                             
  | IF '(' expression ')' statement_closed ELSE statement_open {
                                yTRACE("statement -> if statement");
                                $$ = make_Node(21,-1,$3, $5, $7, NULL, 0, 0.0, yyline);
                           }
                                             
  | WHILE '(' expression ')' statement_open {
                                yTRACE("statement -> while statement");
                                $$ = make_Node(22,-1,$3, $5, NULL, NULL, 0, 0.0, yyline);
                             }

  ;
statement_closed
  : variable '=' expression ';' {
                                  yTRACE("statement -> assignment");
                                  $$ = make_Node(23,-1,$1, $3, NULL, NULL, 0, 0.0, yyline);
                                }

                                                
  | scope { $$ = $1; yTRACE("statement -> scope"); }
                                               
  | WHILE '(' expression ')' statement_closed { 
                                  $$ = make_Node(25,-1,$3, $5, NULL, NULL, 0, 0.0, yyline);
                                  yTRACE("statement -> while statement"); 
                                 }
                                               
  | IF '(' expression ')' statement_closed ELSE statement_closed {
                                  yTRACE("statement -> if statement");
                                  $$ = make_Node(26,-1,$3, $5, $7, NULL, 0, 0.0, yyline);
                                 }
                                               
  | /* empty */ ';'               { $$ = NULL; yTRACE("statement -> empty");    }
                                              
  ;

arguments_opt
  : arguments {$$ = $1;}
  | {$$ = NULL;}
  ;

arguments
  : arguments ',' argument {
                             $$ = make_Node(30,-1,$1, $3, NULL, NULL, 0, 0.0, yyline);
                             $$->number_args = $1->number_args + 1;
                           }
  | argument               {
                             $$ = make_Node(30,-1,$1, NULL, NULL, NULL, 0, 0.0, yyline);
                             $$->number_args = 1; 
                           }
  ;

argument
  : expression { $$ = $1; yTRACE("argument -> expression"); }
                                              
  ;
  
expression_opt
  : expression {$$ = $1;}
  | {$$ = NULL;}
  ;
   
expression
  : INT_C { $$ = make_Node(2,-1,NULL, NULL, NULL, NULL, $1, 0.0, yyline); yTRACE("expression -> integer"); }
                                                
  | FLOAT_C { $$ = make_Node(3,-1,NULL, NULL, NULL, NULL, 0, $1, yyline); yTRACE("expression -> float"); }
                                                
  | '-' expression %prec UMINUS { $$ = make_Node(9,-1,$2, NULL, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> - expression"); }
                                               
  | expression '+' expression { $$ =make_Node(6,0,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression + expression"); }
                                               
  | expression '-' expression { $$ =make_Node(6,1,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression - expression"); }
                                               
  | expression '*' expression { $$ =make_Node(6,2,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression * expression"); }
                                               
  | expression '/' expression { $$ =make_Node(6,3,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression / expression"); }
                                              
  | expression '^' expression { $$ =make_Node(6,4,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression ^ expression"); }
                                               
  | TRUE_C { $$ =make_Node(4,-1,NULL, NULL, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> true"); }
                                              
  | FALSE_C {$$ = make_Node(5,-1,NULL, NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> false"); }
                                             
  | '!' expression { $$ =make_Node(10,-1,$2, NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> ! expression"); }
                                               
  | expression AND expression {$$ = make_Node(7,5,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression && expression"); }
                                              
  | expression OR expression {$$ = make_Node(7,6,$1, $3, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression || expression"); }
                                              
  | expression EQ expression {$$ = make_Node(8,7,$1, $3, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression == expression"); }
                                               
  | expression NEQ expression {$$ = make_Node(8,8,$1, $3, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression != expression"); }
                                              
  | expression '<' expression {$$ = make_Node(8,9,$1, $3, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression < expression"); }
                                               
  | expression LEQ expression {$$ = make_Node(8,10,$1, $3, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> expression <= expression");}
                                               
  | expression '>' expression {$$ = make_Node(8,11,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression > expression"); }
                                                
  | expression GEQ expression {$$ = make_Node(8,12,$1, $3, NULL, NULL, 0, 0.0, yyline); yTRACE("expression -> expression >= expression"); }
                                               
  | '(' expression ')' {$$ = make_Node(11,-1,$2, NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("expression -> ( expression )"); }
                                               
  | variable { $$ = $1; yTRACE("expression -> variable"); }
                                             
  | constructor_call { $$ = $1; yTRACE("expression -> constructor call"); }
                                                
  | function_call { $$ = $1; yTRACE("expression -> function call");}
                                                
  ;

variable
  : ID { $$ =make_Node(27,0,NULL, NULL, NULL, $1, 0, 0.0, yyline); yTRACE("variable -> identifier"); }
                                               
  | ID '[' INT_C ']' {$$ = make_Node(27,1,NULL, NULL, NULL, $1, $3, 0.0, yyline);yTRACE("variable -> identifier [ expression ]"); }
                                               
  ;

constructor_call
  : type '(' arguments_opt ')' {$$ = make_Node(32,$1,$3, NULL, NULL, NULL, 0, 0.0, yyline);yTRACE("constructor call -> type (arguments)");}
                                                
  ;
type
  : INT_T { $$ = 1; yTRACE("type -> integer"); }
                                               
  | BOOL_T { $$ = 2; yTRACE("type -> boolean"); }
                                               
  | FLOAT_T { $$ = 3; yTRACE("type -> float"); }
                                               
  | VEC2_T { $$ = 4; yTRACE("type -> vec2"); }
                                              
  | VEC3_T { $$ = 5; yTRACE("type -> vec3"); }
                                               
  | VEC4_T { $$ = 6; yTRACE("type -> vec4"); }
                                               
  | IVEC2_T { $$ = 7; yTRACE("type -> ivec2"); }
                                               
  | IVEC3_T { $$ = 8; yTRACE("type -> ivec3"); }
                                               
  | IVEC4_T { $$ = 9; yTRACE("type -> ivec4"); }
                                               
  | BVEC2_T { $$ = 10; yTRACE("type -> bvec2"); }
                                               
  | BVEC3_T { $$ = 11; yTRACE("type -> bvec3"); }
                                                
  | BVEC4_T { $$ = 12; yTRACE("type -> bvec4"); }
                                               

                                                
  ;
function_call
  : function_name '(' arguments_opt ')' {
                                          $$ = make_Node(33,$1,$3, NULL, NULL, NULL, 0, 0.0, yyline); 
                                          yTRACE("function call -> type (arguments)"); 
                                        }
  ;                                               
function_name
  : DP3_F { $$ = 1; yTRACE("function name -> dp3"); }
                                               
  | LIT_F { $$ = 2; yTRACE("function name-> lit"); }
                                               
  | RSQ_F { $$ = 3; yTRACE("function name-> rsq"); }
  ;                                             




%%

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

