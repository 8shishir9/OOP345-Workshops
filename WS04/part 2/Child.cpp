//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Child.h"

namespace seneca
{
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		this->m_name = name;
		this->m_age = age;
		this->m_count = count;
		this->m_pToys = new const Toy*[m_count];
		for (auto i = 0u; i < m_count; ++i) {
			this->m_pToys[i] = new Toy(*toys[i]);
		}
	}
	Child::Child(const Child& other)
	{
		*this = other;
	}
	Child& Child::operator=(const Child& other)
	{
		if (this != &other)
		{
			for (auto i = 0u; i < m_count; ++i)
				delete this->m_pToys[i];
			delete[] this->m_pToys;

			m_name = other.m_name;
			m_age = other.m_age;
			m_count = other.m_count;

			this->m_pToys = new const Toy*[m_count];
			for (auto i = 0u; i < m_count; ++i) {
				this->m_pToys[i] = new Toy(*other.m_pToys[i]);
			}
		}
		return *this;
	}
	Child::Child(Child&& other) noexcept
	{
		*this = std::move(other);
	}
	Child& Child::operator=(Child&& other) noexcept
	{
		if (this != &other)
		{
			for (auto i = 0u; i < m_count; ++i)
				delete this->m_pToys[i];
			delete[] this->m_pToys;

			m_name = other.m_name;
			m_age = other.m_age;
			m_count = other.m_count;

			this->m_pToys = other.m_pToys;
			other.m_name = "";
			other.m_age = 0;
			other.m_count = 0;
			other.m_pToys = nullptr;
		}
		return *this;
	}
	Child::~Child()
	{
		for (auto i = 0u; i < m_count; ++i)
			delete this->m_pToys[i];
		delete[] this->m_pToys;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child)
	{
		static size_t callCnt = 0;
		os << "--------------------------\n";
		os << "Child " << ++callCnt << ": " << child.m_name << " " << child.m_age << " years old:\n";
		os << "--------------------------\n";
		if (child.m_count == 0)
			os << "This child has no toys!\n";
		for (auto i = 0u; i < child.m_count; ++i)
			os << *child.m_pToys[i];
		os << "--------------------------\n";
		return os;
	}
}
