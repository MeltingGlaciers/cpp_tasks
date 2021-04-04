#include "Property.h"

Property::Property(string name, string type, AccessModifier am, bool isStatic) : Field(name, type, am, isStatic) {
}

string Property::toString()
{
    string str = "";
    str.append(Field::toString());
    str.pop_back();
    str.append("{get; set;}");
    return str;
}
