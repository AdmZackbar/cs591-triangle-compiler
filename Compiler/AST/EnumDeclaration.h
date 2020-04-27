#ifndef _EnumDeclaration
#define _EnumDeclaration

#include "./AST/Identifier.h"
#include "./AST/Declaration.h"
#include "SourcePosition.h"
#include <string>
#include <vector>
using namespace std;

class EnumDeclaration : public Declaration {

public:
    Identifier *EnumName;
    vector<Identifier *> I;

	EnumDeclaration (Identifier *nameAST, vector<Identifier *> iASTs, SourcePosition* thePosition): Declaration(thePosition) {
        EnumName = nameAST;
        I = iASTs;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitEnumDeclaration(this, o);
    }

	string class_type()	{
		string temp = "ENUMDECLARATION";
		return temp;
	}
};

#endif
