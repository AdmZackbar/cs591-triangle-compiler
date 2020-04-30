#ifndef _ResultParameterInfo
#define _ResultParameterInfo

#include "./CodeGenerator/UnknownAddress.h"
#include "FormalParameter.h"

class ResultParameterInfo
{
    public:
    FormalParameter *param;
    UnknownAddress *mainLoc;
    int argSize;
    bool copyIn;

    ResultParameterInfo(FormalParameter *p, UnknownAddress *o, int size, bool copy)
    {
        param = p;
        mainLoc = o;
        argSize = size;
        copyIn = copy;
    }
};

#endif
