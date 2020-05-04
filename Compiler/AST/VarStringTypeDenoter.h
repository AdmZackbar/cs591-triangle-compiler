#ifndef _VarStringTypeDenoter
#define _VarStringTypeDenoter

#include "./AST/AST.h"
#include "./AST/IntegerLiteral.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class VarStringTypeDenoter: public TypeDenoter
{
    public:
    VarStringTypeDenoter (SourcePosition* thePosition): TypeDenoter(thePosition) {}

    Object* visit(Visitor* v, Object* o) {
        return v->visitVarStringTypeDenoter((Object*)this, o);
    }

    bool equals (Object *obj)
    {
        return (obj && obj->class_type() == "VARSTRINGTYPEDENOTER" || obj->class_type() == "STRINGTYPEDENOTER");
    }

    string class_type() {
        string temp = "VARSTRINGTYPEDENOTER";
        return temp;
    }
};

#endif
