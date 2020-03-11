#ifndef _FieldTypeDenoter
#define _FieldTypeDenoter


#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include "./AST/Object.h"
#include <string>

using namespace std;

class FieldTypeDenoter : public TypeDenoter {

public:
	FieldTypeDenoter(SourcePosition* thePosition): TypeDenoter(thePosition){};

string class_type(){
	string temp = "FIELDTYPEDENOTER";
	return temp;
	}
	
bool equals (Object* obj){
 
	if ( obj->class_type() == "FIELDTYPEDENOTER" )
		return true;
	
	else
		return false;

}
	

};

#endif
