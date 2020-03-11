#ifndef _EQUALITYROUTINE
#define _EQUALITYROUTINE

#include "./CodeGenerator/RuntimeEntity.h"
#include "./AST/Object.h"
#include <string>

using namespace std;


class EqualityRoutine: public RuntimeEntity{

public:
	int displacement;

	EqualityRoutine ():RuntimeEntity() {};

	EqualityRoutine (int size, int displacement):RuntimeEntity(size) {
		this->displacement = displacement;
		}

	string class_type(){
		string temp = "EQUALITYROUTINE";
		return temp;
	}
};


#endif
