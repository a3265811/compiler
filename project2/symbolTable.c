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
	//make table linked list
	if(tableList == NULL)
		temp_t->pre = NULL;
	else
		temp_t->pre = tableList;
	temp_t->next = NULL;
	tableList = temp_t;
}

//if parser go out of function and delete the symbol table 
void deleteTable(){
	table *temp_t = NULL;
	temp_t = tableList;
	tableList = tableList->pre;
	tableList->next = NULL;
	free(temp_t);
}

/*
	search specific data in specific symbol talbe
	insert_mode is for inserting that looking up wether the same identifier in the right now symbol table
*/
node* lookup(table *searchTable, char* str,int insert_mode){	
	table *now_table = searchTable;
	node *now = NULL;			
	while(now_table != NULL){
		list_head *entry = NULL;
		//get the address of hash entry
		entry = now_table->idTable[hash_f(str)];
		/*
			search linked list until find the data
			if find data break while loop
			if not keep searching
		*/
		if(entry != NULL){
			now = entry->head;
			while(now != NULL){
				if(strcmp(str,now->idName) == 0)
					break;
				else
					now = now->next;
			}
  		}
		/*
			check wether find the data in the symbol table
			if not, continue search previous table
			if insert_mode is ON only search right now table
		*/
		if(now != NULL)
			break;
		else if(insert_mode == 1)
			break;
		else
			now_table = now_table->pre;
	}
	return now;
}

//insert data to specific symbol table
node* insert(table *insertTable,char *str,char* type){
	list_head *entry = NULL;
	node *now = NULL;
	/*
		check wether identifier is in the symbol table
		if yes, return
		if not, insert
	*/
	now = lookup(insertTable,str,1);
	if(now != NULL)
		return now;
	/*
		reset now
		give a new memory space for temp_n and initial temp_n
		copy identifier name to temp_n
		copy type name to temp_n
	*/
	now = NULL;
	node *temp_n = malloc(sizeof(node));
	temp_n->pre = NULL;
	temp_n->next = NULL;
	temp_n->idName = NULL;
	temp_n->type = NULL;
	for(int i = 0; i < 256; i++)
		temp_n->args[i] = 0;
	temp_n->idName = malloc(sizeof(char) * (strlen(str)+1));
	temp_n->type = malloc(sizeof(char) * (strlen(type)+1));
	strcpy(temp_n->idName,str);
	strcpy(temp_n->type,type);
	//get the address of hash entry
	entry = insertTable->idTable[hash_f(str)];
	/*
		if entry of hash table is empty give a new memory space and insert to head and tail
		if not, check the list of entry wether is only one node
		if yes, let the next of head become new node
		finally link the node to tail
	*/
	if(entry == NULL){
		entry = malloc(sizeof(list_head));
		insertTable->idTable[hash_f(str)] = entry;
		entry->head = temp_n;
		entry->tail = temp_n;
	}
	else{
		if(entry->head == entry->tail)
			entry->head->next = temp_n;
		entry->tail->next = temp_n;
		temp_n->pre = entry->tail;
		entry->tail = temp_n;
	}
	return temp_n;
}

//show the all indentifiers in specific symbol table  
void dump(table *dumpTable){
	//let user know we will print symbol table
	printf("dump symbol table (%p):\n",tableList);
	//print every entry and linked list behind of entry
	for(int i = 0 ; i < idTable_size; i++){
		list_head *entry = NULL;
		node *now = NULL;
		entry = dumpTable->idTable[i];
		if(entry == NULL)
			continue;
		now = entry->head;
		while(now != NULL){
			printf(" %s",now->idName);
			printf(" %s",now->type);
			printf(" %p",now);
			now = now->next;
		}
		if(entry!=NULL)
			printf("\n");
	}
}
