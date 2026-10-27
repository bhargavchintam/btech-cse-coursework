CC     = gcc
CFLAGS = -std=c99 -Wall
LDLIBS = -lm

SRC = $(wildcard */*.c)
BIN = $(patsubst %.c,bin/%,$(SRC))

all: $(BIN)

bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -rf bin

.PHONY: all clean
