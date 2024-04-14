//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <ostream>
#include <string>

namespace seneca
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		double      m_price{};
		size_t      m_year{};
		void trim(std::string& str) const;
	public:
		Book() = default;
		Book(const std::string& strBook);

		const std::string& title() const { return m_title; }
		const std::string& country() const { return m_country; }
		const size_t& year() const { return m_year; }
		double& price() { return m_price; }

		friend std::ostream& operator<<(std::ostream& out, const Book& theBook);
	};
}
#endif
