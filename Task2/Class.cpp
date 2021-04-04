#include "Class.h"
#include <string>
#include <exception>
#include "TypeEnum.h"

Class::Class(string str, AccessModifier am, ClassType ct):CodeElement(str)
{

	this->am = am;
	this->ct = ct;
}

Class::~Class()
{
	extends.clear();
	implements.clear();
	fields.clear();
	properties.clear();
	methods.clear();
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

void Class::addField(Field* field)
{
	fields.push_back(field);
}

void Class::addProperty(Property* prop)
{
	properties.push_back(prop);
}

void Class::addMethod(Method* meth)
{
	methods.push_back(meth);
}

void Class::deleteField(int idx)
{
	fields.erase(fields.begin() + idx);
}

void Class::deleteProperty(int idx)
{
	properties.erase(properties.begin() + idx);
}

void Class::deleteMethod(int idx)
{
	methods.erase(methods.begin() + idx);
}

vector<Field*> Class::getFields()
{
	vector<Field*> newVec;

	copy(fields.begin(), fields.end(), back_inserter(newVec));

	return newVec;
}

vector<Property*> Class::getProperties()
{
	vector<Property*> newVec;

	copy(properties.begin(), properties.end(), back_inserter(newVec));

	return newVec;
}

vector<Method*> Class::getMethods()
{
	vector<Method*> newVec;

	copy(methods.begin(), methods.end(), back_inserter(newVec));

	return newVec;
}

string Class::toString()
{
	string str = "";

	if (am != NO_MODIF)
		str.append(AccessModifierToString(am)).append(" ");

	str.append(ClassTypeToString(ct));
	if (extends.size() != 0) {
		str.append(": ");
		for (Class* c : extends)
			str.append(c->getName()).append(",");
	}
	str.pop_back();

	if (implements.size() != 0) {
		str.append(": ");
		for (Class* c : implements)
			str.append(c->getName()).append(",");
	}
	str.pop_back();


	str.append(" ").append(name).append("{\n");

	for (Property* prop : properties)
		str.append(prop->toString()).append("\n");
	for (Field* field : fields)
		str.append(field->toString()).append("\n");
	for (Method* meth : methods)
		str.append(meth->toString()).append("\n");;

	str.append("}");
	return str;
}
