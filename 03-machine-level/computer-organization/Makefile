CC     = gcc
CFLAGS = -std=c99 -Wall

SRC = $(wildcard */*.c) $(wildcard lab/*/*.c)
BIN = $(patsubst %.c,bin/%,$(SRC))

all: $(BIN)

bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf bin

# verilog doesn't fit a pattern rule nicely (testbenches pull in their design
# files), so those are run by hand -- each _tb.v has its command in a comment

.PHONY: all clean
