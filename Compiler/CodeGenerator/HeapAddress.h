#ifndef _HEAPADDRESS
#define _HEAPADDRESS

#include "./CodeGenerator/RuntimeEntity.h"
#include "./CodeGenerator/ObjectAddress.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class HeapAddress: public RuntimeEntity {

public:
    ObjectAddress* address;	
	HeapAddress(): RuntimeEntity() {
        address = NULL;
    }

    HeapAddress(int size, int level, int displacement): RuntimeEntity(size) {
        address = new ObjectAddress(level, displacement);
    }
    string class_type() {
        string temp = "HEAPADDRESS";
        return temp;
    }

};


#endif
