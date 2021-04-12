#include "Method.h"
using namespace std;
Method::Method(string name, string returnType, AccessModifier am, bool isStatic) 
    : CodeElement(name) {

    this->returnType = returnType;
    this->am = am;
    this->isStatic = isStatic;

}

Method::~Method()
{
    for (Parameter* p : input)
        delete p;

}

void Method::addParameter(Parameter* param) {
    input.push_back(param);
}

void Method::deleteParameter(int idx) {
    input.erase(input.begin() + idx, input.begin() + idx);

}

std::string Method::getReturnType() {
    return returnType;
}

vector<Parameter*> Method::getParameters() {
    vector<Parameter*> newVec;

    copy(input.begin(), input.end(), back_inserter(newVec));
    return newVec;
}

string Method::toString() {
    string str = "";

    str.append(AccessModifierToString(am)).append(" ");

    if (isStatic)
        str.append("static ");

    str.append(returnType + " " + name + "(");

    for (int i = 0; i < input.size(); i++) {
        str.append(input.at(i)->toString() + ", ");
    }
    str.pop_back();
    str.pop_back();
    str.append("){\n}");
    return str;
}
