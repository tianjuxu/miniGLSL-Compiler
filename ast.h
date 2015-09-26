
#ifndef AST_H_
#define AST_H_ 1

#include <stdarg.h>

// Dummy node just so everything compiles, create your own node/nodes
//
// The code provided below is an example ONLY. You can use/modify it,
// but do not assume that it is correct or complete.
//
// There are many ways of making AST nodes. The approach below is an example
// of a descriminated union. If you choose to use C++, then I suggest looking
// into inheritance.

// forward declare
/*struct node_;
typedef struct node_ node;
extern node *ast;

typedef enum {
  UNKNOWN               = 0,

  SCOPE_NODE            = (1 << 0),
  
  EXPRESSION_NODE       = (1 << 2),
  UNARY_EXPRESION_NODE  = (1 << 2) | (1 << 3),
  BINARY_EXPRESSION_NODE= (1 << 2) | (1 << 4),
  INT_NODE              = (1 << 2) | (1 << 5), 
  FLOAT_NODE            = (1 << 2) | (1 << 6),
  IDENT_NODE            = (1 << 2) | (1 << 7),
  VAR_NODE              = (1 << 2) | (1 << 8),
  FUNCTION_NODE         = (1 << 2) | (1 << 9),
  CONSTRUCTOR_NODE      = (1 << 2) | (1 << 10),

  STATEMENT_NODE        = (1 << 1),
  IF_STATEMENT_NODE     = (1 << 1) | (1 << 11),
  WHILE_STATEMENT_NODE  = (1 << 1) | (1 << 12),
  ASSIGNMENT_NODE       = (1 << 1) | (1 << 13),
  NESTED_SCOPE_NODE     = (1 << 1) | (1 << 14),

  DECLARATION_NODE      = (1 << 15)
} node_kind;

struct node_ {

  // an example of tagging each node with a type
  node_kind kind;

  union {
    struct {
      // declarations?
      // statements?
    } scope;
  
    struct {
      int op;
      node *right;
    } unary_expr;

    struct {
      int op;
      node *left;
      node *right;
    } binary_expr;

    // etc.
  };
};

node *ast_allocate(node_kind type, ...);
void ast_free(node *ast);
void ast_print(node * ast);*/
enum Node_Type{
invalid, // 0
expression_opt,	// 1
expression_INT_C,	// 2
expression_FLOAT_C, // 3
expression_TRUE_T, // 4
expression_FALSE_T, // 5
expression_Binary_Math, // 6
expression_Binary_Logic, // 7
expression_Comparison, // 8
expression_Unary_Minus,	// 9
expression_Logical_Not,	// 10
expression_Parenthesis, // 11
expression_Constructor_Call, // 12
expression_Function_Call,	// 13
expression_Variable,	// 14
declaration_CONST, // 15
declaration_VAR, // 16
declarations,	// 17
statements, // 18
statement, // 19
statement_open_IF, // 20
statement_open_IF_ELSE, // 21
statement_open_WHILE, // 22
statement_closed_ASSG, // 23
statement_closed_SCOPE, // 24
statement_closed_WHILE, // 25
statement_closed_IF_ELSE,	// 26
variable, // 27
scope, // 28
arguments_opt, // 29
arguments, // 30
argument, // 31
constructor_call, // 32
function_call // 33
};

enum D_Type{
integer_t,	// 1
boolean_t,	// 2
float_c,	// 3
vec2_t,	// 4
vec3_t,	// 5
vec4_t,	// 6
ivec2_t, // 7
ivec3_t,	// 8
ivec4_t,	// 9
bvec2_t,	// 10
bvec3_t, // 11
bvec4_t, // 12
invalid_d_type
};

enum F_Type{
dp3_f,	// 1
lit_f,	// 2
rsq_f	// 3
};

enum Expression_Type{
add, // 0
subtract, // 1
multiply, // 2
divide, // 3
exponent,	// 4
logical_and, // 5
logical_or, // 6
logical_eq, // 7
logical_neq, // 8
logical_le, // 9
logical_leq, // 10
logical_ge, // 11
logical_geq	// 12
};

enum Variable_Type{
scalar, vector
};

// Dummy node just so everything compiles, create your own node/nodes
typedef struct mynode {

    Node_Type node_type;
    D_Type d_type;
    F_Type f_type;
    Expression_Type exp_type;
    Variable_Type var_type;

    char *identifier;
    int integer;
    float floating_point;

    struct mynode *child1;
    struct mynode *child2;
    struct mynode *child3;

    struct symrec *sym_table;

    int line_number;
    char *label;
    char *label_2;
    int number_args;
} node;



node *make_Node(int type, int type_2, node * child1, node * child2, node * child3, char * string_data, int integer_data, float decimal_data, int line);

void freeAST(node * ast);
void printAST(node * ast);
int printTree (node * t, int depth);



#endif /* AST_H_ */
