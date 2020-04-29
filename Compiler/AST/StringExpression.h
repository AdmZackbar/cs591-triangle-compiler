#ifndef _StringExpression
#define _StringExpression

#include "./AST/Expression.h"
#include "./AST/StringLiteral.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;

class StringExpression : public Expression {

public:
    StringLiteral* SL;

    StringExpression (StringLiteral* slAST, SourcePosition* thePosition):Expression(thePosition) {
        SL = slAST;
    }

    Object* visit(Visitor* v, Object* o) {
    return v->visitStringExpression(this, o);
    }

string class_type(){
    string temp = "STRINGEXPRESSION";
    return temp;
}
  
};

#endif
