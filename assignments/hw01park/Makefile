CC=gcc
CFLAGS+=-std=c99 -Wall -Wextra -pedantic -g -lm -O3 -Wunused-variable #-Werror
LFLAGS+=-lpthread
CFILES=main.c

all: clean compile

compile:
	$(CC) $(CFLAGS) $(CFILES) -o main $(LFLAGS)

run:
	./main

clean:
	rm main

zip:
	zip hw01park.zip $(CFILES)

tar:
	tar -czf hw01park.tar $(CFILES)
