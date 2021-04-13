#include "Controller.h"

int Controller::readIdxAsParameter(string str, int bound)
{
	int idx = stoi(str.substr(3, str.npos));
	if (str.at(2) == '-' && idx != 0) {
		if (bound > idx - 1) {
			return idx - 1;
		}
		else
			return -1;
	}
	else
		return -2;
}

int Controller::readIdx(string str, int bound)
{
	int idx = stoi(str);
	if (idx != 0) {
		if (bound > idx - 1) {
			return idx - 1;
		}
		else
			return -1;
	}
	else
		return -2;
}

void Controller::testRun()
{
	NameSpace nsp("123");
	namespaces.push_back(nsp);
	ns = &namespaces.at(0);
	Class* i = new Class("inter", NO_MODIF, INTERFACE);
	Class* c = new Class("cls", NO_MODIF, NO_TYPE);
	ns->addClass(i);
	ns->addClass(c);
	cls = c;
	addImplementation();
	addImplementation();
	cout<<cls->toString();


}

void Controller::run()
{

	cout << "First of all, create namespace\n";
	createNS();
	progLevel();
}

void Controller::createNS()
{
	cout << "Enter namespace name:\n";
	string name;
	cin >> name;
	NameSpace ns(name);
	namespaces.push_back(ns);
	cin.ignore();
}

void Controller::progLevel()
{
	cout << "a: see all namespaces\n";
	cout << "c: create namespace\n";
	cout << "i -<num>: select namespace\n";
	cout << "d -<num>: delete namespace\n";
	string c;
	int idx;
	bool input = true;
	while (input) {
		c.clear();

		cin.clear();
		getline(cin, c);
		cout << endl;
		switch (c.at(0)) {

		case 'a':
			seeAllNS();
			break;
		case 'c':
			createNS();
			break;
		case 'i':
			idx = readIdxAsParameter(c, namespaces.size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid parameter\n";
				break;
			default:
				selectNS(idx);
				//input = false;
				break;
			}
			break;
		case 'd':
			idx = readIdxAsParameter(c, namespaces.size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid parameter\n";
				break;
			default:
				deleteNS(idx);
				break;
			}
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void Controller::deleteNS(int idx)
{
	namespaces.erase(namespaces.begin() + idx);
}

void Controller::selectNS(int idx)
{
	this->ns = &namespaces.at(idx);
	nsLevel();
}

void Controller::seeAllNS()
{
	cout << "Namespaces:\n";
	for (int i = 0; i < namespaces.size(); i++) {
		cout << i + 1 << ": " << namespaces.at(i).getName() << endl;
	}
}

void Controller::nsLevelHelp()
{
	cout << "a: see all classes\n";
	cout << "c: create class\n";
	cout << "i -<num>: select class\n";
	cout << "d -<num>: delete class\n";
	cout << "b: back\n";
	cout << "s: print code\n";
	cout << "h: help\n";
}

void Controller::nsLevel()
{
	cout << "<<<NameSpace " << ns->getName() << ">>>\n";
	nsLevelHelp();
	string c;
	int idx;
	bool input = true;
	while (input) {
		c.clear();

		cin.clear();
		getline(cin, c);
		cout << endl;
		switch (c.at(0)) {

		case 'a':
			seeAllClasses();
			break;
		case 'c':
			createCls();
			break;
		case 'i':
			idx = readIdxAsParameter(c, ns->getClassAmount());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid parameter\n";
			default:
				selectCls(idx);
				break;
			}
			break;
		case 'd':
			idx = readIdxAsParameter(c, ns->getClassAmount());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid parameter\n";
			default:
				deleteCls(idx);
				break;
			}
			break;
		case 'b':
			//ns = NULL;
			input = false;
			break;
		case 's':
			cout << ns->toString() << endl;
			nsLevel();
			input = !input;
			break;
		case 'h':
			nsLevelHelp();
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void Controller::deleteCls(int idx)
{
	ns->deleteClass(idx);
}

void Controller::createCls()
{
	cout << "Enter name:\n";
	string name;
	cin.clear();
	getline(cin, name);
	cout << "Choose access modifier:\n";
	cout << "u: public\n";
	cout << "r: private\n";
	cout << "a: protected\n";
	cout << "w: without\n";
	char c;
	AccessModifier am;
	bool input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'u':
			am = PUBLIC;
			input = false;
			break;
		case 'r':
			am = PRIVATE;
			input = false;
			break;
		case 'a':
			am = PROTECTED;
			input = false;
			break;
		case 'w':
			am = NO_MODIF;
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}

	}

	cout << "Choose class type:\n";
	cout << "a: abstract\n";
	cout << "i: interface\n";
	cout << "w: without\n";
	ClassType ct;
	input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'a':
			ct = ABSTRACT;
			input = false;
			break;
		case 'i':
			ct = INTERFACE;
			input = false;
			break;
		case 'w':
			ct = NO_TYPE;
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}

	}

	Class* createdClass = new Class(name, am, ct);
	ns->addClass(createdClass);
	cin.ignore();
}

