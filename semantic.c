
#include "semantic.h"

#include "common.h"

#include "parser.tab.h"
#define TRACE(x) { printf("%s\n", x); }

stack_el *stack = (stack_el *)0;

extern int inside_if = 0;
extern int checking_write_only = 0;
extern int checking_read_only = 0;
extern int uniform_or_const_check_flag = 0;

extern int constructor_temp_count = 0;
extern int arg_gen = 0;
        


int semanticCheck(node * ast){
           //ast will be AST node of type scope
           //push ast into stack
         int pop_master_flag = 0;
            if (ast->sym_table!=NULL){
               pop_master_flag = 1;
               push_master(stack, ast->sym_table);
            }

         
           //Call to Declarations Check
            if ((declarations_Check(ast->child1) == 1) && (statementsCheck(ast->child2) == 1)){
          
                   if (pop_master_flag == 1)
                       pop_master(stack);
               return 1;
            }
            else{

              TRACE("ERROR - At Scope with Declarations or Statements");
              errorOccurred = TRUE;
              return 0;
            }
}



char* filter_custom_var(char* ident){
        if(strcmp(ident, "gl_FragColor") == 0 ){
                return "result.color";
         }
        if(strcmp(ident, "gl_FragDepth") == 0 ){
                return "result.depth";
         }	
        if(strcmp(ident, "gl_FragCoord") == 0 ){
                return "fragment.position";
         }
        if(strcmp(ident, "gl_TexCoord") == 0 ){
                return "fragment.texcoord";
         }
        if(strcmp(ident, "gl_Color") == 0 ){
                return "fragment.color";
         }
        if(strcmp(ident, "gl_Secondary") == 0 ){
                return "fragment.color.secondary";
         }
        if(strcmp(ident, "gl_FogFragCoord") == 0 ){
                return "fragment.fogcoord";
         }
        if(strcmp(ident, "gl_Light_Half") == 0 ){
                return "state.light[0].half";
         }
        if(strcmp(ident, "gl_Light_Ambient") == 0 ){
                return "state.lightmodel.ambient";
         }
        if(strcmp(ident, "gl_Material_Shininess") == 0 ){
                return "state.material.shininess";
         }
        if(strcmp(ident, "env1") == 0 ){
                return "program.env[1]";
         }
        if(strcmp(ident, "env2") == 0 ){
                return "program.env[2]";
         }
        if(strcmp(ident, "env3") == 0 ){
                return "program.env[3]";
         }
     return NULL;
}



              //return 1 for success and 0 for failure
int declarations_Check(node * decl){
             int result = 1;
             int result1 = 1;
             int result2 = 1;

            if (decl == NULL) return 1;

            if (decl->node_type == declarations){
                 result1 = declarations_Check(decl->child1);
                 result2 = declarations_Check(decl->child2);
                 return ((result1 == 1)&&(result2 == 1))? 1 : 0;
             }
            else if((decl->child1 == NULL)&&(decl->child2 == NULL)){
                 fprintf(outputFile,"TEMP %s;\n", decl->identifier);
                 return 1; //
           }	
           else
              return assignmentCheck(decl);
}


            //return 1 for success and 0 for failure
