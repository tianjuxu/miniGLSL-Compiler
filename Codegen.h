#ifndef _GEN_H
#define _GEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "common.h"




#define C_TRUE 1.0
#define C_FALSE -1.0




void process_ArithmeticOp(enum Expression_Type op, char* input1, char* input2, char* result);
void process_BinaryOp(enum Expression_Type op, char * input1, char * input2, char * result);
void process_CompareOp(enum Expression_Type op, char * input1, char * input2, char * result);
void process_NegateOp(char * input1, char * result);
void process_NotOp(char * input1, char * result);
void process_MoveOp(char * input1, char * result);

char* create_constant(float ,float,float,float);
int create_var_register(char* , float ,float ,float ,float );
char* allocate_temp_reg(float ,float ,float ,float );
void free_temp_reg(char* );

#endif
