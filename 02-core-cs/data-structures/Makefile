CC     = gcc
CFLAGS = -std=c99 -Wall

SRC = $(wildcard */*.c)
BIN = $(patsubst %.c,bin/%,$(SRC))

all: $(BIN)

bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin

.PHONY: all clean
