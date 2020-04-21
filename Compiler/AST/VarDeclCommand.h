#ifndef _VarDeclCommand
#define _VarDeclCommand

#include "./AST/Identifier.h"
#include "./AST/Expression.h"
#include "./AST/Command.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class VarDeclCommand : public Command {

public:
    Vname *V;
    Expression *E;

	VarDeclCommand (Vname *vAST, Expression *eAST, SourcePosition* thePosition): Command(thePosition) {
        V = vAST;
        E = eAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitVarDeclCommand(this, o);
    }

	string class_type()	{
		string temp = "VARDECLCOMMAND";
		return temp;
	}
};

#endif
