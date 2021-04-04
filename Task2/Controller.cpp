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
			cout << idx - 1 << endl;
			return idx - 1;
		}
		else
			return -1;
	}
	else
		return -2;
}

void Controller::run()
{
	classes.reserve(20);
	fields.reserve(40);
	props.reserve(40);
	meths.reserve(40);

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
	int i = 1;
	cout << "Namespaces:\n";
	for (NameSpace ns : namespaces) {
		cout << i << ": " << ns.getName() << endl;
		i++;
	}
}

void Controller::nsLevel()
{
	cout << "<<<NameSpace " << ns->getName() << ">>>\n";
	cout << "a: see all classes\n";
	cout << "c: create class\n";
	cout << "i -<num>: select class\n";
	cout << "d -<num>: delete class\n";
	cout << "b: back\n";
	cout << "s: print code\n";
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
			idx = readIdxAsParameter(c, ns->getClasses().size());
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
			idx = readIdxAsParameter(c, ns->getClasses().size());
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
			ns = NULL;
			input = false;
			break;
		case 's':
			cout << ns->toString() << endl;
			nsLevel();
			input = !input;
			break;
		default:
			cout << "invalid input\n";
			break;
		}
	}
}

void Controller::deleteCls(int idx)
{
	Class* c = ns->getClasses().at(idx);
	ns->deleteClass(idx);
	classes.erase(classes.begin() + (c - &classes[0]));
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

	Class cls(name, am, ct);
	classes.push_back(cls);
	ns->addClass(&classes.back());
	cin.ignore();

}

void Controller::selectCls(int idx)
{
	cls = ns->getClasses().at(idx);
	classLevel();
}

void Controller::seeAllClasses()
{
	int i = 1;
	cout << "Classes:\n";
	for (Class* cls : ns->getClasses()) {
		cout << i << ": " << cls->getName() << endl;
		i++;
	}
}

void Controller::seeAllClasses(int idx)
{
	int i = 1;
	cout << "Classes:\n";
	for (Class* cls : namespaces.at(idx).getClasses()) {
		cout << i << ": " << cls->getName() << endl;
		i++;
	}
}

void Controller::classLevel()
{
	cout << "<<<Class " << cls->getName() << ">>>\n";
	cout << "f: see all fields\n";
	cout << "p: see all properties\n";
	cout << "m: see all methods\n";
	cout << "l: create field\n";
	cout << "v: create property\n";
	cout << "o: create method\n";
	cout << "h: implement\n";
	cout << "j: extend\n";
	cout << "t -<num>: select method\n";
	cout << "n -<num>: delete implementation\n";
	cout << "k -<num>: delete extension\n";
	cout << "i -<num>: delete field\n";
	cout << "r -<num>: delete property\n";
	cout << "e -<num>: delete methods\n";
	cout << "b: back\n";
	cout << "s: print code\n";

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
			seeAllFields();
			break;
		case 'p':
			seeAllProperties();
			break;
		case 'm':
			seeAllMethods();
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
		case 'h':
			addImplementation();
			break;
		case 'j':
			addExtension();
			break;
		case 't':
			idx = readIdxAsParameter(c, cls->getMethods().size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				selectMethod(idx);
				break;
			}
			break;
		case 'i':
			idx = readIdxAsParameter(c, cls->getFields().size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				deleteField(idx);
				input = false;
				break;
			}
			break;
		case 'r':
			idx = readIdxAsParameter(c, cls->getProperties().size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				deleteProperty(idx);
				input = false;
				break;
			}
			break;
		case 'e':
			idx = readIdxAsParameter(c, cls->getMethods().size());
			switch (idx) {
			case -1:
				cout << "out of bounds\n";
				break;
			case -2:
				cout << "invalid paramater\n";
				break;
			default:
				deleteMethod(idx);
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
				idx = readIdx(c, n->getClasses().size());
				switch (idx) {
				case -1:
					cout << "out of bounds\n";
					break;
				case -2:
					cout << "invalid input\n";
					break;
				default:
					cs = n->getClasses().at(idx);
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
				idx = readIdx(c, n->getClasses().size());
				switch (idx) {
				case -1:
					cout << "out of bounds\n";
					break;
				case -2:
					cout << "invalid input\n";
					break;
				default:
					cs = n->getClasses().at(idx);

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

void Controller::seeAllFields()
{
	int i = 1;
	for (Field* f : cls->getFields())
		cout << i << ": " << f->getName() << endl;
}

void Controller::seeAllProperties()
{
	int i = 1;
	for (Property* p : cls->getProperties())
		cout << i << ": " << p->getName() << endl;
}

void Controller::seeAllMethods()
{
	int i = 1;
	for (Method* m : cls->getMethods())
		cout << i << ": " << m->getName() << endl;
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
			break;
		}

	}
	cout << "Is static? (y/n)\n";
	bool isStatic = false;
	cin >> c;
	input = true;;
	while (input) {
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
	Field f(name, type, am, isStatic);
	fields.push_back(f);
	cls->addField(&fields.back());
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
	cin >> c;
	input = true;;
	while (input) {
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
	Method m(name, type, am, isStatic);
	meths.push_back(m);
	cls->addMethod(&meths.back());
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
	cin >> c;
	input = true;;
	while (input) {
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
	Property f(name, type, am, isStatic);
	props.push_back(f);
	cls->addField(&props.back());
	cin.ignore();
}

void Controller::deleteField(int idx)
{
	Field* f = cls->getFields().at(idx);
	cls->deleteField(idx);
	fields.erase(fields.begin() + (f - &fields[0]));
}

void Controller::deleteProperty(int idx)
{
	Property* p = cls->getProperties().at(idx);
	cls->deleteProperty(idx);
	props.erase(props.begin() + (p - &props[0]));
}

void Controller::deleteMethod(int idx)
{
	Method* m = cls->getMethods().at(idx);
	cls->deleteProperty(idx);
	meths.erase(meths.begin() + (m - &meths[0]));
}

void Controller::selectMethod(int idx)
{
	meth = cls->getMethods().at(idx);
	methodLevel();
}

void Controller::methodLevel()
{
	cout << "<<<Method " << meth->getName() << ">>>\n";
	cout << "a: see all parameters\n";
	cout << "c: add parameter\n";
	cout << "d -<num>: delete parameter\n";
	cout << "b: back\n";
	cout << "s: print code\n";
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
			idx = readIdxAsParameter(c, cls->getMethods().size());
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
			ns = NULL;
			input = false;
			break;
		case 's':
			cout << meth->toString() << endl;
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
	for (Parameter p : meth->getParameters())
		cout << i << ": " << p.getName() << endl;
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

	Parameter p(name, type);
	meth->addParameter(p);
}

void Controller::deleteParameter(int idx)
{
	meth->deleteParameter(idx);
}
