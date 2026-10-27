CXX      = g++
CXXFLAGS = -std=c++14 -Wall

SRC = $(wildcard */*.cpp)
BIN = $(patsubst %.cpp,bin/%,$(SRC))

all: $(BIN)

bin/%: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf bin

.PHONY: all clean
