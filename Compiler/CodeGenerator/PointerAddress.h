#ifndef _POINTERADDRESS
#define _POINTERADDRESS

#include "./CodeGenerator/ObjectAddress.h"
#include "./CodeGenerator/RuntimeEntity.h"

#include <string>
using namespace std;

class PointerAddress: public RuntimeEntity {

public:
    ObjectAddress* address;
    int childSize;
    PointerAddress():RuntimeEntity() {
        address = NULL;
        childSize = 0;
    }

    PointerAddress (int size, int level, int displacement, int locSize): RuntimeEntity(size) {
        address = new ObjectAddress(level, displacement);
        childSize = locSize;
    }

    string class_type() {
        string temp = "POINTERADDRESS";
        return temp;
    }
};

#endif
