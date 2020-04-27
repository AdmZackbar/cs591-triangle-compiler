CC = g++
EXECS = tc td ti
EXAMPLEDIR = ./Examples
OUTDIR = ./Output
RESULTDIR = ./Output/Results

.PHONY: all test clean
all: $(EXECS)

tc : ./Compiler/main.cpp
	$(CC) ./Compiler/main.cpp -I ./Compiler -g -o tc

td : ./Disassembler/main.cpp
	$(CC) ./Disassembler/main.cpp -I ./Disassembler -o td

ti : ./Interpreter/main.cpp
	$(CC) ./Interpreter/main.cpp -I ./Interpreter -o ti

test : tc ti
	@mkdir -p Output/Results
	@$(foreach f, $(shell ls $(EXAMPLEDIR)), ./tc $(EXAMPLEDIR)/$(f) $(OUTDIR)/$(f).tam;)
	@$(foreach f, $(shell ls $(OUTDIR)), ./ti $(OUTDIR)/$(f) > $(RESULTDIR)/$(f).output;)

clean :
	rm -rf $(EXECS) ${OUTDIR} *.tam *.xml
