Building:
Use the command 'make' to build the compiler, dissassembler, and interpreter.
Use the command 'make tc' to build only the compiler.
Use the command 'make td' to build only the dissassembler.
Use the command 'make ti' to build only the interpreter.

Usage:
Use the command ./tc 'filename'.tri to compile the given triangle program. This will create 2 files, 'temp.tam' and 'temp.xml'.
To see the TAM instructions in a .tam file, run ./td temp.tam to get the instructions printed to stdout.
To run the TAM program, run ./ti temp.tam to run the program and get all output printed to stdout.

Testing:
You can use the examples files provided in ./Examples to test various aspects of the compiler.
Expected outputs can be found in ./Output.

Cleaning:
Use the command 'make clean' to remove all executables and temporary files.
