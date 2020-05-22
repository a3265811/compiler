scanner: lex.yy.c hash.o
	cc -o scanner -O lex.yy.c hash.o -ll
lex.yy.c: scanner.l
	lex scanner.l
hash.o: hash.h hash.c
	cc -c hash.c
clean:
	rm -rf lex.yy.c scanner hash.o
