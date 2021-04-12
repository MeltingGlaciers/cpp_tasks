#include "NameSpace.h"

NameSpace::NameSpace(string str) : CodeElement(str){
	classes.reserve(20);
}

NameSpace::~NameSpace()
{
	for (Class* c : classes)
		delete c;
}

void NameSpace::addClass(Class* cls)
{
	classes.push_back(move(cls));
}

int NameSpace::getClassAmount()
{
	return classes.size();
}

Class* NameSpace::getClassAt(int idx)
{
	return classes.at(idx);
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
