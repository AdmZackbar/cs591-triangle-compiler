#ifndef _StringTypeDenoter
#define _StringTypeDenoter


#include "./AST/AST.h"
#include "./AST/IntegerLiteral.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class StringTypeDenoter: public TypeDenoter
{
    public:
    IntegerLiteral* IL;

    StringTypeDenoter (IntegerLiteral* ilAST, SourcePosition* thePosition):TypeDenoter(thePosition) {
        IL = ilAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitStringTypeDenoter((Object*)this, o);
    }

    bool equals (Object *obj)
    {
        if (obj && obj->class_type() == "STRINGTYPEDENOTER")
        {
            StringTypeDenoter *ast2 = (StringTypeDenoter *)obj;
            if (atoi(this->IL->spelling.c_str())==atoi(ast2->IL->spelling.c_str()))
                return true;
        }
        return false;
    }

    string class_type() {
        string temp = "STRINGTYPEDENOTER";
        return temp;
    }
};

#endif
