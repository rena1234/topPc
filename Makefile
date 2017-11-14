all:
	clear
	gcc -c main.c -o main.o
	gcc -c cria_grafo.c -o cria_grafo.o
	gcc -c sequencial.c -o sequencial.o -lm
	gcc -c teste.c -o teste.o
	gcc -c no.c -o no.o
	
	gcc main.o sequencial.o teste.o no.o cria_grafo.o -o executavel 

