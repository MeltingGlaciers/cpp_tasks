#include <iostream>
#include <string>
#include "Controller.h"
using namespace std;

int main() {

    /*Class cls("Name", PUBLIC, NO_TYPE);
    Field f1("sas", "int", PUBLIC, false);
    Field f2("asa", "double", PRIVATE, false);

    Property p("Sas", "int", PUBLIC, true, NULL, NULL);

    Parameter a("a", "b");
    Parameter b("c", "d");
    Parameter* params[] = { &a, &b };
    Method m("func", "int", PRIVATE, true, params, 2);

    cls.addField(&f1);
    cls.addField(&f2);
    cls.addMethod(&m);
    cls.addProperty(&p);

    cout << cls.toString();*/

    Controller c;
    c.run();

    //cout << str[c - '0'];

}