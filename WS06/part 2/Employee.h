#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include <string>
#include <iostream>
#include "Person.h"

namespace seneca
{
	class Employee : public Person
	{
		std::string m_name;
		int m_age;
		std::string m_id;

	public:
		Employee(std::istream& in);
		std::string status() const override;
		std::string name() const override;
		std::string id() const override;
		std::string age() const override;

		void display(std::ostream&) const override;
	};
}

#endif