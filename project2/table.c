#include "symbolTable.h"
#include <stdio.h>

int main()
{
	createTable();
	createTable();
	createTable();
	createTable();
	createTable();
	createTable();
	createTable();
	createTable();
	createTable();
	while(tableList != NULL)
	{
		printf("%p\n",tableList);
		tableList = tableList -> pre;
	}
	return 0;
}
