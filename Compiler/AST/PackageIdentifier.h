#ifndef _PackageIdentifier
#define _PackageIdentifier

#include "./AST/Identifier.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class PackageIdentifier: public Identifier
{
    public:
    Identifier *P;
    PackageIdentifier(Identifier *iAST, string spelling, SourcePosition *position): Identifier(spelling, position)
    {
        P = iAST;
    }

    Object* visit (Visitor* v, Object* o) {
        return v->visitPackageIdentifier(this, o);
    }

    string class_type()	{
        string temp = "PACKAGEIDENTIFIER";
        return temp;
    }
};

#endif
