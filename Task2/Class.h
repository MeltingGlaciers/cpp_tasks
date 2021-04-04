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
    vector<Field*> fields;
    vector<Property*> properties;
    vector<Method*> methods;

public:

    Class(string, AccessModifier, ClassType);
    ~Class();

    void extend(Class*);

    void implement(Class*);

    void addField(Field*);

    void addProperty(Property*);


    void addMethod(Method*);

    void deleteField(int);

    void deleteProperty(int);

    void deleteMethod(int);

    vector<Field*> getFields();

    vector<Property*> getProperties();

    vector<Method*> getMethods();

    string toString();


};
