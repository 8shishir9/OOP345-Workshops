#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H
#include <iostream>

namespace seneca
{
	class Person;
	std::string trim(std::string& token);

	Person* buildInstance(std::istream& in);
}

#endif