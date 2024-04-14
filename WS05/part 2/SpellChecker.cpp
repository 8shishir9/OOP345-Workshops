//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SpellChecker.h"

namespace seneca
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (file.is_open() == false)
			throw "Bad file name!";

		for (size_t i = 0u; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
		{
			file >> m_badWords[i];
			file >> m_goodWords[i];
			m_fixCnt[i] = 0;
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (auto i = 0u; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
		{
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos)
			{
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				++m_fixCnt[i];
				pos = text.find(m_badWords[i]);
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics\n";
		for (auto i = 0u; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
			out << std::setw(15) << m_badWords[i] << ": " << m_fixCnt[i] << " replacements\n";
	}
}
