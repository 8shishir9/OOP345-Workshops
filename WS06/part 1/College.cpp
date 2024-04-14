#include <vector>
#include <iomanip>
#include <iostream>
#include "College.h"

namespace seneca
{

	College& College::operator+=(Person* thePerson)
	{
		m_persons.push_back(thePerson);

		return *this;
	}

	void College::display(std::ostream& out) const
	{
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #1 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			(*it)->display(out);
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		out << "|                                        Test #2 Persons in the college!                                               |\n";
		out << "------------------------------------------------------------------------------------------------------------------------\n";
		for (auto it = m_persons.begin(); it != m_persons.end(); ++it)
		{
			out << std::left << "| " << std::setw(10) << (*it)->status()
				<< "| " << std::setw(10) << (*it)->id()
				<< "| " << std::setw(20) << (*it)->name()
				<< " | " << std::setw(3) << (*it)->age() << " |";
			
			out << std::endl;
		}
		out << "------------------------------------------------------------------------------------------------------------------------\n";
	}

	College::~College()
	{
		for (Person* person : m_persons)
			delete person;
	}
}