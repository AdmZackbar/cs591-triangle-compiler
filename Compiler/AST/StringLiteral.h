#ifndef _StringLiteral
#define _StringLiteral

#include "./AST/Terminal.h"
#include "SourcePosition.h"
#include "Object.h"
#include <string>
using namespace std;

class StringLiteral : public Terminal {

public:	
    StringLiteral (string theSpelling, SourcePosition* thePosition): Terminal(theSpelling,thePosition) {};

    Object* visit (Visitor* v, Object* o) {
        return v->visitStringLiteral(this, o);
    }
    string class_type(){
        string temp = "STRINGLITERAL";
        return temp;
    }
};

#endif
