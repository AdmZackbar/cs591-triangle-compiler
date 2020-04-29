#include <cstdio> 
#include <cstdlib> 
#include <string>
#include "./AST/AST.h"
#include "./AST/Identifier.h"
#include "./AST/Vname.h"
#include "SourcePosition.h"


using namespace std;

#ifndef _PackageVname
#define _PackageVname

class PackageVname : public Vname {

public:
    Identifier* I;
    Vname* V;

    PackageVname (Vname* vAST, Identifier* iAST, SourcePosition* thePosition): Vname(thePosition) {
        V = vAST;
        I = iAST;
    }

    Object* visit (Visitor* v, Object* o) {
        return v->visitPackageVname(this, o);
    }

    string class_type(){
        string temp = "PACKAGEVNAME";
        return temp;
    }
  
};

#endif
