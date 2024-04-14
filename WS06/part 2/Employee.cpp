#include <string>
#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "Utilities.h"

using namespace std;
namespace seneca
{
	Employee::Employee(std::istream& in)
	{
		std::string token;

		std::getline(in, token, ',');
		m_name = trim(token);

		std::getline(in, token, ',');
		try
		{
			m_age = stoi(trim(token));
		}
		catch (...)
		{
			throw m_name + "++Invalid record!";
		}
	
		std::getline(in, token, ',');
		m_id = trim(token);
		if (m_id[0] != 'E')
		{
			throw m_name + "++Invalid record!";
		}
	}

	string Employee::status() const
	{
		return "Employee";
	}

	string Employee::name() const
	{
		return  m_name;
	}

	string Employee::id() const
	{
		return  m_id;
	}

	string Employee::age() const
	{
		return to_string(m_age);
	}

	void Employee::display(std::ostream& out) const
	{
		out << std::left << "| " << std::setw(10) << "Employee"
			<< "| " << std::setw(10) << m_id
			<< "| " << std::setw(20) << m_name
			<< " | " << std::setw(3) << m_age << " |";
	}
}
