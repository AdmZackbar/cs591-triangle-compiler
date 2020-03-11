CC = g++
EXECS = compiler disassembler interpreter

all: $(EXECS)

compiler : ./Compiler/main.cpp
	$(CC) ./Compiler/main.cpp -I ./Compiler -o compiler

disassembler : ./Disassembler/main.cpp
	$(CC) ./Disassembler/main.cpp -I ./Disassembler -o disassembler

interpreter : ./Interpreter/main.cpp
	$(CC) ./Interpreter/main.cpp -I ./Interpreter -o interpreter

clean :
	rm -f $(EXECS)

