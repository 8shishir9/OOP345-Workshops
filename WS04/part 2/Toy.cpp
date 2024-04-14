//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iomanip>
#include "Toy.h"

namespace seneca
{
	void Toy::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	// The string has the format (assume correct format)
	//  ID:NAME:NUM:PRICE
	Toy::Toy(const std::string& toy)
	{
		size_t posS = 0;
		size_t posE = toy.find(':');
		m_id = static_cast<unsigned int>(std::stoi(toy.substr(posS, posE - posS)));

		posS = posE + 1;
		posE = toy.find(':', posS);
		this->trim(m_name = toy.substr(posS, posE - posS));

		posS = posE + 1;
		posE = toy.find(':', posS);
		m_num = std::stoi(toy.substr(posS, posE - posS));

		posS = posE + 1;
		posE = toy.find(':', posS);
		m_price = std::stod(toy.substr(posS, posE - posS));
	}

	//Toy <id>: <name> <num> $<price> $<subtotal> $<tax> $<total>
	std::ostream& operator<<(std::ostream& out, const Toy& toy)
	{
		double m_subtotal = toy.m_num * toy.m_price;
		double m_tax = m_subtotal * toy.hst;
		double m_total = m_subtotal + m_tax;

		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Toy" << std::setw(8) << toy.m_id << ":"
			<< std::setw(18) << std::right << toy.m_name << std::setw(3)
			<< toy.m_num << " items" << std::setw(8)<< toy.m_price << "/item"
			<< "  subtotal:" << std::setw(7)<< m_subtotal << " tax:" 
			<< std::setw(6)<<m_tax << " total:" << std::setw(7) << m_total << "\n";

		return out;
	}
}
