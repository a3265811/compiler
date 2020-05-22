#include <stdio.h> //standard I/O
#include <stdlib.h> //using memory allocation
#include <string.h> //some string functions
#define idTable_size 1024 //hash table size
#define idName_size 1024 //data size

//data type for every identifier
typedef struct _node{
	struct _node *pre;
	struct _node *next;
   char  idName[idName_size];  
	char type[100];
}node;

//data type for every hash entry
typedef struct _list_head{
	node *head;
	node *tail;
}list_head;

//data tyep for table
typedef struct _table{
	struct _table *pre;
	struct _table *next;
	list_head *idTable[idTable_size];
}table;

//hash function for getting index
int hash_f(char*);

//create a symbol table
void createTable();

//copy last symbol table
void copyTable(table*, table*);

//delete symbol table
void deleteTable();

//search specific data in specific symbol talbe
node* lookup(table *searchTable, char*);

//insert data to specific symbol table
node* insert(table*,char*,char*);

//show the specific symbol table
void dump(table*);

table *tableList;
