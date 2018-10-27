CC=gcc
CFLAGS=-lWarn -pedantic
OBJS=main.o irtester.o
LDFLAGS=-lwiringPi

tester: tester.o libmyifttt.a
	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

%.o: %.c irtester.h
	$(CC) -Wall -pedantic -c -ansi $<

main: $(OBJS)
	$(CC) -Wall -pedantic $(OBJS) -o main $(LDFLAGS)

clean:
	rm tester *.o
