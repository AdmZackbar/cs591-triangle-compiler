CC = g++
FLAGS = -std=c++11
EXECS = tc td ti
EXAMPLEDIR = ./Examples
RESULTDIR = ./Output/Results

TESTS = ./Examples/9-6/for.tri ./Examples/9-6/repeat.tri ./Examples/9-7/case.tri ./Examples/9-8/varinit.tri ./Examples/9-9/opdecl.tri ./Examples/9-10/valparam.tri
TESTS := $(TESTS) ./Examples/9-10/valresultparam.tri ./Examples/9-11/enum.tri ./Examples/9-11/succpred.tri ./Examples/9-12/str.tri ./Examples/9-14/package.tri
TESTS := $(TESTS) ./Examples/9-14/package2.tri ./Examples/9-15/array.tri ./Examples/9-15/array_ob.tri

.PHONY: all test clean
all: $(EXECS)

tc : ./Compiler/main.cpp
	$(CC) ./Compiler/main.cpp -I ./Compiler $(FLAGS) -o tc

td : ./Disassembler/main.cpp
	$(CC) ./Disassembler/main.cpp -I ./Disassembler $(FLAGS) -o td

ti : ./Interpreter/main.cpp
	$(CC) ./Interpreter/main.cpp -I ./Interpreter $(FLAGS) -o ti

test: tc ti
	rm -f output.txt
	for file in $(TESTS) ; do \
		echo $$file >> output.txt ; \
		./tc $$file ; \
		./ti temp.tam >> output.txt ; \
	done

clean :
	rm -rf $(EXECS) *.tam *.xml output.txt
