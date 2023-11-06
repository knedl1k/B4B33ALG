CC=gcc
CFLAGS+=-std=c17 -Wall -Wextra -pedantic -g -lm -O3 -Wunused-variable #-Werror
LFLAGS+=-lpthread
CFILES=main.c
ARCHVIE=hw02

all: compile

compile: main.c node.c
	$(CC) $(CFLAGS) $^ -o main $(LFLAGS)

run:
	./main

clean:
	rm -f main *.d $(ARCHIVE).{zip,tar}

zip:
	zip $(ARCHIVE).zip $(CFILES)

tar:
	tar -czf $(ARCHIVE).tar $(CFILES)

.PHONY: main
