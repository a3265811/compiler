From project1 to project 2
Changes for scanner.l
1. Do not print token forever
2. Return value to parser.y
3. Using yylval as a delivery parameter between scanner.l and parser.y
4. Comments still print to screen

Changes for symbol table
structure: table linked list 
					    ^
						 |
			    symbol table
						 ^
						 |
				   identifier
1. Now can insert to specific table
2. Now can search specific table and choose wether search deeply
3. Now can dump specific table
4. Adding now function deleteTable()

print keyword need add parentheses
e.g. print (abc)
