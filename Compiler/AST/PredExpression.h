#ifndef _PredExpression
#define _PredExpression

#include "./AST/Expression.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;

class PredExpression: public Expression {

public:
    Expression *E;

    PredExpression (Expression* eAST, SourcePosition* thePosition): Expression(thePosition) {
        E = eAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitPredExpression(this, o);
    }

string class_type() {
    string temp = "PREDEXPRESSION";
    return temp;
}
  
};

#endif
