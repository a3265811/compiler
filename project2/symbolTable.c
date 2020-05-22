#include "symbolTable.h"

//hash function for getting index
int hash_f(char* str){
	int index = 0; 						//hash function index
   size_t length = strlen(str); 		//get string length
	for(int i = 0 ; i < length; i++) //counting string ASCII sum
		index += str[i];
	return index % idTable_size;
}

//create a symbol table
void createTable(){
	table *temp_t = malloc(sizeof(table));
	//initial symbol table
	for(int i = 0 ; i < idTable_size; i++){
		temp_t->idTable[i] = NULL;
	}
	/*
		when encounter a function brackets we need to copy the same symbol table
		if not just create a talbe
	*/
	if(tableList == NULL){
		temp_t->pre = NULL;
		temp_t->next = NULL;
		tableList = temp_t;
	}
	else{
		copyTable(tableList,temp_t);
		temp_t->pre = tableList;
		tableList->next = temp_t;
		tableList = temp_t;
	}
}

//copy last symbol table
void copyTable(table *pre_t, table *next_t){
	//copy every entry of hash table and linked list to the new symbol table
	for(int i = 0; i < idTable_size; i++){
		list_head *temp_l = NULL;
		temp_l = pre_t->idTable[i];
		if(temp_l != NULL){
			for(node *j = temp_l->head ; j != NULL ; j = j->next)
				insert(next_t,j->idName,j->type);
		}
	}
}

//if parser go out of function and delete the symbol table 
void deleteTable(){
	table *temp_t = NULL;
	temp_t = tableList;
	tableList = tableList->pre;
	tableList->next = NULL;
	free(temp_t);
}

//search specific data in specific symbol talbe
node* lookup(table *searchTable, char* str){	
	list_head *entry = NULL;
	node *now = NULL;			
	//get the address of hash entry
	entry = searchTable->idTable[hash_f(str)];
	/*
		if entry of hash table is empty just break
		search linked list until find the data
		if find data return address
		if not return NULL
	*/
	if(entry == NULL)
		return now; 
	else{
		if(entry->head == NULL || entry->tail == NULL)
			return now;
		else{
			now = entry->head;
			while(now != NULL){
				if(strcmp(str,now->idName) == 0)
					break;
				else
					now = now->next;
			}
		}
	}
	return now;
}

//insert data to specific symbol table
node* insert(table *insertTable,char *str,char *type){
	list_head *entry = NULL;
	node *now = NULL;
	//check wether identifier is in the symbol table
	now = lookup(insertTable,str);
	if(now != NULL)
		return now;
	/*
		reset now
		give a new memory space for temp_n
		copy string to temp_n
	*/
	now = NULL;//reset now
	node *temp_n = malloc(sizeof(node));
	strcpy(temp_n->idName,str);
	//if know what type is and copy to temp_n
	if(strcmp(type,"Nothing") != 0)
		strcpy(temp_n->type,type);
	//get the address of hash entry
	entry = insertTable->idTable[hash_f(str)];
	/*
		if entry of hash table is empty give a new memory space and insert to head and tail
		if not, check wether is only one node
		if yes, let the next of head become new node
		finally link the node to tail
	*/
	if(entry == NULL){
		entry = malloc(sizeof(list_head));
		entry->head = temp_n;
		entry->tail = temp_n;
	}
	else{
		if(entry->head == NULL || entry->tail ==NULL)
			entry->head->next = temp_n;
		entry->tail->next = temp_n;
		temp_n->pre = entry->tail;
		entry->tail = temp_n;
	}
	return temp_n;
}

//show the specific symbol table  
void dump(table *dumpTable){
	//let user know we will print symbol table
	printf("dump symbol table:\n");
	//print every entry and linked list behind of entry
	for(int i = 0 ; i < idTable_size; i++){
		list_head *entry = NULL;
		node *now = NULL;
		entry = dumpTable->idTable[i];
		now = entry->head;
		while(now != NULL){
			printf(" %s",now->idName);
			printf(" %p",now);
			now = now->next;
		}
		if(entry!=NULL)
			printf("\n");
	}
}
