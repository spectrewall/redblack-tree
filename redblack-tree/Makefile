all: ArvoreRubroNegra

ArvoreRubroNegra: main.o ArvoreRubroNegra.o
	gcc -o ArvoreRubroNegra main.o ArvoreRubroNegra.o

main.o: main.c ArvoreRubroNegra.h
	gcc -o main.o main.c -c -w -Wall -ansi -pedantic

ArvoreRubroNegra.o: ArvoreRubroNegra.c ArvoreRubroNegra.h
	gcc -o ArvoreRubroNegra.o ArvoreRubroNegra.c -c -W -Wall -ansi -pedantic

clean:
	rm -rs *.o *~ ArvoreRubroNegra

