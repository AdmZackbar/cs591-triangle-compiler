#ifndef _NilExpression
#define _NilExpression

#include "./AST/AST.h"
#include "SourcePosition.h"
#include "./AST/Expression.h"
#include <string>
using namespace std;

class NilExpression: public Expression {
    public:
    NilExpression (SourcePosition* thePosition): Expression(thePosition) {
        // Do nothing
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitNilExpression(this, o);
    }

    string class_type() {
        string temp = "NILEXPRESSION";
        return temp;
    }  
};

#endif
