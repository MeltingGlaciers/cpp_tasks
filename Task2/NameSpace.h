#pragma once
#include <string>
#include "CodeElement.h"
#include "Class.h"

class NameSpace : public CodeElement {
private:
    vector<Class*> classes;

public:

    NameSpace(string);
    ~NameSpace();

    void addClass(Class*);

    int getClassAmount();

    Class* getClassAt(int);

    void deleteClass(int);

    string toString();
};

