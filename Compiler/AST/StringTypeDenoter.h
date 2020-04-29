#ifndef _StringTypeDenoter
#define _StringTypeDenoter


#include "./AST/AST.h"
#include "./AST/IntegerLiteral.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class StringTypeDenoter :public TypeDenoter {

public:
    IntegerLiteral* IL;

    StringTypeDenoter (IntegerLiteral* ilAST, SourcePosition* thePosition):TypeDenoter(thePosition) {
        IL = ilAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitStringTypeDenoter((Object*)this, o);
    }

	string class_type() {
	    string temp = "STRINGTYPEDENOTER";
	    return temp;
    }

};

#endif
