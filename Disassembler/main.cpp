// #include <conio.h>
#include <cstdio> 
#include <cstdlib>
#include <fstream>
#include <string>
#include "./TAM/Disassembler.h"

using namespace std;

int main(int argc, char** argv) 
{ 

	if(argc != 2)
	{
		printf("Usage: %s <tam filename>\n", argv[0]);
		exit(1);
	}
	
	printf("\n\n****************** TAM Disassembler (C++ Version 1.1) *******************\n");
	
	string tamFileName(argv[1]);

	Disassembler* disassembleit = new Disassembler();
	

    disassembleit->loadObjectProgram(tamFileName);
    disassembleit->disassembleProgram();

//	printf("\n\nPress any key to exit\n");
//	getch();
}
