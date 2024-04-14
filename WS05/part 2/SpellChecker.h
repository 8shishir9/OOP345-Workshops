//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>
namespace seneca
{
	class SpellChecker
	{
		std::string m_badWords[6]{};
		std::string m_goodWords[6]{};
		size_t m_fixCnt[6]{};
	public:
		SpellChecker(const char* filename);
		void showStatistics(std::ostream& out) const;
		void operator()(std::string& text);
	};
}
#endif
