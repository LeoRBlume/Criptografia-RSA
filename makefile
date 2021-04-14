CriptografiaRSA: main.o func.o
	gcc -o CriptografiaRSA main.o func.o

main.o: main.c func.h
	gcc -c main.c

func.o: func.c func.h
	gcc -c func.c"