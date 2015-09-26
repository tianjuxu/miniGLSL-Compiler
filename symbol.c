#include <string.h>
#include <stdlib.h>
#include "symbol.h"
#include <stdio.h>



symrec* putsym (symrec*& sym_table, char* sym_name,enum D_Type sym_type,int write_only,int read_only,enum Id_Type id_type) {
    if(getsym(sym_table, sym_name) != 0 ){
         errorOccurred = TRUE;
         printf("Error, duplicate declaration: %s\n",sym_name);
     return 0;
     }

    symrec *ptr;
    ptr = (symrec *) malloc (sizeof (symrec));
    ptr->name = (char *) malloc (strlen (sym_name) + 1);
    strcpy (ptr->name,sym_name);
    ptr->type = sym_type;
    ptr->write_only = write_only;
    ptr->read_only = read_only;
    ptr->id_type = id_type;
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
    return ptr;
}

symrec* getsym (symrec* sym_table,char* sym_name) {
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}

int is_readonly(symrec* table, symrec* sym){
     symrec *ptr;
     if(ptr = getsym(table, sym->name)){
       if(ptr->read_only) return 1;
     }
     return 0;
}

int is_writeonly(symrec* table, symrec* sym){
       symrec *ptr;
       if(ptr = getsym(table, sym->name)){
            if(ptr->write_only) return 1;
       }
   return 0;
}

void printSymbols(symrec* table){
    symrec *ptr;
    int i = 0;
      for (ptr = table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next){
printf("%d: NAME:%s TYPE:%d R:%s W:%s\n",i,ptr->name, (int)ptr->type, is_readonly(table, ptr) ? "TRUE" : "FALSE",is_writeonly(table, ptr) ? "TRUE" : "FALSE");
       i+=1;
      }
}

void init_table(symrec *&sym_table) /* puts arithmetic functions in table. */
{
    putsym(sym_table,"gl_FragColor", vec4_t,1,0,result_t);
    putsym(sym_table,"gl_FragDepth", boolean_t,1,0,result_t);
    putsym(sym_table,"gl_FragCoord", vec4_t,0,1,attribute_t);
    putsym(sym_table,"gl_TexCoord", vec4_t,0,1,attribute_t);
    putsym(sym_table,"gl_Color", vec4_t,0,1,attribute_t);
    putsym(sym_table,"gl_Secondary", vec4_t,0,1,attribute_t);
    putsym(sym_table,"gl_FogFragCoord", vec4_t,0,1,attribute_t);
    putsym(sym_table,"gl_Light_Half", vec4_t,0,1,uniform_t);
    putsym(sym_table,"gl_Light_Ambient", vec4_t,0,1,uniform_t);
    putsym(sym_table,"gl_Material_Shininess", vec4_t,0,1,uniform_t);
    putsym(sym_table,"env1", vec4_t,0,1,uniform_t);
    putsym(sym_table,"env2", vec4_t,0,1,uniform_t);
    putsym(sym_table,"env3", vec4_t,0,1,uniform_t);
}

int build_sym_table(symrec *&sym_table, node *node_ptr){
     if(node_ptr == NULL ) return 0;
     if(node_ptr->node_type == declaration_CONST ){
         if(!putsym(sym_table, node_ptr->identifier, node_ptr->d_type,0,1,const_t)){
//Print Error
            return 0;
         }
     }
     if(node_ptr->node_type == declaration_VAR){
       if(!putsym(sym_table, node_ptr->identifier, node_ptr->d_type,0,0,invalid_id_type)){
//Print Error
       return 0;
       }
//printSymbols(sym_table);
     return 1;
    }
    build_sym_table(sym_table, node_ptr->child1);
    build_sym_table(sym_table, node_ptr->child2);
    build_sym_table(sym_table, node_ptr->child3);
}

void printStackNodes(stack_el* stack){
       stack_el *ptr;
       int i = 0;
       for (ptr = stack; ptr != (stack_el *) 0; ptr = (stack_el *)ptr->next){
            printf("#:%d-- \n",i );
            printSymbols(ptr->sym_table);
            printf("-- \n",i );
            i+=1;
       }
}

symrec* isInStack(stack_el* stack, char* value){
        stack_el *ptr;
        for (ptr = stack; ptr != (stack_el *) 0; ptr = (stack_el *)ptr->next){
          symrec *ptr_r;
          if(ptr_r = getsym(ptr->sym_table, value)){
             return ptr_r;
          }
        }
return 0;

}

stack_el* push_master(stack_el*& stack, symrec* sym_table) {
     stack_el *ptr;
     ptr = (stack_el *) malloc (sizeof (stack_el));
     ptr->sym_table = sym_table;
     ptr->next = (struct stack_el *)stack;
     stack = ptr;
return ptr;
}

stack_el* pop_master(stack_el*& stack){
    stack_el *ptr;
    ptr = (stack_el *) malloc (sizeof (stack_el));
    ptr->sym_table = stack->sym_table;
    ptr->next = NULL;
    stack = stack->next;
//printSymbols(ptr->sym_table);
    return ptr;
}

int check_assgn_decl(node* ast, stack_el* stack){
     if(ast == NULL) return 0;
     if(ast->node_type == variable){
//printf("\nVar Identifiers: %s InStack? %d\n",ast->identifier,isInStack(stack,ast->identifier));
         if(isInStack(stack,ast->identifier) == 0) {
              printf("\nINVALID DECLARATION: %s\n", ast->identifier);
         }
     }
     check_assgn_decl(ast->child1, stack);
     check_assgn_decl(ast->child2, stack);
     check_assgn_decl(ast->child3, stack);

}


