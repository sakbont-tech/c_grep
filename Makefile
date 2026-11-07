.PHONY: clean

CC := gcc
CFLAGS := -std=c17 -Wall -Wextra -Wpedantic -g

cgrep: main.c
	${CC} ${CFLAGS} main.c -o cgrep

clean: 
	rm -f cgrep