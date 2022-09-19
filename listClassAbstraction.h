#ifndef LIST_STRUCT_H
#define LIST_STRUCT_H
#include<unistd.h>

// The attribute structure with no disclosed attribute

/*
The list_t is just a declaration without a 
definition, and with just a structure declaration, you cannot access the fields 
of the structure. You cannot even declare a variable out of it. This way, we 
guarantee the information-hiding.
*/
struct list_t;

// Allocation function

struct list_t* list_malloc();

//Construct and destructor function

void list_init(struct list_t*);
void list_destroy(struct list_t*);

// Publixc behavour funmctions

int list_add(struct list_t*, int);
int list_get(struct list_t*, int, int*);
void list_clear(struct list_t*);
size_t list_size(struct list_t*);
void list_print(struct list_t*);
#endif
