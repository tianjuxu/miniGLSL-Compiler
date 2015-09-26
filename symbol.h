/*
SYMBOL.H defines Symbol Table Structure as a Linked List and its associated helper functions

The first data structure is: << symrec >>
-----------------------------------------
<< symrec >> is concerned with the following production rules:
: type ID ';'
| type ID '=' expression ';'
| CONST type ID '=' expression ';'
| ';'

<< symrec >> has attributes:
name - string holds the name of the ID (identifier)
type - <ENUM D_Type> holds the type of ID as a member of ENUM-D_Type
write_only - BOOLEAN flag specifies if ID is write only
read_only - BOOLEAN flag specifies if ID is read only
value - optional string to hold the value associated with <expression> for rules:
| type ID '=' expression ';'
| CONST type ID '=' expression ';'
next - pointer to the next symrec data structure in the linked list

<< symrec >> has helper functions:

=>symrec* putsym();
This function inserts data from a AST node into a supplied symbol table. On success, it returns the newly created symbol table entry
=>symrec* getsym();
This function fetchs an entry for a supplied symbol table and ID string. On success, it returns the pointer to the entry in the symbol table
On failure it returns 0.
=>void printSymbols();
This function prints out all entries a supplied symbol table.
=>void init_table();
This function initialises a supplied symbol table with the following entries:
"gl_FragColor", vec4_t
"gl_FragDepth", boolean_t
"gl_FragCoord", vec4_t
"gl_TexCoord", vec4_t
"gl_Color", vec4_t
"gl_Secondary", vec4_t
"gl_FogFragCoord", vec4_t
"gl_Light_Half", vec4_t
"gl_Light_Ambient", vec4_t
"gl_Material_Shininess", vec4_t
"env1", vec4_t
"env2", vec4_t
"env3", vec4_t
These entries represent the predefined qualifiers for the mini-GLSL language.
=>int is_readonly();
This function checks if an entry in a supplied symbol table has read-only permissions
On success it returns 1.
On failure it return 0.
=>int is_writeonly();
This function checks if an entry in a supplied symbol table has write-only permissions
On success it returns 1.
On failure it return 0.
=>int build_sym_table();
This function builds a symbol table when supplied with a NULL pointer to a symbol table and an AST node of a "scope" node

The second data structure is: << stack_el >>
--------------------------------------------
<< stack_el >> holds a linked list of all symbol tables of type <symrec> for all "scope" nodes found in the AST

<< stack_el >> has attributes:
sym_table - (symrec*)pointer to a symbol table
next - (stack_el*)pointer to the next stack_el data structure in the linked list

<< stack_el >> has helper functions:
=>void printStackNodes();
This function prints the contents of the entire << stack_el >> linked_list. It contains all symbol tables for all "scopes" identified.
=>int isInStack();
This function checks if a supplied ID string is present in the stack linked list.
=>stack_el* push_master();
This functions inserts a symbol table into the top of the stack.
=>stack_el* pop_master();
This function removes("pops") the symbol table on the top of the stack. It returns the "popped" symbol table.
=>int build_master_sym_list();
This function recursively builds the stack of symbol tables from a supplied AST.


Problems Encountered
====================

1) When checking the following form:
{
   {
    vec4 a = gl_Color;
   }
  {
    vec4 vroom = gl_Color;
    a = gl_Color;
  }
}
Our semantic check currently cannot detect the above invalid usage of "a = gl_Color". The assignment to "a" is invalid in the latter scope since it has not been declared in its own scope and its parent scope.
However it has been declared in its adjacent scope. However since our Symbol table stack is built with all symbol tables for all nodes, It thinks that "a" has been declared when it checks the validity of "a = gl_Color".
Therefore our compiler does not throw an error in this case when it should.
*/

#ifndef _SYMBOL_H
#define _SYMBOL_H

#include "ast.h"
#include "common.h"
//#include "semantic.h"
enum Id_Type {
const_t,
uniform_t,
attribute_t,
result_t,
invalid_id_type
};
//extern stack_el* stack;
/* Data type for links in the chain of symbols. */
struct symrec
{
  char* name;
  enum D_Type type;
int write_only;
int read_only;
  enum Id_Type id_type;
  struct symrec *next;	
};
typedef struct symrec symrec;

struct stack_el
{
struct stack_el *next;
struct symrec *sym_table;	
};

typedef struct stack_el stack_el;

symrec* putsym (symrec*&, char* ,enum D_Type ,int ,int ,enum Id_Type );
symrec* getsym (symrec* ,char* );
void printSymbols(symrec* );
void init_table(symrec*&);
int is_readonly(symrec*,symrec*);
int is_writeonly(symrec*,symrec*);
int build_sym_table(symrec*&, node*);

void printStackNodes(stack_el* stack);
symrec* isInStack(stack_el* stack, char* value);
stack_el* push_master(stack_el*& stack, symrec* sym_table);
stack_el* pop_master(stack_el*& stack);
int check_assgn_decl(node* ast, stack_el* stack);
int build_master_sym_list(node* ast);


#endif


