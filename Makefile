all: main.o fileOps.o
	gcc main.o fileOps.o -o todo

main.o: main.c fileOps.o
	gcc -c main.c

fileOps.o: fileOps.c
	gcc -c fileOps.c

clean:
	rm main.o
	rm fileOps.o