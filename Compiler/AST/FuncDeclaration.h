#ifndef _FuncDeclaration
#define _FuncDeclaration

#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./AST/FormalParameterSequence.h"
#include "./AST/TypeDenoter.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class FuncDeclaration : public Declaration 
{
public:

	Identifier* I;
	FormalParameterSequence* FPS;
	TypeDenoter* T;
	Expression* E;

	FuncDeclaration (Identifier* iAST, FormalParameterSequence* fpsAST,
  		   TypeDenoter* tAST, Expression* eAST,
		   SourcePosition* thePosition) : Declaration(thePosition) 
	{   
		I = iAST;
		FPS = fpsAST;
		T = tAST;
		E = eAST;
	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitFuncDeclaration(this, o);
	}
	
	string class_type(){
		string temp = "FUNCDECLARATION";
		return temp;
	}  
};

#endif
