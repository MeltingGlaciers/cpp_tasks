#include "Parameter.h"

Parameter::Parameter(string name, string type) : CodeElement(name) {

    CodeElement::name = name;
    this->type = type;

}

string Parameter::toString()
{
    string str = "";
    str.append(type + " " + name);
    return str;
}
