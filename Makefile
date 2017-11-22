all:
	clear
	gcc -c main.c -o main.o -g
	gcc -c cria_grafo.c -o cria_grafo.o
	gcc -c sequencial.c -o sequencial.o -lm
	gcc -c teste.c -o teste.o
	gcc -c no.c -o no.o
	gcc -c paralelo.c -o paralelo.o -lm -g -fopenmp
	gcc  sequencial.o teste.o no.o cria_grafo.o paralelo.o main.o -o executavel -fopenmp

clean:
	rm -f *.o