int statementsCheck(node * stmts){
          int result = 1;
          int result1 = 1;
          int result2 = 1;

          if (stmts == NULL) return 1; 

          if (stmts->node_type == statements){
                result1 = statementsCheck(stmts->child1);
                result2 = statementsCheck(stmts->child2);
                return ((result1 == 1)&&(result2 == 1))? 1 : 0;
         }
         else{
                switch(stmts->node_type){
                     case statement_closed_IF_ELSE:
                            {
                                char * temp = allocate_temp_reg(0,0,0,0);
                                if(expressionCheck(stmts->child1, temp)!=boolean_t){
                                TRACE("ERROR: Expression for an if statement may only evaluate to boolean!");
                                return 0;
                                }
                                else{
           
                                     inside_if++;
                                      if(stmts->child1->node_type == expression_TRUE_T){
                                         result1 = statementsCheck(stmts->child2);
                                         inside_if--;
                                         return result1;
                                      }
                                      else if(stmts->child1->node_type == expression_FALSE_T){
                                         result1 = statementsCheck(stmts->child3);
                                         inside_if--;
                                         return result1;
                                       }
                                      else{
                                         result1 = statementsCheck(stmts->child2);
                                         result2 = statementsCheck(stmts->child3);
                                         inside_if--;
                                         return ((result1 == 1)&&(result2 == 1))? 1 : 0;
                                      }
                                }
                               free_temp_reg(temp);
                               break;
                            }
                           case statement_closed_WHILE:
                                 TRACE("ERROR: WHILE LOOPS ARE NOT ALLOWED IN OUR LANGUAGE AND IN LAB3, TSK TSK TSK...");
                                 return 0;
                           break;
                           case statement_closed_ASSG:
                                 return assignmentCheck(stmts);
                           break;
                           case statement_open_WHILE:
                                 TRACE("ERROR: WHILE LOOPS ARE NOT ALLOWED IN OUR LANGUAGE AND IN LAB3, TSK TSK TSK...");
                                 return 0;
                           break;
                           case statement_open_IF_ELSE:
                                   {
                                      char * temp = allocate_temp_reg(0,0,0,0);
                                      if(expressionCheck(stmts->child1, temp)!=boolean_t){
                                                 TRACE("ERROR: Expression for an if statement may only evaluate to boolean!");
                                                  return 0;
                                       }
                                      else{
                                              inside_if++;
                                              result1 = statementsCheck(stmts->child2);
                                              result2 = statementsCheck(stmts->child3);
                                              inside_if--;
                                              return ((result1 == 1)&&(result2 == 1))? 1 : 0;
                                      }
                                      free_temp_reg(temp);

                           break;
                          }
                           case statement_open_IF:
                                    {
                                       char * temp = allocate_temp_reg(0,0,0,0);
                                       if(expressionCheck(stmts->child1, temp)!=boolean_t){
                                             TRACE("ERROR: Expression for an if statement may only evaluate to boolean!");
                                             return 0;
                                       }
                                      else{
                                             inside_if++;
                                             result1 = statementsCheck(stmts->child2);
                                             inside_if--;
                                             return result1;
                                      }
                                         free_temp_reg(temp);

                            break;
                            }
                          case scope:
                                     return semanticCheck(stmts);
                          break;
                }
        }
}

            //return 1 for success and 0 for failure // checks both declarations and assignments
