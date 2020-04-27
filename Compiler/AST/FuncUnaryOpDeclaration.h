#ifndef _FuncUnaryOpDeclaration
#define _FuncUnaryOpDeclaration

#include "./AST/Operator.h"
#include "./AST/VarFormalParameter.h"
#include "./AST/UnaryOperatorDeclaration.h"
#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./AST/TypeDenoter.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class FuncUnaryOpDeclaration : public Declaration 
{
public:
	Operator *O;
	VarFormalParameter *P1;
	UnaryOperatorDeclaration *D;
	TypeDenoter *T;
	Expression* E;

	FuncUnaryOpDeclaration (Operator *opAST, Identifier* i1AST, TypeDenoter* t1AST, TypeDenoter* t2AST, Expression* eAST, SourcePosition* thePosition) : Declaration(thePosition) 
	{
		O = opAST;
		P1 = new VarFormalParameter(i1AST, t1AST, thePosition);
		D = new UnaryOperatorDeclaration(opAST, t1AST, t2AST, thePosition);
		T = t2AST;
		E = eAST;
	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitFuncUnaryOpDeclaration(this, o);
	}
	
	string class_type(){
		string temp = "FUNCUNARYOPDECLARATION";
		return temp;
	}  
};

#endif
