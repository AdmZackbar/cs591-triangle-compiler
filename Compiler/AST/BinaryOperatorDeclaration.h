#ifndef _BinaryOperatorDeclaration
#define _BinaryOperatorDeclaration

#include "./AST/Declaration.h"
#include "./AST/TypeDenoter.h"
#include "./AST/Operator.h"
#include "./AST/Object.h"
#include <string>


using namespace std;


class BinaryOperatorDeclaration : public Declaration {

public:
	Operator* O;
	TypeDenoter* ARG1;
	TypeDenoter* ARG2;
	TypeDenoter* RES;

	BinaryOperatorDeclaration (Operator* oAST, TypeDenoter* arg1AST,
  		   TypeDenoter* arg2AST, TypeDenoter* resultAST,
		   SourcePosition* thePosition):Declaration(thePosition) {

    O = oAST;
    ARG1 = arg1AST;
    ARG2 = arg2AST;
    RES = resultAST;
  }


  Object* visit(Visitor* v, Object* o) {
    return v->visitBinaryOperatorDeclaration(this, o);
  }
	
  string class_type(){
	string temp = "BINARYOPERATORDECLARATION";
	return temp;
	}
  
};

#endif
