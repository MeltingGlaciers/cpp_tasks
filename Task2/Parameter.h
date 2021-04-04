#pragma once
#include <string>
#include "CodeElement.h"
using namespace std;

class Parameter : public CodeElement {

protected:
    string type;

public:

    Parameter(string, string);

    string toString();

};