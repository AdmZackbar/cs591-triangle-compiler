#ifndef _RecordAggregate
#define _RecordAggregate


#include "SourcePosition.h"
#include "./AST/AST.h"
#include "./AST/FieldTypeDenoter.h"
#include <string>
using namespace std;

class RecordAggregate : public AST {

public:
	FieldTypeDenoter* type;

	RecordAggregate (SourcePosition *thePosition): AST(thePosition) {
    type = NULL;
	}
};


#endif
