#ifndef _SuccExpression
#define _SuccExpression

#include "./AST/Expression.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;

class SuccExpression: public Expression {

public:
    Expression *E;

    SuccExpression (Expression* eAST, SourcePosition* thePosition): Expression(thePosition) {
        E = eAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitSuccExpression(this, o);
    }

string class_type() {
    string temp = "SUCCEXPRESSION";
    return temp;
}
  
};

#endif