void Controller::selectCls(int idx)
{
	cls = ns->getClassAt(idx);
	classLevel();
}

void Controller::seeAllClasses()
{
	cout << "Classes:\n";
	for (int i = 0; i < ns->getClassAmount();i++) {
		cout << i+1 << ": " << ns->getClassAt(i)->getName() << endl;
	}
}

void Controller::seeAllClasses(int idx)
{
	cout << "Classes:\n";
	NameSpace* nsp = &namespaces.at(idx);
	for (int i = 0; i < nsp->getClassAmount(); i++) {
		Class* c = nsp->getClassAt(i);
		cout << i + 1 << ": " << namespaces.at(idx).getClassAt(i)->getName() << endl;
	}
}

void Controller::classLevelHelp()
{
	cout << "f: see all elements\n";
	cout << "l: create field\n";
	cout << "v: create property\n";
	cout << "o: create method\n";
	cout << "i: implement\n";
	cout << "e: extend\n";
	cout << "t -<num>: select element\n";
	cout << "n -<num>: delete implementation\n";
	cout << "k -<num>: delete extension\n";
	cout << "d -<num>: delete element\n";
	cout << "b: back\n";
	cout << "s: print code\n";
	cout << "h: help\n";
}

void Controller::classLevel()
{
	cout << "<<<Class " << cls->getName() << ">>>\n";
	classLevelHelp();

	string c;
	int idx;
	bool input = true;
	while (input) {
		c.clear();

		cin.clear();
		getline(cin, c);
		cout << endl;
		switch (c.at(0)) {

		case 'f':
			seeAllElements();
			break;
		case 'l':
			createField();
			break;
		case 'v':
			createProperty();
			break;
		case 'o':
			createMethod();
			break;
		case 'i':
			addImplementation();
			break;
		case 'e':
			addExtension();
			break;
		case 't':
			idx = readIdxAsParameter(c, cls->getElementAmount());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				selectElement(idx);
				break;
			}
			break;
		case 'd':
			idx = readIdxAsParameter(c, cls->getElementAmount());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				deleteElement(idx);
				input = false;
				break;
			}
			break;
		case 'b':
			cls = NULL;
			input = false;
			break;
		case 's':
			cout << cls->toString() << endl;
			break;
		case 'h':
			classLevelHelp();
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void Controller::addImplementation()
{
	cout << "Choose ";
	NameSpace* n;
	Class* cs;
	seeAllNS();
	string c;
	int idx;
	bool input = true;
	while (input) {
		cin >> c;
		idx = readIdx(c, namespaces.size());
		switch (idx) {
		case -1:
			cout << "out of bounds\n";
			break;
		case -2:
			cout << "invalid input\n";
			break;
		default:
			cin.ignore();
			n = &namespaces.at(idx);
			cout << "Choose ";
			seeAllClasses(idx);
			while (input) {
				cin >> c;
				idx = readIdx(c, n->getClassAmount());
				switch (idx) {
				case -1:
					cout << "out of bounds\n";
					break;
				case -2:
					cout << "invalid input\n";
					break;
				default:
					cs = n->getClassAt(idx);
					try {
						cls->implement(cs);
					}
					catch (exception) {
						cout << "selected class isn't interface\n";
					}
					input = false;
					cin.ignore();
					break;
				}
			}

			input = false;
			break;
		}
	}
}

void Controller::addExtension()
{
	cout << "Choose ";
	NameSpace* n;
	Class* cs;
	seeAllNS();
	string c;
	int idx;
	bool input = true;
	while (input) {
		cin >> c;
		idx = readIdx(c, namespaces.size());
		switch (idx) {
		case -1:
			cout << "out of bounds\n";
			break;
		case -2:
			cout << "invalid input\n";
			break;
		default:
			cin.ignore();
			n = &namespaces.at(idx);
			cout << "Choose ";
			seeAllClasses(idx);
			while (input) {
				cin >> c;
				idx = readIdx(c, n->getClassAmount());
				switch (idx) {
				case -1:
					cout << "out of bounds\n";
					break;
				case -2:
					cout << "invalid input\n";
					break;
				default:
					cs = n->getClassAt(idx);

					cls->extend(cs);

					input = false;
					cin.ignore();
					break;
				}
			}

			input = false;
			break;
		}
	}
}

void Controller::seeAllElements()
{
	cout << "Elements:\n";
	for (int i=0;i<cls->getElementAmount();i++)
		cout << i+1 << ": " << cls->getElementAt(i)->getName() << endl;
		
}

void Controller::createField()
{
	cout << "Enter name:\n";
	string name;
	string type;
	cin.clear();
	getline(cin, name);
	cout << "Enter type:\n";
	cin.clear();
	getline(cin, type);
	cout << "Choose access modifier:\n";
	cout << "u: public\n";
	cout << "r: private\n";
	cout << "a: protected\n";
	cout << "w: without\n";
	char c;
	AccessModifier am;
	bool input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'u':
			am = PUBLIC;
			input = false;
			break;
		case 'r':
			am = PRIVATE;
			input = false;
			break;
		case 'a':
			am = PROTECTED;
			input = false;
			break;
		case 'w':
			am = NO_MODIF;
			input = false;
			break;
		default:
			cout << "invalid input\n";
			cin.ignore();
			break;
		}

	}
	cout << "Is static? (y/n)\n";
	bool isStatic = false;
	input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'y':
			isStatic = true;
			input = false;
			break;
		case 'n':
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
	Field* f = new Field(name, type, am, isStatic);
	cls->addElement(f);
	cin.ignore();
}

