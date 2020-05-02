#ifndef _NilTypeDenoter
#define _NilTypeDenoter

#include "./AST/TypeDenoter.h"
#include "./AST/Object.h"

#include <string>

using namespace std;

class NilTypeDenoter: public TypeDenoter {
    public:
    NilTypeDenoter (SourcePosition* thePosition): TypeDenoter(thePosition) {};
    Object* visit (Visitor* v, Object* o) {
        return v->visitNilTypeDenoter(this, o);
    }

    bool equals (Object* obj) {
        return (obj && (obj->class_type() == "NILTYPEDENOTER" || obj->class_type() == "POINTERTYPEDENOTER"));
    }

    string class_type(){
        string temp = "NILTYPEDENOTER";
        return temp;
    }
};

#endif
