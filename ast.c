#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#include "ast.h"
#include "common.h"
#include "parser.tab.h"

#define DEBUG_PRINT_TREE 0

node *make_Node(int type, int type_2, node * child1, node * child2, node * child3, char * string_data, int integer_data, float decimal_data, int line){
     // Allocate space for the node, set the node type and assign the corresponding fields accordingly

     node * current_node = (node *) malloc(sizeof(node));
     current_node->label = (char *) malloc(255);
     current_node->label_2 = (char *) malloc(255);

     strcpy(current_node->label,"");
     strcpy(current_node->label_2,"");


     enum D_Type decl_type;
     enum Expression_Type expression_type;
     enum F_Type function_type;
     enum Node_Type node_type;
     enum Variable_Type var_type;

     //Node_Type for type
     switch (type){
        case 0: node_type = invalid ;
                strcpy(current_node->label,"invalid");
        break; // 0
        case 1: node_type = expression_opt ;
                strcpy(current_node->label,"expression_opt");
        break; // 1
        case 2: node_type = expression_INT_C ;
                strcpy(current_node->label,"INT_CONSTANT");
        break; // 2
        case 3: node_type = expression_FLOAT_C ;
                strcpy(current_node->label,"FLOAT_CONSTANT");
        break; // 3
        case 4: node_type = expression_TRUE_T ;
                strcpy(current_node->label,"TRUE_TERMINAL");
        break; // 4
        case 5: node_type = expression_FALSE_T ;
                strcpy(current_node->label,"FALSE_TERMINAL");
        break; // 5
        case 6: node_type = expression_Binary_Math ;
                strcpy(current_node->label,"BINARY_MATH");
                   switch (type_2){
                       case 0: expression_type = add ;
                               strcpy(current_node->label_2,"ADD");
                       break; // 0
                       case 1: expression_type = subtract ;
                               strcpy(current_node->label_2,"SUBTRACT");
                       break; // 1
                       case 2: expression_type = multiply ;
                               strcpy(current_node->label_2,"MULTIPLY");
                       break; // 2
                       case 3: expression_type = divide ;
                               strcpy(current_node->label_2,"DIVIDE");
                       break; // 3
                       case 4: expression_type = exponent ;
                               strcpy(current_node->label_2,"EXPONENT");
                       break; // 4
                    }
         break; // 6
         case 7: node_type = expression_Binary_Logic ;
                 strcpy(current_node->label,"BINARY_LOGIC");
                   switch (type_2){
                      case 5: expression_type = logical_and ;
                              strcpy(current_node->label_2,"AND");
                      break; // 5
                      case 6: expression_type = logical_or ;
                              strcpy(current_node->label_2,"OR");
                      break; // 6

                      strcpy(current_node->label_2,"");
                      break;
                    }
         break; // 7
         case 8: node_type = expression_Comparison ;
                 strcpy(current_node->label,"COMPARISON");
                   switch (type_2){
                     case 7: expression_type = logical_eq ;
                             strcpy(current_node->label_2,"EQ");
                     break; // 7
                     case 8: expression_type = logical_neq ;
                             strcpy(current_node->label_2,"NEQ");
                     break; // 8
                     case 9: expression_type = logical_le ;
                              strcpy(current_node->label_2,"LE");
                     break; // 9
                     case 10: expression_type = logical_leq ;
                              strcpy(current_node->label_2,"LEQ");
                     break; // 10
                     case 11: expression_type = logical_ge ;
                              strcpy(current_node->label_2,"GE");
                     break; // 11
                     case 12: expression_type = logical_geq ;
                              strcpy(current_node->label_2,"GEQ");
                     break; // 12
                    }
          break; // 8
          case 9: node_type = expression_Unary_Minus ;
                  strcpy(current_node->label,"UNARY_MINUS");
          break; // 9
          case 10: node_type = expression_Logical_Not ;
                   strcpy(current_node->label,"Logical_Not");
          break; // 10
          case 11: node_type = expression_Parenthesis ;
                   strcpy(current_node->label,"PARENTHESIS");
          break; // 11
          case 12: node_type = expression_Constructor_Call ;
                   strcpy(current_node->label,"CONSTRUCTOR_CALL");
          break; // 12
          case 13: node_type = expression_Function_Call ;
                   strcpy(current_node->label,"FUNCTION_CALL");
          break; // 13
          case 14: node_type = expression_Variable ;
                   strcpy(current_node->label,"VARIABLE");
          break; // 14
          case 15: node_type = declaration_CONST ;
                   strcpy(current_node->label,"CONSTANT");
                   switch (type_2){
                            case 1: decl_type = integer_t ;
                                    strcpy(current_node->label_2,"INT_T");
                            break; // 1
                            case 2: decl_type = boolean_t ;
                                    strcpy(current_node->label_2,"BOOL_T");
                            break; // 2
                            case 3: decl_type = float_c ;
                                    strcpy(current_node->label_2,"FLOAT_T");
                            break; // 3
                            case 4: decl_type = vec2_t ;
                                    strcpy(current_node->label_2,"VEC2_T");
                            break; // 4
                            case 5: decl_type = vec3_t ;
                                    strcpy(current_node->label_2,"VEC3_T");
                            break; // 5
                            case 6: decl_type = vec4_t ;
                                    strcpy(current_node->label_2,"VEC4_T");
                            break; // 6
                            case 7: decl_type = ivec2_t ;
                                    strcpy(current_node->label_2,"IVEC2_T");
                            break; // 7
                            case 8: decl_type = ivec3_t ;
                                    strcpy(current_node->label_2,"IVEC3_T");
                            break; // 8
                            case 9: decl_type = ivec4_t ;
                                    strcpy(current_node->label_2,"IVEC4_T");
                            break; // 9
                            case 10: decl_type = bvec2_t ;
                                     strcpy(current_node->label_2,"BVEC2_T");
                            break; // 10
                            case 11: decl_type = bvec3_t ;
                                     strcpy(current_node->label_2,"BVEC3_T");
                            break; // 11
                            case 12: decl_type = bvec4_t ;
                                     strcpy(current_node->label_2,"BVEC4_T");
                            break; // 12
                            strcpy(current_node->label_2,"");
                            break;
                      }
         break; // 15
         case 16: node_type = declaration_VAR ;
                  strcpy(current_node->label,"VARIABLE");
                  switch (type_2){
                      case 1: decl_type = integer_t ;
                              strcpy(current_node->label_2,"INT_T");
                      break; // 1
                      case 2: decl_type = boolean_t ;
                              strcpy(current_node->label_2,"BOOL_T");
                      break; // 2
                      case 3: decl_type = float_c ;
                              strcpy(current_node->label_2,"FLOAT_T");
                      break; // 3
                      case 4: decl_type = vec2_t ;
                              strcpy(current_node->label_2,"VEC2_T");
                      break; // 4
                      case 5: decl_type = vec3_t ;
                              strcpy(current_node->label_2,"VEC3_T");
                      break; // 5
                      case 6: decl_type = vec4_t ;
                              strcpy(current_node->label_2,"VEC4_T");
                      break; // 6
                      case 7: decl_type = ivec2_t ;
                              strcpy(current_node->label_2,"IVEC2_T");
                      break; // 7
                      case 8: decl_type = ivec3_t ;
                              strcpy(current_node->label_2,"IVEC3_T");
                      break; // 8
                      case 9: decl_type = ivec4_t ;
                              strcpy(current_node->label_2,"IVEC4_T");
                      break; // 9
                      case 10: decl_type = bvec2_t ;
                               strcpy(current_node->label_2,"BVEC2_T");
                      break; // 10
                      case 11: decl_type = bvec3_t ;
                               strcpy(current_node->label_2,"BVEC3_T");
                      break; // 11
                      case 12: decl_type = bvec4_t ;
                      strcpy(current_node->label_2,"BVEC4_T");
                      break; // 12
                      strcpy(current_node->label_2,"");
                      break;
                   }
                 break; // 16
         case 17: node_type = declarations ;
                  strcpy(current_node->label,"DECLARATIONS");
         break; // 17
         case 18: node_type = statements ;
                  strcpy(current_node->label,"STATEMENTS");
         break; // 18
         case 19: node_type = statement ;
                  strcpy(current_node->label,"STATEMENT");
         break; // 19
         case 20: node_type = statement_open_IF ;
                  strcpy(current_node->label,"IF");
         break; // 20
         case 21: node_type = statement_open_IF_ELSE ;
                  strcpy(current_node->label,"IF_ELSE");
         break; // 21
         case 22: node_type = statement_open_WHILE ;
                  strcpy(current_node->label,"WHILE LOOP");
         break; // 22
         case 23: node_type = statement_closed_ASSG ;
                  strcpy(current_node->label,"ASSIGNMENT");
         break; // 23
         case 24: node_type = statement_closed_SCOPE ;
                  strcpy(current_node->label,"SCOPE");
         break; // 24
         case 25: node_type = statement_closed_WHILE ;
                  strcpy(current_node->label,"WHILE LOOP");
         break; // 25
         case 26: node_type = statement_closed_IF_ELSE ;
                  strcpy(current_node->label,"IF ELSE");
         break; // 26
         case 27: node_type = variable ;
                  strcpy(current_node->label,"VARIABLE");
                     switch (type_2){
                           case 0: var_type = scalar ;
                                   strcpy(current_node->label_2,"SCALAR");
                           break;
                           case 1: var_type = vector ;
                                   strcpy(current_node->label_2,"VECTOR");
                           break;
                       }
         break; // 27
         case 28: node_type = scope;
                  strcpy(current_node->label, "SCOPE");
         break; // 28
         case 29: node_type = arguments_opt ;
                  strcpy(current_node->label,"ARGUMENTS_OPT");
         break; // 29
         case 30: node_type = arguments ;
                  strcpy(current_node->label,"ARGUMENTS");
         break; // 30
         case 31: node_type = argument ;
                  strcpy(current_node->label,"ARGUMENT");
         break; // 31
         case 32: node_type = constructor_call ;
                  strcpy(current_node->label,"CONSTRUCTOR_CALL");
                     switch (type_2){
                           case 1: decl_type = integer_t ;
                                   strcpy(current_node->label_2,"INT_T");
                           break; // 1
                           case 2: decl_type = boolean_t ;
                                   strcpy(current_node->label_2,"BOOL_T");
                           break; // 2
                           case 3: decl_type = float_c ;
                                   strcpy(current_node->label_2,"FLOAT_T");
                           break; // 3
                           case 4: decl_type = vec2_t ;
                                   strcpy(current_node->label_2,"VEC2_T");
                           break; // 4
                           case 5: decl_type = vec3_t ;
                                   strcpy(current_node->label_2,"VEC3_T");
                           break; // 5
                           case 6: decl_type = vec4_t ;
                                   strcpy(current_node->label_2,"VEC4_T");
                           break; // 6
                           case 7: decl_type = ivec2_t ;
                                   strcpy(current_node->label_2,"IVEC2_T");
                           break; // 7
                           case 8: decl_type = ivec3_t ;
                                   strcpy(current_node->label_2,"IVEC3_T");
                           break; // 8
                           case 9: decl_type = ivec4_t ;
                           strcpy(current_node->label_2,"IVEC4_T");
                           break; // 9
                           case 10: decl_type = bvec2_t ;
                                    strcpy(current_node->label_2,"BVEC2_T");
                           break; // 10
                           case 11: decl_type = bvec3_t ;
                                    strcpy(current_node->label_2,"BVEC3_T");
                           break; // 11
                           case 12: decl_type = bvec4_t ;
                                    strcpy(current_node->label_2,"BVEC4_T");
                           break; // 12
                           strcpy(current_node->label_2,"");
                           break;
                     }
          break; // 32
          case 33: node_type = function_call ;
                   strcpy(current_node->label,"FUNCTION_CALL");
                         switch (type_2){
                              case 1: function_type = dp3_f ;
                                      strcpy(current_node->label_2,"DP3");
                              break; // 1
                              case 2: function_type = lit_f ;
                                      strcpy(current_node->label_2,"LIT");
                              break; // 2
                              case 3: function_type = rsq_f ;
                                      strcpy(current_node->label_2,"RSQ");
                              break; // 3
                              strcpy(current_node->label_2,"");
                           break;
                         }
           break; // 33
   }


      current_node->line_number = line;
      current_node->child1 = child1;
      current_node->child2 = child2;
      current_node->child3 = child3;
      current_node->d_type = decl_type;
      current_node->f_type = function_type;
      current_node->exp_type = expression_type;
      current_node->var_type = var_type;
      current_node->identifier = NULL;
      current_node->integer = 0;
      current_node->floating_point = 0.0;

      current_node->node_type = node_type;

         switch(type)
            {
               case 2:
                      current_node->integer = integer_data;
               break;
               case 3:
                      current_node->floating_point = decimal_data;
               break;
               case 6:
                      current_node->exp_type = expression_type;
               break;
               case 7:
                      current_node->exp_type = expression_type;
               break;
               case 8:
                      current_node->exp_type = expression_type;
               break;
               case 15:
                       current_node->child1 = child1;
                       current_node->identifier = (char *) malloc((strlen(string_data)+1)*(sizeof(char)));
                       strcpy(current_node->identifier, string_data);
                       current_node->d_type = decl_type;
               break;
               case 16:
                       current_node->child1 = child1;
                       current_node->identifier = (char *) malloc((strlen(string_data)+1)*(sizeof(char)));
                       strcpy(current_node->identifier, string_data);
                       current_node->d_type = decl_type;
               break;
               case 27:
                       current_node->var_type = var_type;

                       current_node->identifier = (char *) malloc((strlen(string_data)+1)*(sizeof(char)));
                       strcpy(current_node->identifier, string_data);

                       if(type_2 == 1) current_node->integer = integer_data; //we've got a vector! so record which part of the vector it is
                       break;
               case 33:
                       current_node->f_type = function_type;
             }

            return current_node;
 }

