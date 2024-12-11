all: main.c
	clang -Wall -Wextra -ggdb main.c -lraylib -lm -o infinite_pong

clean:
	rm infinite_pong

