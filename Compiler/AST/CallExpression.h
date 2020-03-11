#ifndef _CallExpression
#define _CallExpression

#include "./AST/Expression.h"
#include "./AST/Identifier.h"
#include "./AST/ActualParameterSequence.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;

class CallExpression : public Expression {

public:
	Identifier* I;
	ActualParameterSequence* APS;

	CallExpression (Identifier* iAST, ActualParameterSequence* apsAST,
		SourcePosition* thePosition):Expression(thePosition) {
    I = iAST;
    APS = apsAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitCallExpression(this, o);
  }

string class_type(){
	string temp = "CALLEXPRESSION";
	return temp;
	}
  
};


#endif
