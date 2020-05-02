#ifndef _RecTypeDeclaration
#define _RecTypeDeclaration

#include "./AST/Identifier.h"
#include "./AST/Declaration.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class RecTypeDeclaration: public Declaration {

public:
    Identifier *I;
    TypeDenoter *T;

    RecTypeDeclaration (Identifier *iAST, TypeDenoter *tAST, SourcePosition* thePosition): Declaration(thePosition) {
        I = iAST;
        T = tAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitRecTypeDeclaration(this, o);
    }

    string class_type()	{
        string temp = "RECTYPEDECLARATION";
        return temp;
    }
};

#endif
