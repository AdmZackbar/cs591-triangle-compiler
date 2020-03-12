#ifndef _CaseCommand
#define _CaseCommand

#include "./AST/Expression.h"
#include "./AST/IntegerLiteral.h"
#include "./AST/Command.h"
#include "SourcePosition.h"
#include <string>
#include <vector>
using namespace std;

class CaseCommand : public Command {

public:
    Expression *E;
    vector<IntegerLiteral *> I;
    vector<Command *> C;
    Command *elseC;

	CaseCommand (Expression *eAST, vector<IntegerLiteral *> iASTs, vector<Command *> cASTs, Command *elseAST, SourcePosition* thePosition): Command(thePosition) {
        E = eAST;
        I = iASTs;
        C = cASTs;
        elseC = elseAST;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitCaseCommand(this, o);
    }

	string class_type()	{
		string temp = "CASECOMMAND";
		return temp;
	}
};

#endif
