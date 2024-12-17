INCLUDE_PATHS =
CFLAGS = -Wall -Wextra -ggdb
CLIBS = -lraylib -lm
SOURCES = main.c
CC = clang
EXECUTABLE = infpong

all: main

main: main.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(CLIBS)

run: main
	./$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)

