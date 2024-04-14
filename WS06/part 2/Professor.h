#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <string>
#include <iostream>
#include "Employee.h"

namespace seneca
{
	class Professor : public Employee
	{

		std::string m_department;

	public:
		Professor(std::istream& in);

		std::string status() const override;

		std::string department() const;

		void display(std::ostream&) const override;
	};
}

#endif