CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/main.c src/builtin.c
OUT = shellG

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)