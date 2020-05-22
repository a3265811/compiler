#include <stdio.h> //standard I/O
#include <stdlib.h> //using memory allocation
#include <string.h> //some string functions
#define idTable_size 1024 //hash table size
#define idName_size 1024 //data size

//data type for symbol table entry
typedef struct _node{
	struct _node *pre;
	struct _node *next;
   char  idName[idName_size];  
}node;

int hash_f(char*);//hash function for getting index

void create();//create and initial symbol table

node* lookup(char*);//search specific data in symbol talbe

node* insert(char*);//insert specific data to symbol table

void dump();//show the while symbol table