void Controller::createMethod()
{
	cout << "Enter name:\n";
	string name;
	string type;
	cin.clear();
	getline(cin, name);
	cout << "Enter return type:\n";
	cin.clear();
	getline(cin, type);
	cout << "Choose access modifier:\n";
	cout << "u: public\n";
	cout << "r: private\n";
	cout << "a: protected\n";
	cout << "w: without\n";
	char c;
	AccessModifier am;
	bool input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'u':
			am = PUBLIC;
			input = false;
			break;
		case 'r':
			am = PRIVATE;
			input = false;
			break;
		case 'a':
			am = PROTECTED;
			input = false;
			break;
		case 'w':
			am = NO_MODIF;
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}

	}
	cout << "Is static? (y/n)\n";
	bool isStatic = false;
	input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'y':
			isStatic = true;
			input = false;
			break;
		case 'n':
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
	Method* m = new Method(name, type, am, isStatic);
	cls->addElement(m);
	cin.ignore();
}

void Controller::createProperty()
{
	cout << "Enter name:\n";
	string name;
	string type;
	cin.clear();
	getline(cin, name);
	cout << "Enter type:\n";
	cin.clear();
	getline(cin, type);
	cout << "Choose access modifier:\n";
	cout << "u: public\n";
	cout << "r: private\n";
	cout << "a: protected\n";
	cout << "w: without\n";
	char c;
	AccessModifier am;
	bool input = true;;
	while (input) {
		cin >> c;
		switch (c) {
		case 'u':
			am = PUBLIC;
			input = false;
			break;
		case 'r':
			am = PRIVATE;
			input = false;
			break;
		case 'a':
			am = PROTECTED;
			input = false;
			break;
		case 'w':
			am = NO_MODIF;
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}

	}
	cout << "Is static? (y/n)\n";
	bool isStatic = false;
	input = true;
	while (input) {
		cin >> c;
		switch (c) {
		case 'y':
			isStatic = true;
			input = false;
			break;
		case 'n':
			input = false;
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
	Property* p = new Property(name, type, am, isStatic);
	cls->addElement(p);
	cin.ignore();
}

void Controller::deleteElement(int idx)
{
	cls->deleteElement(idx);
}

void Controller::selectElement(int idx)
{
	try {
		meth = dynamic_cast<Method*>(cls->getElementAt(idx));
		methodLevel();
	}
	catch (const bad_cast& e) {
		cout << "Only methods can be chosen as context\n";
	}
}

void Controller::methodLevelHelp()
{
	cout << "a: see all parameters\n";
	cout << "c: add parameter\n";
	cout << "d -<num>: delete parameter\n";
	cout << "b: back\n";
	cout << "s: print code\n";
	cout << "h: help\n";
}

void Controller::methodLevel()
{
	cout << "<<<Method " << meth->getName() << ">>>\n";
	methodLevelHelp();
	string c;
	int idx;
	bool input = true;
	while (input) {
		c.clear();

		cin.clear();
		getline(cin, c);
		cout << endl;
		switch (c.at(0)) {

		case 'a':
			seeAllParameters();
			break;
		case 'c':
			addParameter();
			break;
		case 'd':
			idx = readIdxAsParameter(c, cls->getElementAmount());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid parameter\n";
			default:
				deleteParameter(idx);
				input = false;
				break;
			}
			break;
		case 'b':
			//ns = NULL;
			input = false;
			break;
		case 's':
			cout << meth->toString() << endl;
			break;
		case 'h':
			methodLevelHelp();
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void Controller::seeAllParameters()
{
	int i = 1;
	for (Parameter* p : meth->getParameters())
		cout << i << ": " << p->getName() << endl;
}

void Controller::addParameter()
{
	cout << "Enter name:\n";
	string name;
	string type;
	cin.clear();
	getline(cin, name);
	cout << "Enter type:\n";
	cin.clear();
	getline(cin, type);

	Parameter* p = new Parameter(name, type);
	meth->addParameter(p);
}

void Controller::deleteParameter(int idx)
{
	meth->deleteParameter(idx);
}
