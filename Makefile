CC = g++
FLAGS = -std=c++11
EXECS = tc td ti
EXAMPLEDIR = ./Examples
RESULTDIR = ./Output/Results

.PHONY: all test clean
all: $(EXECS)

tc : ./Compiler/main.cpp
	$(CC) ./Compiler/main.cpp -I ./Compiler $(FLAGS) -o tc

td : ./Disassembler/main.cpp
	$(CC) ./Disassembler/main.cpp -I ./Disassembler $(FLAGS) -o td

ti : ./Interpreter/main.cpp
	$(CC) ./Interpreter/main.cpp -I ./Interpreter $(FLAGS) -o ti

clean :
	rm -rf $(EXECS) *.tam *.xml
