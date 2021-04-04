#pragma once
#include <iostream>
#include <string>
#include <list>
#include "NameSpace.h"
#include "Class.h"
#include "Field.h"
#include "Property.h"
#include "Method.h"
#include "TypeEnum.h"
#include "Parameter.h"
using namespace std;
class Controller {

	vector<NameSpace> namespaces;
	vector<Class> classes;
	vector<Field> fields;
	vector<Property> props;
	vector<Method> meths;
	NameSpace* ns;
	Class* cls;
	Method* meth;

public:
	Controller() {}

	int readIdxAsParameter(string, int);

	int readIdx(string , int);

	void run();

	void createNS();

	void progLevel();

	void deleteNS(int);

	void selectNS(int);

	void seeAllNS();

	void nsLevel();

	void deleteCls(int);

	void createCls();

	void selectCls(int);

	void seeAllClasses();

	void seeAllClasses(int);

	void classLevel();

	void addImplementation();

	void addExtension();

	void seeAllFields();

	void seeAllProperties();

	void seeAllMethods();

	void createField();

	void createMethod();

	void createProperty();

	void deleteField(int);

	void deleteProperty(int);

	void deleteMethod(int);
	
	void selectMethod(int);

	void methodLevel();

	void seeAllParameters();

	void addParameter();

	void deleteParameter(int);

};

