//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <string>

namespace seneca
{
	class StringSet
	{
		std::string* m_strings{ nullptr };
		size_t m_cnt{ 0 };
	public:
		StringSet() = default;
		StringSet(const std::string&);
		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);
		~StringSet();

		size_t size() const { return m_cnt; }
		std::string operator[](size_t idx);
	};
}
#endif