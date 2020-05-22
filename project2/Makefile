scanner: lex.yy.c symbolTable.o y.tab.c
	gcc -o parser -O lex.yy.c y.tab.c symbolTable.o -ll -ly
y.tab.c: parser.y
	bison -y -d parser.y
lex.yy.c: scanner.l
	flex scanner.l
symbolTable.o: symbolTable.c
	gcc -c symbolTable.c
clean:
	rm -rf lex.yy.c parser symbolTable.o y.tab.c y.tab.h
