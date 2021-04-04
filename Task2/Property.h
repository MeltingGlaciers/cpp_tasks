#pragma once
#include "Field.h"
#include "TypeEnum.h"
#include "Method.h"

class Property : public Field{

public: 
    Property(string, string, AccessModifier, bool);

    string toString();

};