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
    Identifier *I;
    Expression *E;

	VarDeclCommand (Identifier *iAST, Expression *eAST, SourcePosition* thePosition): Command(thePosition) {
        I = iAST;
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
