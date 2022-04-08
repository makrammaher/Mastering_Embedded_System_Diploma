#Basic Makefile
#CC = gcc.exe
#
#
#main.exe: main.c a.c b.c
#	gcc -c -std=c89 -I . -ansi -g a.c -o a.o
#	gcc -c -std=c89 -I . -ansi -g b.c -o b.o
#	gcc -c -std=c89 -I . -ansi -g main.c -o main.o
#	gcc -I . main.o a.o b.o -o main.exe
#
#clean:
#	rm *.o *.exe


#Basic Makefile V2

CC = gcc.exe
CFLAGS = -std=c89 -ansi -g
INCS = -I .
LIBS = 

main.exe: main.o a.o b.o
	$(CC) main.o a.o b.o -o main.exe

main.o: main.c
	$(CC) $(CFLAGS) $(INCS) -c main.c -o main.o

a.o: a.c
	$(CC) $(CFLAGS) $(INCS) -c a.c -o a.o

b.o: b.c
	$(CC) $(CFLAGS) $(INCS) -c b.c -o b.o

clean:
	rm *.o
	rm *.exe