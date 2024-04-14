//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <ostream>
#include <string>

namespace seneca
{
	class Movie
	{
		std::string m_title{};
		size_t m_year{};
		std::string m_description{};
		void trim(std::string& str) const;
	public:
		Movie() = default;
		Movie(const std::string& strMovie);

		const std::string& title() const { return m_title; };

		template<typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& out, const Movie& theMovie);
	};
}
#endif
