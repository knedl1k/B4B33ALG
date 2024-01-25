PROJECT=ZK
CC=g++
CFLAGS+=-std=c++20 -Wall -O3 -Wextra -pedantic  -g # -lm  -Wunused-variable #-Werror
LFLAGS+=#-lpthread
PROGRAM=main

all: compile

compile: $(PROGRAM)

$(PROGRAM): main.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

run:
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM) *.d $(PROJECT).{zip,tar}

zip:
	zip $(PROJECT).zip *.[cpp]

tar:
	tar -czf $(PROJECT).tar *.[cpp]

.PHONY: $(PROGRAM)
