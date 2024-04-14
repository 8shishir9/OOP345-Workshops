//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <ostream>
#include "Toy.h"

namespace seneca
{
	//manages a collection of toys
	class Child {
		std::string m_name = "";
		int m_age = 0;
		const seneca::Toy** m_pToys = nullptr;
		size_t m_count = 0u;
	public:
		//Child();
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& other);
		Child& operator=(const Child& other);
		Child(Child&& other) noexcept;
		Child& operator=(Child&& other) noexcept;
		~Child();
		size_t size() const { return m_count; }

		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif// SENECA_CHILD_H
