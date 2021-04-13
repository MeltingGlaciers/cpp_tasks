#include "Class.h"
#include <string>
#include <exception>
#include "TypeEnum.h"

Class::Class(string str, AccessModifier am, ClassType ct):CodeElement(str)
{

	this->am = am;
	this->ct = ct;
	elements.reserve(15);
}

Class::~Class()
{
	for (CodeElement* ce : elements)
		delete ce;
}

void Class::extend(Class* cls)
{
	extends.push_back(cls);
}

void Class::implement(Class* cls)
{
	if (cls->ct == INTERFACE)
		implements.push_back(cls);
	else throw exception();
}

void Class::addElement(CodeElement* ce)
{
	elements.push_back(ce);
}

void Class::deleteElement(int idx)
{
	elements.erase(elements.begin() + idx);
}

CodeElement* Class::getElementAt(int idx)
{
	return elements.at(idx);
}

int Class::getElementAmount()
{
	return elements.size();
}

string Class::toString()
{
	string str = "";

	if (am != NO_MODIF)
		str.append(AccessModifierToString(am)).append(" ");

	str.append(ClassTypeToString(ct));
	
	str.append(" ").append(name);

	if (extends.size() != 0 || implements.size() != 0)
		str.append(": ");

	if (extends.size() != 0) {
		for (Class* c : extends)
			str.append(c->getName()).append(",");
		str.pop_back();
	}

	if (implements.size() != 0) {
		for (Class* c : implements)
			str.append(c->getName()).append(",");

		str.pop_back();
	}
	str.append("{\n");

	for (CodeElement* ce : elements)
		str.append(ce->toString()).append("\n");

	str.append("}");
	return str;
}
