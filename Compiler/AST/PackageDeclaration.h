#ifndef _PackageDeclaration
#define _PackageDeclaration

#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./ContextualAnalyzer/IdentificationTable.h"
#include "SourcePosition.h"
#include <string>
using namespace std;


class PackageDeclaration : public Declaration {

public:
    Identifier *I;
    Declaration *D1, *D2;
    IdentificationTable *Table;

    PackageDeclaration(Identifier* iAST, Declaration* d1AST, Declaration *d2AST, SourcePosition* thePosition): Declaration(thePosition) {
        I = iAST;
        D1 = d1AST;
        D2 = d2AST;
        Table = NULL;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitPackageDeclaration(this, o);
    }

    string class_type(){
        string temp = "PACKAGEDECLARATION";
        return temp;
    }  
};

#endif
