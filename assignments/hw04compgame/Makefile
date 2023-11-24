PROJECT=hw04compgame
CC=gcc
CFLAGS+=-std=c17 -Wall -Wextra -pedantic -O3 -g # -lm  -Wunused-variable #-Werror
LFLAGS+=#-lpthread
PROGRAM=compgame

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
