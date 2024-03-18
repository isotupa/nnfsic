CC=gcc
CFLAGS=-Wall
CFLAGS+=-Wextra
CFLAGS+=-lm
CFLAGS+=-lgsl
CFLAGS+=-lgslcblas


main:
	$(CC) -c src/neural.c -o bin/neural.o
	$(CC) -c src/linear_ops/linear.c -o bin/linear.o
	$(CC) -c main.c -o bin/main.o
	$(CC) bin/*.o -o bin/main
	rm bin/*.o

neural: 
	$(CC) $(CFLAGS) -c src/*
	$(CC) $(CFLAGS) src/* 
	$(CC) $(CFLAGS) -o bin/neural *.o
	rm *.o a.out

test:
	$(CC) -c src/neural.c -o bin/neural.o
	$(CC) -c src/linear_ops/linear.c -o bin/linear.o
	$(CC) -c test.c -o bin/test.o
	$(CC) bin/*.o -o bin/test
# rm bin/*.o

# neural: src/csv_reader.c src/csv_reader.h src/globals.h src/img_printer.c src/img_printer.h src/main.c src/mynn.c src/mynn.h
# 	$(CC) $(CFLAGS) src/csv_reader.c src/img_printer.c src/main.c src/mynn.c -o bin/neural
