CC=gcc
CFLAGS=-Wall
CFLAGS+=-Wextra
CFLAGS+=-lm
CFLAGS+=-lgsl
CFLAGS+=-lgslcblas


neural: 
	$(CC) $(CFLAGS) -c src/*
	$(CC) $(CFLAGS) src/* 
	$(CC) $(CFLAGS) -o bin/neural *.o
	rm *.o a.out

# neural: src/csv_reader.c src/csv_reader.h src/globals.h src/img_printer.c src/img_printer.h src/main.c src/mynn.c src/mynn.h
# 	$(CC) $(CFLAGS) src/csv_reader.c src/img_printer.c src/main.c src/mynn.c -o bin/neural
