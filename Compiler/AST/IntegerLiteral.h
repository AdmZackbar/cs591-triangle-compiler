#ifndef _IntegerLiteral
#define _IntegerLiteral

#include "./AST/AST.h"
#include "./AST/Terminal.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class IntegerLiteral : public Terminal {

public:
	IntegerLiteral (string theSpelling, SourcePosition* thePosition):Terminal(theSpelling,thePosition) {};

  Object* visit(Visitor* v, Object* o) {
    return v->visitIntegerLiteral(this, o);
  }

	string class_type(){
		string temp = "INTEGERLITERAL";
		return temp;
	}
};

#endif

