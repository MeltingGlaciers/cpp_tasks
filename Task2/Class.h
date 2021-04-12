#pragma once
#include <string>
#include "CodeElement.h"
#include "TypeEnum.h"
#include "Field.h"
#include "Class.h"
#include "Property.h"
#include "Method.h"

using namespace std;

class Class : public CodeElement {

private:
    AccessModifier am;
    vector<Class*> extends;
    vector<Class*> implements;
    ClassType ct;
    vector<CodeElement*> elements; //dynamic cast

public:

    Class(string, AccessModifier, ClassType);
    ~Class();

    void extend(Class*);

    void implement(Class*);

    void addElement(CodeElement*);

    void deleteElement(int);

    CodeElement* getElementAt(int);

    int getElementAmount();

    string toString();


};
