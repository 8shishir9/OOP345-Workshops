#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Person.h"
#include "Employee.h"

namespace seneca
{
	Person* buildInstance(std::istream& in)
	{
		std::string line;
		char type = '\0';
		char delim = '\0';

		std::getline(in, line);
		std::stringstream ss(line);
		ss >> type >> delim;
		if (ss)
		{
			switch (type)
			{
			case 'e':
			case 'E':
				return new Employee(ss);
				break;
			}
		}
		return nullptr;
	}

	std::string trim(std::string& token)
	{
		while (token.length() > 0 && token[0] == ' ')
			token.erase(0, 1);
		while (token.length() > 0 && token[token.length() - 1] == ' ')
			token.erase(token.length() - 1, 1);
		return token;
	}
}