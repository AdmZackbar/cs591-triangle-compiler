#ifndef _UNKNOWNVALUE
#define _UNKNOWNVALUE

#include "./CodeGenerator/RuntimeEntity.h"
#include "./CodeGenerator/ObjectAddress.h"
#include <string>

using namespace std;

class UnknownValue : public RuntimeEntity {

public:

	ObjectAddress* address;

	UnknownValue ():RuntimeEntity() {
		address = NULL;
		}

	UnknownValue (int size, int level, int displacement):RuntimeEntity(size) {
		address = new ObjectAddress(level, displacement);
		}
	string class_type() {
		string temp = "UNKNOWNVALUE";
		return temp;
		}
};

#endif