void freeAST(node * ast)
{
        // Probably should recursively free the nodes you created.
         if (ast == NULL) return;
          freeAST(ast->child1);
          freeAST(ast->child2);
          freeAST(ast->child3);
          free(ast);
}

void setDepth(int x){
     int i;
     for(i=0; i<x; i++){
          printf("\t");
     }
 }



int printTree (node * t, int depth){
      if(t == NULL){
             return 1;
       }
       setDepth(depth);
       printf("%s\n",t->label);
       if(t->node_type == expression_Binary_Math ||
          t->node_type == expression_Binary_Logic ||
          t->node_type == expression_Comparison ||
          t->node_type == declaration_VAR ||
          t->node_type == declaration_CONST ||
          t->node_type == constructor_call){
                   setDepth(depth);printf("\t%s\n",t->label_2);
          }
       if(t->node_type == function_call){
                   setDepth(depth);printf("\t%s()\n",t->label_2);	
        }
       if(t->node_type == declaration_CONST || t->node_type == declaration_VAR || t->node_type == variable){
                   setDepth(depth);printf("\t\"%s\"\n",t->identifier);
        }
       if(t->node_type == expression_INT_C ){
                   setDepth(depth);printf("\t\"%d\"\n",t->integer);
       }	
       if(t->node_type == expression_FLOAT_C ){
                   setDepth(depth);printf("\t\"%f\"\n",t->floating_point);
       }
       int new_depth;
       if ((t->node_type == declarations)||(t->node_type == statements)||(t->node_type == arguments))
                     new_depth = depth;
       else
                     new_depth = depth+=1;


       printTree(t->child1, new_depth);
       printTree(t->child2, new_depth);
       printTree(t->child3, new_depth);
}
 

void printAST(node * ast) {
printTree(ast, 0);
}
