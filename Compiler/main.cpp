// #include <conio.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "Compiler.h"
#include "./PrintVisitor/PVInt.h"
#include "./PrintVisitor/PrintVisitor.h"
using namespace std;

int main(int argc, char** argv) 
{
	if(argc != 2 && argc != 3 && argc !=4)
	{
		printf("Usage: %s <triangle filename>\n", argv[0]);
		exit(1);
	}

	bool compiledOK;
	Compiler* MiniTriangleCompiler = new Compiler();
	
	string sourceFileName(argv[1]);

	string objectName = "temp.tam";
	if(argc >= 3)
		objectName = argv[2];

	string xmlName = "temp.xml";
	if(argc == 4)
		xmlName = argv[3];


	compiledOK = MiniTriangleCompiler->compileProgram(sourceFileName,objectName,true,false,xmlName);

//	printf("\n\nPress any key to exit\n");
//	getch();
} 
