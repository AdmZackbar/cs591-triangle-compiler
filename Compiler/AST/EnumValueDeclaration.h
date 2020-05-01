#ifndef _EnumValueDeclaration
#define _EnumValueDeclaration

#include "./AST/Identifier.h"
#include "./AST/EnumDeclaration.h"
#include "./AST/Declaration.h"

class EnumValueDeclaration : public Declaration
{
    public:
    Identifier *I;
    int value;
    EnumDeclaration *P;

    EnumValueDeclaration(Identifier *iAST, int index, EnumDeclaration *pAST, SourcePosition* thePosition): Declaration(thePosition)
    {
        I = iAST;
        value = index;
        P = pAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitEnumValueDeclaration(this, o);
    }

    string class_type()	{
        string temp = "ENUMVALUEDECLARATION";
        return temp;
    }
};

#endif