int assignmentCheck(node * assgn){
           //declarations check
  if (assgn->node_type == declaration_CONST){
                  Node_Type RHS;
                  D_Type RHS_type;
                  D_Type LHS_type;
                  node * RHS_node;

               if (assgn->child1->node_type == expression_Parenthesis){ 
                        RHS = parenthesis_recursion_check(assgn->child1)->node_type;
                        RHS_type = parenthesis_recursion_check(assgn->child1)->d_type;
                        RHS_node = parenthesis_recursion_check(assgn->child1);
               }
               else{
                        RHS = assgn->child1->node_type;
                        RHS_type = assgn->child1->d_type;
                        RHS_node = assgn->child1;
               }

       fprintf(outputFile,"PARAM %s = ",(filter_custom_var(assgn->identifier)?filter_custom_var(assgn->identifier):assgn->identifier));

              if(RHS == constructor_call){ 
          //check if a constructor is seen and check its type(vector only) if so.
         
         
                  if (constructorCheck(RHS_node, NULL) == 0){
                        TRACE("ERROR - bad constructor in const declaration");
                        return 0;
                  } // ERROR - bad constructor in const declaration

                  if ((RHS_type == integer_t)||(RHS_type == boolean_t)&&(RHS_type == float_c)){
                              TRACE("ERROR - constructor calls for non vectors aren't allowed ");
                              return 0; 
                  }	// ERROR - constructor calls for non vectors aren't allowed 
              }
              else if(((RHS == expression_INT_C)||(RHS == expression_FLOAT_C)||(RHS == expression_TRUE_T)||(RHS == expression_FALSE_T))){
                        switch(RHS){
                             case expression_INT_C: 
                                      fprintf(outputFile,"%.1f;\n", (float)RHS_node->integer); RHS_type = integer_t; 
                             break;
                             case expression_FLOAT_C: 
                                      fprintf(outputFile,"%.1f;\n", RHS_node->floating_point); RHS_type = float_c; 
                             break;
                             case expression_FALSE_T: 
                                      fprintf(outputFile,"{-1.0,-1.0,-1.0,-1.0};\n"); RHS_type = boolean_t; 
                             break;
                             case expression_TRUE_T: 
                                      fprintf(outputFile,"{1.0,1.0,1.0,1.0};\n"); RHS_type = boolean_t; 
                             break;
                         }
               }
             else if(RHS == variable)
              {
                 uniform_or_const_check_flag ++;
               fprintf(outputFile,"%s;\n",(filter_custom_var(RHS_node->identifier) ? filter_custom_var(RHS_node->identifier) : RHS_node->identifier));

                 if(variableCheck(RHS_node) == invalid_d_type){
                 TRACE("ERROR: Assigning a constant to an invalid variable");
                  }
                 else RHS_type = variableCheck(RHS_node);
                 uniform_or_const_check_flag --;
              }
             else{ //invalid expression was used in const assignment, error out
                   TRACE("ERROR invalid expression was used in const assignment");	
                   return 0;
              } //ERROR - invalid expression used


         //now we should have a valid right hand side type... lets figure out the LHS and make sure the two are the same, if not, FAIL

           LHS_type = assgn->d_type;

            if (LHS_type != RHS_type){
                TRACE("ERROR - type mismatch in const assignment ");
                return 0;}//ERROR - type mismatch in const assignment
            else return 1;
      }	
     else if (assgn->node_type == declaration_VAR){
        //first check if the expresion is valid
        //If it is the expression checker will return the D_Type the expression would evaluate to
                 char* temp = allocate_temp_reg(0,0,0,0);

                 checking_write_only++;
                 D_Type RHS_type = expressionCheck(assgn->child1, temp);
       
                 checking_write_only--;
                 D_Type LHS_type = assgn->d_type;
                 fprintf(outputFile,"TEMP %s;\n",
(filter_custom_var(assgn->identifier) ? filter_custom_var(assgn->identifier) : assgn->identifier));

                 fprintf(outputFile,"MOV %s, %s;\n", (filter_custom_var(assgn->identifier) ? filter_custom_var(assgn->identifier) : assgn->identifier),(filter_custom_var(temp) ? filter_custom_var(temp) : temp) );
      

       free_temp_reg(temp);

       if(RHS_type == invalid_d_type){
            TRACE("ERROR: the expression used in assignment didn't pass the semantic check");
            return 0;
        } //ERROR: the expression used in assignment didn't pass the semantic check
       else if(RHS_type != LHS_type) {
            TRACE("ERROR: type mismatch");
            return 0;
        } //ERROR: type mismatch
       else {
            return 1;
       } //return successfully
      }
      else if (assgn->node_type == statement_closed_ASSG){
             D_Type RHS_type;
             D_Type LHS_type;
             node * LHS_node = assgn->child1;
             node * RHS_node = assgn->child2;

             checking_read_only++;
             LHS_type = variableCheck(assgn->child1);
           
             checking_read_only--;

             checking_write_only++;
             char * temp = allocate_temp_reg(0,0,0,0) ;
             RHS_type = expressionCheck(assgn->child2, temp);
             if (LHS_node->var_type == vector){
                   switch(LHS_node->integer){
                          case 0:
           fprintf(outputFile,"MOV %s.x , ",(filter_custom_var(LHS_node->identifier)?filter_custom_var(LHS_node->identifier):LHS_node->identifier));
                          break;
                          case 1:
            fprintf(outputFile,"MOV %s.y , ",(filter_custom_var(LHS_node->identifier)?filter_custom_var(LHS_node->identifier):LHS_node->identifier));

                          break;
                          case 2:
            fprintf(outputFile,"MOV %s.z , ",(filter_custom_var(LHS_node->identifier)?filter_custom_var(LHS_node->identifier):LHS_node->identifier));

                          break;
                          case 3:
            fprintf(outputFile,"MOV %s.w , ",(filter_custom_var(LHS_node->identifier)?filter_custom_var(LHS_node->identifier):LHS_node->identifier));

                          break;
                   }
                }
           else{
          
          fprintf(outputFile,"MOV %s , ",(filter_custom_var(LHS_node->identifier) ? filter_custom_var(LHS_node->identifier) : LHS_node->identifier));
            }

                  fprintf(outputFile,"%s;\n", (filter_custom_var(temp)?filter_custom_var(temp):temp));
                  checking_write_only--;
         
                 free_temp_reg(temp);

                 if((RHS_type==invalid_d_type)||(LHS_type==invalid_d_type)){
                         TRACE("ERROR: Problem with assignment");
                         return 0;
                 }
                 else if(RHS_type!=LHS_type){
                         TRACE("ERROR: Types don't match in an assignment");
                         return 0;
                 }
                 else
                         return 1; //return successfully
           return 1;
         }
        else {
                   TRACE("ERROR - something went wrong when the tree was build  ");
                   return 0; 
         }
}

