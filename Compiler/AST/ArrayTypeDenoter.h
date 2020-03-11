#ifndef _ArrayTypeDenoter
#define _ArrayTypeDenoter


#include "./AST/AST.h"
#include "./AST/TypeDenoter.h"
#include "./AST/IntegerLiteral.h"
#include "SourcePosition.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class ArrayTypeDenoter :public TypeDenoter {

public:
	
  IntegerLiteral* IL;
  TypeDenoter* T;

	ArrayTypeDenoter (IntegerLiteral* ilAST, TypeDenoter* tAST,SourcePosition* thePosition):TypeDenoter(thePosition) {
    IL = ilAST;
    T = tAST;
  }


	Object* visit(Visitor* v, Object* o) {
		return v->visitArrayTypeDenoter((Object*)this, o);
	}

	bool equals (Object* obj) 
	{
		if (obj != NULL && obj->class_type() == "ERRORTYPEDENOTER")
			return true;
		else if (obj != NULL && obj->class_type() == "ARRAYTYPEDENOTER")
			return	(this->IL->spelling == ((ArrayTypeDenoter*)obj)->IL->spelling) && 
					(this->T == ((ArrayTypeDenoter*)obj)->T);
		else
			return false;
	}

	string class_type(){
	string temp = "ARRAYTYPEDENOTER";
	return temp;
}

};

#endif
