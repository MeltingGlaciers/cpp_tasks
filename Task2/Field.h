#pragma once
#include "TypeEnum.h"
#include "Parameter.h"

class Field : public Parameter {

protected:
    AccessModifier am;
    bool isStatic;

public:
    Field(string, string, AccessModifier, bool);

    string toString();

};

