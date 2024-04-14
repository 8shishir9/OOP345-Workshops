#include <string>
#include <iostream>
#include <iomanip>
#include "Professor.h"
#include "Utilities.h"

using namespace std;
namespace seneca
{
	Professor::Professor(std::istream& in) : Employee(in)
	{
		std::string token;

		std::getline(in, token, ',');
		m_department = trim(token);
	}

	string Professor::status() const
	{
		return "Professor";
	}

	string  Professor::department() const
	{
		return m_department;
	}

	void Professor::display(std::ostream& out) const
	{
		Employee::display(out);
		out << std::left << std::setw(10) << department() << "| " << status();
	}
}
