#ifndef _EnumCommand
#define _EnumCommand

#include "./AST/Identifier.h"
#include "./AST/Command.h"
#include "SourcePosition.h"
#include <string>
#include <vector>
using namespace std;

class EnumCommand : public Command {

public:
    Identifier *EnumName;
    vector<Identifier *> I;

	EnumCommand (Identifier *nameAST, vector<Identifier *> iASTs, SourcePosition* thePosition): Command(thePosition) {
        EnumName = nameAST;
        I = iASTs;
    }

    Object* visit(Visitor* v, Object* o) {
        return v->visitEnumCommand(this, o);
    }

	string class_type()	{
		string temp = "ENUMCOMMAND";
		return temp;
	}
};

#endif
