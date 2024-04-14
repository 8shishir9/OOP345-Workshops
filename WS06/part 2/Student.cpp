#include <string>
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Utilities.h"

using namespace std;
namespace seneca
{
	Student::Student(std::istream& in)
	{
		std::string token;

		std::getline(in, token, ',');
		m_name = trim(token);

		std::getline(in, token, ',');
		try
		{
			m_age = stoi(token);
		}
		catch (...)
		{
			throw m_name + "++Invalid record!";
		}

		std::getline(in, token, ',');
		m_id = trim(token);
		if (m_id[0] != 'S')
		{
			throw m_name + "++Invalid record!";
		}

		std::getline(in, token, ',');
		try
		{
			m_count = stoi(token);
		}
		catch (...)
		{
			throw m_name + "++Invalid record!";
		}

		courses = new string[m_count];
		for(unsigned int count = 0; count < m_count; ++count)
		{
			std::getline(in, token, ',');
			courses[count] = trim(token);
		}
	}

	string Student::status() const
	{
		return "Student";
	}

	string Student::name() const
	{
		return  m_name;
	}

	string Student::id() const
	{
		return  m_id;
	}

	string Student::age() const
	{
		return  to_string(m_age);
	}

	void Student::display(std::ostream& out) const
	{
		out << std::left << "| " << std::setw(10) << "Student "
			<< "| " << std::setw(10) << m_id
			<< "| " << std::setw(20) << m_name
				<< " | " << std::setw(3) << m_age << " |";
			
		for(unsigned int count = 0; count < m_count ;)
		{
			out << courses[count];
			if ( ++count < m_count)
				out << ", ";
		}
	}

	Student::~Student()
	{
		delete[]  courses;
	}
}