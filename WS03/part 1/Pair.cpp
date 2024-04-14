//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Pair.h"

namespace seneca
{
	bool Pair::operator==(const Pair& other)
	{
		return this->m_key == other.m_key;
	}

	std::ostream& operator<<(std::ostream& out, const Pair& item)
	{
		out << std::setw(20) << item.m_key << ": " << item.m_value;
		return out;
	}
}
