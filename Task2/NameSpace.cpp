#include "NameSpace.h"

NameSpace::NameSpace(string str) : CodeElement(str){

}

NameSpace::~NameSpace()
{
	classes.clear();
}

void NameSpace::addClass(Class* cls)
{
	classes.push_back(move(cls));
}

vector<Class*> NameSpace::getClasses()
{
	vector<Class*> newVec;

	for (Class* c : classes)
		newVec.push_back(c);

	return newVec;
}

void NameSpace::deleteClass(int idx)
{
	classes.erase(classes.begin() + idx, classes.begin() + idx);
}

string NameSpace::toString()
{
	string str = "";
	str.append("namespace ").append(name).append("{\n");
	for (Class* cls : classes)
		str.append(cls->toString()).append("\n");

	str.append("}");
	return str;
}
