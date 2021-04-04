#pragma once

#include <string>

class CodeElement {

protected:
	std::string name;

public: 

	CodeElement(std::string name);

	std::string getName();

	virtual std::string toString() = 0;

};

