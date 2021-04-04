#include "CodeElement.h"
using namespace std;

CodeElement::CodeElement(string name) {
	this->name = name;
}

string CodeElement::getName()
{
	return name;
}
