#ifndef _EnumTypeDenoter
#define _EnumTypeDenoter

#include "./AST/AST.h"
#include "SourcePosition.h"
#include "./AST/TypeDenoter.h"
#include <string>
using namespace std;


class EnumTypeDenoter : public TypeDenoter 
{
public:
	EnumTypeDenoter (SourcePosition* thePosition):TypeDenoter(thePosition){};

	Object* visit (Visitor* v, Object* o) {
		return v->visitEnumTypeDenoter(this, o);
	}
	
	bool equals (Object* obj) {
		if (obj != NULL && obj->class_type() == "ERRORTYPEDENOTER")
			return true;
		else
			return (obj != NULL && obj->class_type() == "ENUMTYPEDENOTER");
	}

    string class_type(){
		string temp = "ENUMTYPEDENOTER";
		return temp;
	}
};

#endif


