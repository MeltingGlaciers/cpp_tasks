#pragma once
#include "TypeEnum.h"
#include "Parameter.h"
#include <iostream>
#include <string>
#include <vector>
class Method : public CodeElement {

private:
    std::string returnType;
    AccessModifier am;
    bool isStatic;
    vector<Parameter*> input;

public:
    Method(std::string name, std::string returnType, AccessModifier am, bool isStatic);

    ~Method();

    void addParameter(Parameter*);

    void deleteParameter(int);

    std::string getReturnType();

    vector<Parameter*> getParameters();

    std::string toString();

};