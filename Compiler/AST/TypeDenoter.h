#ifndef _TypeDenoter
#define _TypeDenoter

#include <cstdio> 
#include <cstdlib> 
#include <string>
#include "./AST/AST.h"
#include "SourcePosition.h"
using namespace std;


class TypeDenoter : public AST 
{
public:

	TypeDenoter(SourcePosition* thePosition):AST(thePosition){};

	virtual bool equals(Object* obj)
	{
		return false;
	}
};

#endif
