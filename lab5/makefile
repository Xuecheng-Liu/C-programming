all:lab5

lab5: lab5main.o min.o max.o sum.o sort.o
	gcc lab5main.o min.o max.o sum.o sort.o -o lab5


lab5main.o:lab5main.c
	gcc -ansi -pedantic -c lab5main.c

min.o:min.c
	gcc -ansi -pedantic -c min.c
	
max.o:max.c
	gcc -ansi -pedantic -c max.c

sum.o:sum.c
	gcc -ansi -pedantic -c sum.c

sort.o:sort.c
	gcc -ansi -pedantic -c sort.c

clean:
	rm -rf *.o lab5
