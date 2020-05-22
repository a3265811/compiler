#include "hash.h"

node *idTable[idTable_size];

int hash_f(char* str){
	int index = 0; //hash function index
   size_t length = strlen(str); //get string length
	for(int i = 0 ; i < length; i++)
		index += str[i];
	return index % idTable_size;
}


//initial symbol table
void create(){
	for(int i = 0 ; i < idTable_size; i++){
		idTable[i] = NULL ;
	}
}


node* lookup(char* str){
	node *now = NULL; //pointer for lined list
	now = idTable[hash_f(str)];//get the first hash index
	while(1){
		if(now == NULL) // not match the string
			break; 
		else{
			if(strcmp(str,now->idName) == 0)// match the string
				break;		
			else// not match the string
				now = now->next;
		}
	}
	return now;
}


node* insert(char* str){
	node *now = NULL;//pointer for lined list
	now = lookup(str);//check wether is in symbol table
	if(now != NULL)
		return now;
	now = NULL;//reset now
	node *temp = malloc(sizeof(node));//give a new memory space
	strcpy(temp->idName,str);//copy string to temp
	now = idTable[hash_f(str)];//get the first hash index
	while(1){
		if(now == NULL){ //if the first entry is NULL that means the empty linked list and just put into symbol table
			idTable[hash_f(str)] = temp;
			break;
		}
		else if(now->next == NULL){ //if the next entry is NULL that means we went to last data in this linked list and just put backward this data
			temp->pre = now;
			now->next = temp;
			break;
		}
		else // the next entry already have data and go ahead for empty space
			now = now -> next;
	}
	return temp;
}

void dump(){
	node *now = NULL; //pointer for linked list
	printf("dump symbol table:\n"); //let user know we will print symbol table
	for(int i = 0 ; i < idTable_size; i++){ //every entry will be print unless NULL entry
		now = idTable[i];
		while(now != NULL){
			printf(" %s",now->idName);
			printf(" %p",now);
			now = now->next;
		}
		now = NULL;
		if(idTable[i]!=NULL)
			printf("\n");
	}
}
