#ifndef _ForCommand
#define _ForCommand

#include "./AST/Identifier.h"
#include "./AST/Command.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class ForCommand : public Command {

public:
    Identifier *I;
	Expression *E1, *E2; 
    Command *C;

	ForCommand (Identifier *iAST, Expression* e1AST, Expression* e2AST, Command* cAST, SourcePosition* thePosition): Command(thePosition) {
        I = iAST;
        E1 = e1AST;
        E2 = e2AST;
        C = cAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitForCommand(this, o);
    }

	string class_type()	{
		string temp = "FORCOMMAND";
		return temp;
	}
};

#endif
