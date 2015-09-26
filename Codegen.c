#include "Codegen.h"


int TEMP_REG_SPACE[256];
int CONST_COUNTER = 0;


void process_MoveOp(char * input1, char * result){
     fprintf(outputFile,"MOV %s, %s;\n", result,input1);
}


void process_CompareOp(enum Expression_Type op, char * input1, char * input2, char * result){
//assuming that 0 < 0.0 if false
      switch(op){
         case logical_eq:{
//Implementation of SLT => A < B
           char* temp_1 = allocate_temp_reg(0,0,0,0);
           char* temp_2 = allocate_temp_reg(1,1,1,1);
           char* temp_3 = allocate_temp_reg(0,0,0,0);
           fprintf(outputFile,"SLT %s, %s, %s;\n",temp_1, input1, input2 );
           process_ArithmeticOp(subtract, temp_1, temp_2, temp_3 );

           char* temp_4 = allocate_temp_reg(0,0,0,0);

           char* const_true = create_constant(1,1,1,1);
           char* const_false = create_constant(-1,-1,-1,-1);
           fprintf(outputFile,"CMP %s, %s, %s, %s;\n", temp_4, temp_3, const_false, const_true);


//implementation of A > B => - (A < B)
           char* temp_5 = allocate_temp_reg(0,0,0,0);
           process_NegateOp(temp_4, temp_5);

           char* temp_6 = allocate_temp_reg(0,0,0,0);
           process_BinaryOp(logical_or, temp_4, temp_5, temp_6);


           process_NegateOp(temp_6, result);

         }
        break;
        case logical_neq:{
           char* temp_1 = allocate_temp_reg(0,0,0,0);	
           process_CompareOp(logical_eq, input1, input2, temp_1);
           process_NegateOp(temp_1, result);
           free_temp_reg(temp_1);
          }
        break;
        case logical_le:{
//Implementation of SLT => A < B
             char* temp_1 = allocate_temp_reg(0,0,0,0);
             char* temp_2 = allocate_temp_reg(1,1,1,1);
             char* temp_3 = allocate_temp_reg(0,0,0,0);
             fprintf(outputFile,"SLT %s, %s, %s;\n",temp_1, input1, input2 );
             process_ArithmeticOp(subtract, temp_1, temp_2, temp_3 );


             char* const_true = create_constant(1,1,1,1);
             char* const_false = create_constant(-1,-1,-1,-1);
             fprintf(outputFile,"CMP %s, %s, %s, %s;\n", result, temp_3, const_false, const_true);

        }
        break;
        case logical_leq:{
                char* temp_1 = allocate_temp_reg(0,0,0,0);
                process_CompareOp(logical_le, input1, input2, temp_1);
                char* temp_2 = allocate_temp_reg(0,0,0,0);
                process_CompareOp(logical_eq, input1, input2, temp_2);
                process_BinaryOp(logical_or, temp_1, temp_2, result);

         }
       break;
       case logical_ge:{
                char* temp_1 = allocate_temp_reg(0,0,0,0);
                process_CompareOp(logical_leq, input1, input2, temp_1);
                process_NotOp(temp_1, result);

       }
       break;
       case logical_geq:{
//Implementation of SLT => A < B
               char* temp_1 = allocate_temp_reg(0,0,0,0);
               char* temp_2 = allocate_temp_reg(1,1,1,1);
               char* temp_3 = allocate_temp_reg(0,0,0,0);
               fprintf(outputFile,"SGE %s, %s, %s;\n",temp_1, input1, input2 );
               process_ArithmeticOp(subtract, temp_1, temp_2, temp_3 );


              char* const_true = create_constant(1,1,1,1);
              char* const_false = create_constant(-1,-1,-1,-1);
              fprintf(outputFile,"CMP %s, %s, %s, %s;\n", result, temp_3, const_false, const_true);

       }
       break;
      }
}






void process_BinaryOp(enum Expression_Type op, char* input1, char* input2, char* result){
         switch(op){
//highly dependant on the interpretation of:
// 0 < 0.0
// and -0 == 0 ?
           case logical_and:
               {
                 char* temp_1 = allocate_temp_reg(0,0,0,0);
                 process_ArithmeticOp(add, input1, input2, temp_1);
                 char* temp_2 = allocate_temp_reg(0,0,0,0);
                 process_NegateOp(temp_1,temp_2);
                 free_temp_reg(temp_1);

                 char* const_true = create_constant(1,1,1,1);
                 char* const_false = create_constant(-1,-1,-1,-1);
                 fprintf(outputFile,"CMP %s, %s, %s, %s;\n", result,temp_2, const_true, const_false);
                 free_temp_reg(temp_2);
              }
           break;
           case logical_or:
              {
                 char* temp_1 = allocate_temp_reg(0,0,0,0);
                 process_ArithmeticOp(add, input1, input2, temp_1);

                 char* const_true = create_constant(1,1,1,1);
                 char* const_false = create_constant(-1,-1,-1,-1);
                 fprintf(outputFile,"CMP %s, %s, %s, %s;\n", result,temp_1, const_false, const_true);
                 free_temp_reg(temp_1);
            }
            break;
           }
}







