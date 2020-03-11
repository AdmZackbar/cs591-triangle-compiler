CC = g++
EXECS = compiler disassembler interpreter
EXAMPLEDIR = ./Examples
OUTDIR = ./Output
RESULTDIR = ./Output/Results

.PHONY: all test clean
all: $(EXECS)

compiler : ./Compiler/main.cpp
	$(CC) ./Compiler/main.cpp -I ./Compiler -o compiler

disassembler : ./Disassembler/main.cpp
	$(CC) ./Disassembler/main.cpp -I ./Disassembler -o disassembler

interpreter : ./Interpreter/main.cpp
	$(CC) ./Interpreter/main.cpp -I ./Interpreter -o interpreter

test : compiler interpreter
	@mkdir -p Output/Results
	@$(foreach f, $(shell ls $(EXAMPLEDIR)), ./compiler $(EXAMPLEDIR)/$(f) $(OUTDIR)/$(f).tam;)
	@$(foreach f, $(shell ls $(OUTDIR)), ./interpreter $(OUTDIR)/$(f) > $(RESULTDIR)/$(f).output;)

clean :
	rm -rf $(EXECS) ${OUTDIR} *.tam *.xml output.txt 

