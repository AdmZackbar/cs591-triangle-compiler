#ifndef _CallCommand
#define _CallCommand

#include "./AST/Command.h"
#include "./AST/ActualParameterSequence.h"
#include "./AST/Identifier.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;


class CallCommand : public Command {

public:
	Identifier* I;
	ActualParameterSequence* APS;

	CallCommand (Identifier* iAST, ActualParameterSequence* apsAST,SourcePosition* thePosition):Command(thePosition) {
    I = iAST;
    APS = apsAST;
  }


  Object* visit(Visitor* v, Object* o) {
    return v->visitCallCommand(this, o);
  }

  string class_type(){
	string temp = "CALLCOMMAND";
	return temp;
	}

  
};

#endif
