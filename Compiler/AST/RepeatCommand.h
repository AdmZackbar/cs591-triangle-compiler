#ifndef _RepeatCommand
#define _RepeatCommand

#include "./AST/Command.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class RepeatCommand : public Command {

public:
    Command* C;
	Expression* E;

	RepeatCommand (Command* cAST, Expression* eAST, SourcePosition* thePosition): Command(thePosition) {
        C = cAST;
        E = eAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitRepeatCommand(this, o);
    }

	string class_type()	{
		string temp = "REPEATCOMMAND";
		return temp;
	}
};

#endif
