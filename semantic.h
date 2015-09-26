#ifndef _SEMANTIC_H
#define _SEMANTIC_H

#include "ast.h"
#include "symbol.h"
#include "Codegen.h"


int semanticCheck( node *ast);

int declarations_Check(node *ast);

int statementsCheck(node * stmts);

int assignmentCheck(node * assgn);

int constructorCheck(node * con, char* temp);

D_Type functionCheck(node * func);

D_Type argumentsCheck(node * args);

int isInBound(int var, int lowb, int highb);

D_Type variableCheck(node * var);

node* parenthesis_recursion_check(node* exp);

D_Type expressionCheck(node * exp, char * result_reg);

#endif


