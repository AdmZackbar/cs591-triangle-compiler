#include <cstdio> 
#include <cstdlib> 
#include <string>
#include "./AST.h"
//#include "./AST/AST.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
using namespace std;

#ifndef _Vname
#define _Vname


class Vname : public AST {

public:
  bool variable, indexed;
  int offset;
  TypeDenoter* type;
  Vname (SourcePosition* thePosition): AST(thePosition) {
    variable = false;
    type = NULL;
  }

	string class_type()	{
		string temp = "VNAME";
		return temp;
	}

  
};


#endif
