#ifndef _EmptyActualParameterSequence
#define _EmptyActualParameterSequence

#include "./AST/ActualParameterSequence.h"
#include "./AST/Object.h"
#include "SourcePosition.h"
#include <string>

using namespace std;

class EmptyActualParameterSequence : public ActualParameterSequence {

public:
	EmptyActualParameterSequence (SourcePosition* thePosition):ActualParameterSequence(thePosition) {};


  Object* visit(Visitor* v, Object* o) {
    return v->visitEmptyActualParameterSequence(this, o);
  }

  string class_type(){
		string temp = "EMPTYACTUALPARAMETERSEQUENCE";
		return temp;
	}

};


#endif
