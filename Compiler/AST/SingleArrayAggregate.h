#ifndef _SingleArrayAggregate
#define _SingleArrayAggregate

#include "./AST/ArrayAggregate.h"
#include "./AST/Expression.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class SingleArrayAggregate : public ArrayAggregate 
{
public:
	
	Expression *E;
	SingleArrayAggregate (Expression* eAST,
		SourcePosition* thePosition):ArrayAggregate(thePosition) 
	{
		E = eAST;
	}

	Object* visit (Visitor* v, Object* o) {
		return v->visitSingleArrayAggregate(this, o);
	}
  
	string class_type()	{
		string temp = "SINGLEARRAYAGGREGATE";
		return temp;
	}  
};



#endif
