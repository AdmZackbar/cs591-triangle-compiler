#ifndef _VarInitDeclaration
#define _VarInitDeclaration


#include "./AST/VarDeclaration.h"
#include "./AST/Identifier.h"
#include "./AST/Expression.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include <string>
using namespace std;


class VarInitDeclaration : public VarDeclaration {

public:
    Expression *E;

	VarInitDeclaration (Identifier* iAST, Expression* eAST, SourcePosition* thePosition):VarDeclaration(iAST, NULL, thePosition) {
        E = eAST;
    }
  
    Object* visit(Visitor* v, Object* o) {
        return v->visitVarInitDeclaration(this, o);
    }

	string class_type()	{
		string temp = "VARINITDECLARATION";
		return temp;
	}  
};

#endif
