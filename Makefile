CC = gcc -w -Wall


exp : lex.yy.o y.tab.c arbre.o TabLexico.o TabDeclaration.o TabType.o TabRegion.o PileExec.o
	$(CC) -o exp y.tab.c lex.yy.o arbre.o TabLexico.o TabDeclaration.o TabType.o TabRegion.o PileExec.o -ll

lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c -o lex.yy.o

lex.yy.c: exp.l y.tab.h
	lex exp.l

y.tab.h: exp.y arbre.h TabType.h TabLexico.h TabDeclaration.h TabRegion.h PileExec.h
	yacc -d -v exp.y

arbre.o: arbre.c arbre.h
	$(CC) -c arbre.c

TabLexico.o: TabLexico.c TabLexico.h
	$(CC) -c TabLexico.c

TabRegion.o: TabRegion.c TabRegion.h
	$(CC) -c TabRegion.c

TabType.o: TabType.c TabType.h TabLexico.h TabDeclaration.h
	$(CC) -c TabType.c

TabDeclaration.o: TabDeclaration.c TabType.h TabLexico.h TabDeclaration.h TabRegion.h
	$(CC) -c TabDeclaration.c

PileExec.o: PileExec.c PileExec.h arbre.h TabRegion.h TabDeclaration.h TabLexico.h y.tab.h
	$(CC) -c PileExec.c

clean :
	rm -f y.output y.tab.c y.tab.h lex.yy.c lex.yy.o arbre.o TabLexico.o TabDeclaration.o TabType.o TabRegion.o PileExec.o exp