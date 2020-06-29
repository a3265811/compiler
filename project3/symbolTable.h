#include <stdio.h> //standard I/O
#include <stdlib.h> //using memory allocation
#include <string.h> //some string functions
#define idTable_size 1024 //hash table size
#define idName_size 1024 //data size

//data type for every identifier
typedef struct _node{
	struct _node *pre;	//last id
	struct _node *next;	// next id
   char  *idName;	//store id name
	int type;	//store id type
	int index;	//-3:function -2:global var -1:val other:local var
   int value;	//store integer and boolean val
	char* value_str;	//store string val
	int args[256];	//store function parameters' type
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
	int tableIndex;
}table;

//hash function for getting index
int hash_f(char*);

//create a symbol table
void createTable();

//delete symbol table
void deleteTable();

//search specific data in specific symbol talbe
node* lookup(table *searchTable, char*,int);

//insert data to specific symbol table
node* insert(table*,char*,int,int,int,char*);

//show the specific symbol table
void dump(table*);

//string and integer covering to each other
int type2int(char*);

char* int2type(int);

//predefine table pointer
table *tableList;
table *objectTable;

//output file
#ifdef abc
#define abc
extern FILE* fout = NULL;
#endif
