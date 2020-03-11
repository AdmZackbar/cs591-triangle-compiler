// #include <conio.h>
#include <cstdio> 
#include <cstdlib>
#include <fstream>
#include <string>
#include "./TAM/Interpreter.h"

using namespace std;

int main(int argc, char** argv) 
{ 
	if(argc != 2)
	{
		printf("Usage: %s <tam filename>\n", argv[0]);
		exit(1);
	}
	
	printf("\n\n****************** TAM Interpreter (C++ Version 1.1) *******************\n");
	
	

	string tamFileName(argv[1]);

	Interpreter* interpret = new Interpreter();
	
	//printf("FILE NAME:%s",tamFileName.c_str());
    interpret->loadObjectProgram(tamFileName);
	
    if (interpret->CT != interpret->CB) {
      interpret->interpretProgram();
      interpret->showStatus();
	}
  
//	printf("\n\nPress any key to exit\n");
//	getch();
} 
