#ifndef _PointerTypeDenoter
#define _PointerTypeDenoter

#include "./AST/TypeDenoter.h"
#include "./AST/Object.h"

#include <string>

using namespace std;

class PointerTypeDenoter: public TypeDenoter {
    public:
    TypeDenoter *childType;
    PointerTypeDenoter (SourcePosition* thePosition): TypeDenoter(thePosition) {};
    Object* visit (Visitor* v, Object* o) {
        return v->visitPointerTypeDenoter(this, o);
    }

    bool equals (Object* obj) {
        if (obj && (obj->class_type() == "POINTERTYPEDENOTER" || obj->class_type() == "NILTYPEDENOTER"))
            return true;
        if (obj)
            return childType->equals(obj);
        return false;
    }

    string class_type() {
        string temp = "POINTERTYPEDENOTER";
        return temp;
    }
};

#endif
