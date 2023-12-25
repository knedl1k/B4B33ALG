PROJECT=hw08garden
CC=gcc
CFLAGS+=-std=c17 -Wall -O3 -Wextra -pedantic  -g # -lm  -Wunused-variable #-Werror
LFLAGS+=#-lpthread
PROGRAM=main

all: compile

compile: $(PROGRAM)

$(PROGRAM): main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

run:
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) *.d $(PROJECT).{zip,tar}

zip:
	zip $(PROJECT).zip *.[ch]

tar:
	tar -czf $(PROJECT).tar *.[ch]

.PHONY: $(PROGRAM)
