#include "Field.h"

Field::Field(string name, string type, AccessModifier am, bool isStatic) : Parameter(name, type)
{
    this->am = am;
    this->isStatic = isStatic;
}

string Field::toString()
{
    string str = "";

    str.append(AccessModifierToString(am)).append(" ");

    if (isStatic)
        str.append("static ");

    str.append(type).append(" ");

    str.append(name).append(";");

    return str;
}
