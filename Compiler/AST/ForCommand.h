#ifndef _ForCommand
#define _ForCommand

#include "./AST/ConstDeclaration.h"
#include "./AST/Command.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class ForCommand : public Command {

public:
    ConstDeclaration *D;
	Expression *E; 
    Command *C;

	ForCommand (ConstDeclaration *dAST, Expression* eAST, Command* cAST, SourcePosition* thePosition): Command(thePosition) {
        D = dAST;
        E = eAST;
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
