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
	NameSpace* ns;
	Class* cls;
	Method* meth;

public:
	Controller() {}

	int readIdxAsParameter(string, int);

	int readIdx(string , int);

	void testRun();

	void run();

	void createNS();

	void progLevel();

	void deleteNS(int);

	void selectNS(int);

	void seeAllNS();

	void nsLevelHelp();

	void nsLevel();

	void deleteCls(int);

	void createCls();

	void selectCls(int);

	void seeAllClasses();

	void seeAllClasses(int);

	void classLevelHelp();

	void classLevel();

	void addImplementation();

	void addExtension();

	void seeAllElements();

	void createField();

	void createMethod();

	void createProperty();

	void deleteElement(int);
	
	void selectElement(int);

	void methodLevelHelp();

	void methodLevel();

	void seeAllParameters();

	void addParameter();

	void deleteParameter(int);

};

