#ifndef _FuncBinOpDeclaration
#define _FuncBinOpDeclaration

#include "./AST/Operator.h"
#include "./AST/VarFormalParameter.h"
#include "./AST/BinaryOperatorDeclaration.h"
#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./AST/TypeDenoter.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class FuncBinOpDeclaration : public Declaration 
{
public:
	Operator *O;
	VarFormalParameter *P1, *P2;
	BinaryOperatorDeclaration *D;
	TypeDenoter *T;
	Expression* E;

	FuncBinOpDeclaration (Operator *opAST, Identifier* i1AST, TypeDenoter* t1AST, Identifier* i2AST, TypeDenoter* t2AST,
						  TypeDenoter* t3AST, Expression* eAST, SourcePosition* thePosition) : Declaration(thePosition) 
	{
		O = opAST;
		P1 = new VarFormalParameter(i1AST, t1AST, thePosition);
		P2 = new VarFormalParameter(i2AST, t2AST, thePosition);
		D = new BinaryOperatorDeclaration(opAST, t1AST, t2AST, t3AST, thePosition);
		T = t3AST;
		E = eAST;
	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitFuncBinOpDeclaration(this, o);
	}
	
	string class_type(){
		string temp = "FUNCBINOPDECLARATION";
		return temp;
	}  
};

#endif