void process_NegateOp(char * input1, char * result){
      fprintf(outputFile,"MOV %s.x, -%s.x;\n", result,input1);
      fprintf(outputFile,"MOV %s.y, -%s.y;\n", result,input1);
      fprintf(outputFile,"MOV %s.z, -%s.z;\n", result,input1);
      fprintf(outputFile,"MOV %s.w, -%s.w;\n", result,input1);
}


void process_NotOp(char * input1, char * result){
        fprintf(outputFile,"MOV %s.x, -%s.x;\n", result,input1);
 
        fprintf(outputFile,"MOV %s.y, -%s.y;\n", result,input1);

        fprintf(outputFile,"MOV %s.z, -%s.z;\n", result,input1);

        fprintf(outputFile,"MOV %s.w, -%s.w;\n", result,input1);
}


void process_ArithmeticOp( enum Expression_Type op, char* input1, char* input2, char* result){
       switch(op){
            case add:
              fprintf(outputFile,"ADD %s, %s, %s;\n",result,input1,input2);
            break;
            case subtract:
              fprintf(outputFile,"SUB %s, %s, %s;\n",result,input1,input2);
            break;
            case multiply:
              fprintf(outputFile,"MUL %s, %s, %s;\n",result,input1,input2);
            break;
            case divide:
                   {
                       char* temp = allocate_temp_reg(0,0,0,0);
                       fprintf(outputFile,"RCP %s.x, %s.x;\n", temp, input2);
                       fprintf(outputFile,"RCP %s.y, %s.y;\n", temp, input2);
                       fprintf(outputFile,"RCP %s.z, %s.z;\n", temp, input2);
                       fprintf(outputFile,"RCP %s.w, %s.w;\n", temp, input2);
                       fprintf(outputFile,"MUL %s, %s, %s;\n", result, input1, temp);
                       free_temp_reg(temp);
                   }
            break;
           case exponent:
     //need scalar input based on variable constructor call e.g. var[0]
                fprintf(outputFile,"POW %s, %s, %s;\n", result, input1, input2);
           break;
          }
}






char* create_constant(float a,float b,float c,float d){

             fprintf(outputFile,"PARAM const_%d = { %.1f , %.1f , %.1f , %.1f };\n", CONST_COUNTER, a, b, c, d);
             char* temp = (char*)malloc(255);
             sprintf(temp, "const_%d" , CONST_COUNTER);
             CONST_COUNTER+=1;
             return temp;
}


int create_var_register(char* name, float a,float b,float c,float d){
             fprintf(outputFile,"TEMP %s = { %.1f , %.1f , %.1f , %.1f };\n",name,a, b, c, d );
             return -1;
}


char* allocate_temp_reg(float a,float b,float c,float d){
        int i;
        char* temp = (char*)malloc(255);
          for( i = 0; i < 256; i++){
                if(TEMP_REG_SPACE[i] == 0){
                      fprintf(outputFile,"TEMP tempVar_%d;\n",i);
                      TEMP_REG_SPACE[i] = 2;
                      sprintf(temp, "tempVar_%d" , i);
                      return temp ;
                 }
                 else if(TEMP_REG_SPACE[i] == 1){
                      TEMP_REG_SPACE[i] = 2;
                      sprintf(temp, "tempVar_%d" , i);
                      return temp ;
                 }
            }
        free(temp);
        fprintf(outputFile,"ERROR - allocate_temp_reg() exceeded max # of temp registers, maximum 256.\n");
        return NULL;
}




void free_temp_reg(char* reg){
       if(reg !=NULL)
           {
              char* pch = (char*) malloc(255);
              char* copy = (char*) malloc(255);

              strcpy(copy, reg);
              strtok(copy,"_");	

              pch = strtok(NULL,"_");
              int reg_int = atoi(pch);

                if((reg_int >=0) && (reg_int<256) && (TEMP_REG_SPACE[reg_int] == 2)){
                      TEMP_REG_SPACE[reg_int] = 1;

                      free(reg);
                }
                else{
                       fprintf(outputFile,"ERROR - free_temp_reg(int reg) error!\n");
                }

            }
}