int constructorCheck(node * con, char * result_reg){

           int args_num = con->child1->number_args;


          if (result_reg == NULL)
                fprintf(outputFile,"{ ");
          else {
                fprintf(outputFile,"TEMP constructorTempVar_%d = { ", constructor_temp_count);
          }
          arg_gen = 1;
          D_Type args_type = argumentsCheck(con->child1);
          arg_gen = 0;

          if (result_reg == NULL)
                 fprintf(outputFile," };\n");
          else {
                 fprintf(outputFile," };\n");
                 sprintf(result_reg, "constructorTempVar_%d" , constructor_temp_count);
                 constructor_temp_count++;
          }

          switch (con->d_type){
                   case integer_t:
                         if((args_type != integer_t) || (args_num != 1)) {
                               TRACE("ERROR: Invalid constructor call.");
                               return 0;
                          }
                          else return 1; //successful
                   break;
                   case boolean_t:
                         if((args_type != boolean_t) || (args_num != 1)) {
                               TRACE("ERROR: Invalid constructor call.");
                               return 0;
                         }
                         else return 1; //successful
                  break;
                  case float_c:
                         if((args_type != float_c) || (args_num != 1)) {
                               TRACE("ERROR: Invalid constructor call.");
                               return 0;
                         }
                         else return 1; //successful
                  break;
                  case vec2_t:
                         if((args_type != float_c) || (args_num != 2)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case vec3_t:
                         if((args_type != float_c) || (args_num != 3)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case vec4_t:
                         if((args_type != float_c) || (args_num != 4)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case ivec2_t:
                         if((args_type != integer_t) || (args_num != 2)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case ivec3_t:
                         if((args_type != integer_t) || (args_num != 3)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case ivec4_t:
                         if((args_type != integer_t) || (args_num != 4)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case bvec2_t:
                         if((args_type != boolean_t) || (args_num != 2)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                         break;
                  case bvec3_t:
                         if((args_type != boolean_t) || (args_num != 3)) {
                         TRACE("ERROR: Invalid constructor call.");
                         return 0;
                         }
                         else return 1; //successful
                  break;
                  case bvec4_t:
                        if((args_type != boolean_t) || (args_num != 4)) {
                        TRACE("ERROR: Invalid constructor call.");
                        return 0;
                        }
                        else return 1; //successful
                  break;
                  default: return 0;
                  break;	//something is wrong
           }
}

D_Type functionCheck(node * func, char * result_reg ){

          int args_num = func->child1->number_args;



          switch(func->f_type){
               case dp3_f: fprintf(outputFile,"DP3 %s, " ,result_reg); break;
               case rsq_f: fprintf(outputFile,"RSQ %s, " ,result_reg); break;
               case lit_f: fprintf(outputFile,"LIT %s, ", result_reg); break;
           }
          D_Type args_type = argumentsCheck(func->child1);

          fprintf(outputFile," ;\n");


         switch(func->f_type){
               case dp3_f:
                  if(((args_type == vec4_t)||(args_type == vec3_t))&&(args_num == 2))
                        return float_c;
                  else if (((args_type == ivec4_t)||(args_type == ivec3_t))&&(args_num == 2))
                        return integer_t;
                  else{
                        TRACE("ERROR: Invalid call to dp3.");
                        return invalid_d_type;
                  }
               break;
               case rsq_f:
                  if(((args_type == integer_t))&&(args_num == 1))
                       return float_c;
                  else if (((args_type == float_c))&&(args_num == 1))
                       return float_c;
                  else{
                       TRACE("ERROR: Invalid call to rsq.");
                       return invalid_d_type;
                  }

               break;
               case lit_f:
                  if((args_type == vec4_t)&&(args_num == 1)) return vec4_t;
                  else{
                         TRACE("ERROR: Invalid call to lit.");

                          return invalid_d_type;
                  }
               break;
               default:
                      TRACE("ERROR: error in function call check");
                      return invalid_d_type;
               break;
          }

}
D_Type argumentsCheck(node * args){
           D_Type type_return;
           D_Type args_return;
          if(args->child2 != NULL){
               args_return = argumentsCheck(args->child1);
               fprintf(outputFile," , ");
               type_return = expressionCheck(args->child2, NULL);
                 if(type_return != args_return) return invalid_d_type; // all arguments should be of the same type
                 else return type_return;
          }
          else{
               type_return = expressionCheck(args->child1, NULL);
               return type_return;
          }
}

         // checks if the expression makes sense (i.e. types match)
          // returns the type of value the expression evaluates to
         // returns 'invalid' if expression is invalid
D_Type expressionCheck(node * exp, char * result_reg){

    D_Type left;
    D_Type right;
    Expression_Type comparison;

        switch(exp->node_type){
         // these are all constants, return their type
            case expression_INT_C:
             {
                    if (result_reg != NULL){
                      fprintf (outputFile,"MOV %s, %s;\n",result_reg,create_constant(exp->integer,exp->integer,exp->integer,exp->integer));

                     }
                    else fprintf(outputFile,"%.1f", (float) exp->integer); 
                       return integer_t; 
           break;
             }
           case expression_FLOAT_C:
                 {   
                     if (result_reg != NULL){
                          fprintf (outputFile,"MOV %s, %s;\n", result_reg, create_constant(exp->floating_point, exp->floating_point, exp->floating_point, exp->floating_point));

                     }
                     else fprintf(outputFile,"%.1f", exp->floating_point); 
                     return float_c; 
           break;
           }
           case expression_TRUE_T:
                   {
                      if (result_reg != NULL){
                             fprintf (outputFile,"MOV %s, %s;\n", result_reg,create_constant(1,1,1,1));

                       }
                      else fprintf(outputFile,"1.0");	
                     return boolean_t; 
           break;
                   }
           case expression_FALSE_T:
                  {
                      if (result_reg != NULL){
                             fprintf (outputFile,"MOV %s, %s;\n", result_reg, create_constant(0,0,0,0));

                      }
                      else fprintf(outputFile,"0.0");		
                      return boolean_t; 
                   break;
                  }
           // ------------------------------------------------------
           case expression_Binary_Math:
                  {
                     char* input1 = allocate_temp_reg(0,0,0,0);
                     char* input2 = allocate_temp_reg(0,0,0,0);
                     left = expressionCheck(exp->child1, input1);
                     right = expressionCheck(exp->child2, input2);

                     if (((left == boolean_t)||
                          (left == bvec2_t)||
                          (left == bvec3_t)||
                          (left == bvec4_t))||
                         ((right == boolean_t)||
                          (right == bvec2_t)||
                          (right == bvec3_t)||
                          (right == bvec4_t))) {
                              TRACE("ERROR - binary math not allowed with booleans.");
                              return invalid_d_type;
                           }

                        process_ArithmeticOp(exp->exp_type, input1,input2,result_reg);
                        free_temp_reg(input1);
                        free_temp_reg(input2);

                      if (left == right){
                                return left; //  types are the same
                       }

                     if(((left == integer_t)||
                         (left == ivec2_t))&&((right == integer_t )||
                         (right == ivec2_t))) 
                                return ivec2_t;
                     else if (((left == integer_t)||(left == ivec3_t))&&((right == integer_t )||(right == ivec3_t))) 
                                return ivec3_t;
                     else if (((left == integer_t)||(left == ivec4_t))&&((right == integer_t )||(right == ivec4_t))) 
                                return ivec4_t;
                     else if (((left == float_c)||(left == vec2_t))&&((right == float_c )||(right == vec2_t))) 
                                return vec2_t;
                     else if (((left == float_c)||(left == vec3_t))&&((right == float_c )||(right == vec3_t))) 
                                return vec3_t;
                     else if (((left == float_c)||(left == vec4_t))&&((right == float_c )||(right == vec4_t))) 
                                return vec4_t;
                     else {
                              TRACE("ERROR, type mismatch in binary math. ");
                              return invalid_d_type; // ERROR, type mismatch 
                        }	
              break;
                }
      // ------------------------------------------------------
              case expression_Binary_Logic:
                 {
                           char* input1 = allocate_temp_reg(1,1,1,1);
                           char* input2 = allocate_temp_reg(1,1,1,1);
                           left = expressionCheck(exp->child1, input1);
                           right = expressionCheck(exp->child2, input2);

                           if ((left == integer_t)||(left == ivec2_t)||(left == ivec3_t)||(left == ivec4_t)||
                               (right == integer_t)||(right == ivec2_t)||(right == ivec3_t)||(right == ivec4_t)||
                               (right == float_c)||(right == vec2_t)||(right == vec3_t)||(right == vec4_t)||
                               (left == float_c)||(left == vec2_t)||(left == vec3_t)||(left == vec4_t)) {
                                        TRACE("ERROR - invalid binary logic ");
                                        return invalid_d_type; //ERROR - invalid binary logic
                               }

                           process_BinaryOp(exp->exp_type, input1,input2,result_reg);
                           free_temp_reg(input1);
                           free_temp_reg(input2);

                           if (left == right) return left; // types are the same

                           if (((left == boolean_t)||(left == bvec2_t))&&((right == boolean_t)||(right == bvec2_t))) return bvec2_t;
                           else if (((left == boolean_t)||(left == bvec3_t))&&((right == boolean_t)||(right == bvec3_t))) return bvec3_t;
                           else if (((left == boolean_t)||(left == bvec4_t))&&((right == boolean_t)||(right == bvec4_t))) return bvec4_t;
                           else {
                                        TRACE("ERROR, type mismatch in binary logic. ");
                                        return invalid_d_type; //ERROR, type mismatch 
                            }
               break;
                }	
      // ------------------------------------------------------
               case expression_Comparison:
                 {
                           char* input1 = allocate_temp_reg(0,0,0,0);
                           char* input2 = allocate_temp_reg(0,0,0,0);
                           left = expressionCheck(exp->child1, input1);
                           right = expressionCheck(exp->child2, input2);
                           comparison = exp->exp_type;

                

                  if ((((comparison == logical_le)||(comparison == logical_leq)||(comparison == logical_ge)||(comparison == logical_geq))&&
                       ((left == vec2_t)||(left == ivec2_t)||(left == bvec2_t)||(left == vec3_t)||(left == ivec3_t)||(left == bvec3_t)||
                        (left == vec4_t)||(left == ivec4_t)||(left == bvec4_t)||(right == vec2_t)||(right == ivec2_t)||(right == bvec2_t)||
                        (right==vec3_t)||(right ==ivec3_t)||(right ==bvec3_t)||(right ==vec4_t)||(right == ivec4_t)||(right == bvec4_t)))||
                        (left == boolean_t)){
                               TRACE("ERROR, invalid comparison operation on vector. ");
                               return invalid_d_type; 
                               }//ERROR, invalid comparison operation on vector!

                   process_CompareOp(comparison, input1, input2, result_reg);
                   free_temp_reg(input1);
                   free_temp_reg(input2);

                   if (left == right) return boolean_t; // types match, return boolean since comparisons can only result in a boolean!
                   else {
                          TRACE("ERROR, types don't match. ");
                           return invalid_d_type; //ERROR, types don't match
                   }
                   break;
                  }
            // -------------------------------------------------------
                 case expression_Unary_Minus:
                      {
                       char* input1 = allocate_temp_reg(0,0,0,0);
                       left = expressionCheck(exp->child1, input1);

                       process_NegateOp(input1, result_reg);
                       free_temp_reg(input1);

                       if ((left == integer_t)||(left == float_c)) return left; // type is either int or float and thats OK
                       else {
                                 TRACE("ERROR, unary minus can only be used with floats and ints ");
                                 return invalid_d_type; 
                       }
                  break;
                 }
          // -------------------------------------------------------
                  case expression_Logical_Not:
                     {
                       char* input1 = allocate_temp_reg(1,1,1,1);
                       left = expressionCheck(exp->child1, input1);

                       process_NotOp(input1, result_reg);
                       free_temp_reg(input1);

                       if ((left == boolean_t)||(left == bvec2_t)||(left == bvec3_t)||(left == bvec4_t))
                           return left; // type is OK // this includes boolean vectors
                       else {
                           TRACE("ERROR, logical NOT on boolean type");
                           return invalid_d_type; 
                       }
                   break;
                      }
          // --------------------------------------------------------
                 case expression_Parenthesis:
                        return expressionCheck(exp->child1, result_reg);
                 break;
          // ---------------------------------------------------------
                 case constructor_call:
                       if (constructorCheck(exp, result_reg)==1) return exp->d_type; // constructor passed the check, so return its type
                       else {
                               TRACE("ERROR, error in constructor ");
                               return invalid_d_type; //ERROR
                       }
                 break;
       // ---------------------------------------------------------
                 case function_call:
                       return functionCheck(exp, result_reg);
                 break;
        // ---------------------------------------------------------
                 case variable:{
          
                       char * temp = (char *)malloc(255);
                       if (exp->var_type == vector){
                           switch(exp->integer){
                               case 0:
                           sprintf(temp, "%s.x ",(filter_custom_var(exp->identifier)?filter_custom_var(exp->identifier):exp->identifier));
                               break;
                               case 1:
                           sprintf(temp, "%s.y ",(filter_custom_var(exp->identifier)?filter_custom_var(exp->identifier):exp->identifier));
                               break;
                               case 2:
                           sprintf(temp, "%s.z",(filter_custom_var(exp->identifier)?filter_custom_var(exp->identifier):exp->identifier));
                               break;
                               case 3:
                           sprintf(temp, "%s.w",(filter_custom_var(exp->identifier)?filter_custom_var(exp->identifier):exp->identifier));
                               break;
                           }
                       }
                      else
                           sprintf(temp , "%s",(filter_custom_var(exp->identifier)?filter_custom_var(exp->identifier):exp->identifier));

                           if (result_reg != NULL)
  fprintf(outputFile,"MOV %s, %s;\n",(filter_custom_var(result_reg)?filter_custom_var(result_reg):result_reg),(filter_custom_var(temp)?filter_custom_var(temp):temp));
                           else
                                 fprintf(outputFile,"%s",(filter_custom_var(temp)?filter_custom_var(temp):temp));

                          return variableCheck(exp);
                   }
                  break;
                  default: break;
           }
           return invalid_d_type;
}


int isInBound(int var, int lowb, int highb){
            return (((var>=lowb) && (var<=highb)) ? 1 : 0);
}

D_Type variableCheck(node* var){
         
           if(var->node_type != variable) return invalid_d_type;
                symrec* ptr;
           if((ptr = isInStack(stack, var->identifier))){
         

        
                 if((ptr->write_only == checking_write_only)&& (checking_write_only == 1)){	
                      TRACE("ERROR - Reading from a Write Only variable.");
                      return invalid_d_type;
                  }
                  if(ptr->read_only == checking_read_only && (checking_read_only == 1)){
                       TRACE("ERROR - Writing to a Read Only variable.");
                       return invalid_d_type;
                  }
                  if(uniform_or_const_check_flag && ((ptr->id_type ==attribute_t)||(ptr->id_type == result_t)|| (ptr->id_type == invalid_id_type))){
                       TRACE("ERROR - Invalid Assignment to Const type");
                       return invalid_d_type;
                  }
                  if(inside_if && (ptr->id_type == result_t)){
                       TRACE("ERROR - Invalid Assignment to Result variable in Condition Block");
                       return invalid_d_type;	
                   }
            }
          if(var->var_type == scalar){
                symrec* ptr;
                if((ptr = isInStack(stack, var->identifier))){
          

                return ptr->type;
                }
                else{
            
                       TRACE("ERROR - Variable not declared ");
                       return invalid_d_type;
                 }
           }

          if(var->var_type == vector){
          
                 symrec* ptr;
                 if((ptr = isInStack(stack, var->identifier))){
                    int result=0;
                    D_Type rtn_var;
                    switch(ptr->type){
                       case vec2_t	:
                       case ivec2_t	:
                       case bvec2_t	:
                                        result = isInBound(var->integer,0,1);
                       break;
                       case vec3_t	:
                       case ivec3_t	:
                       case bvec3_t	:
                                        result = isInBound(var->integer,0,2);
                       break;
                       case vec4_t	:
                       case ivec4_t	:
                       case bvec4_t	:
                                        result = isInBound(var->integer,0,3);
                       break;
                       default: break;
                      }
             

                    switch(ptr->type){
                           case vec2_t	:
                           case vec3_t	:
                           case vec4_t	:
                                       rtn_var = float_c;
                           break;
                           case ivec2_t	:
                           case ivec3_t	:
                           case ivec4_t	:
                                       rtn_var = integer_t;
                           break;
                           case bvec2_t	:
                           case bvec3_t	:
                           case bvec4_t	:
                                       rtn_var = boolean_t;
                           break;
                           default: break;
                       }
           
                   if(result == 0 ) {
             
                      return invalid_d_type;
                   }
                  return rtn_var;
              }
              else{
          

                   TRACE("ERROR - Variable not declared ");
                   return invalid_d_type;
               }
           }
   return invalid_d_type;
 }

node* parenthesis_recursion_check(node* exp){
          if(exp->node_type != expression_Parenthesis)
                  return exp;
          else
     return parenthesis_recursion_check(exp->child1);
}


