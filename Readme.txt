Instructions for using these programs with g++:

To use the compiler:
	cd Compiler
	g++ main.cpp -I . -o tc 
	./tc filename.tri 	# produces temp.tam and temp.xml

To use the disassembler:
	cd Disassembler
	g++ main.cpp -I . -o td
	./td filename.tam
	
To use the interpreter:
	cd Interpreter
	g++ main.cpp -I . -o ti
	./ti filename.tam

