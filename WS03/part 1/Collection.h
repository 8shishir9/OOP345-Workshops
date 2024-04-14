//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Pair.h"

namespace seneca
{
	// allows duplicates
	template <typename T, int CAPACITY>
	class Collection
	{
		T m_items[CAPACITY]{};
		size_t m_noOfItems{};

		static T m_defaultValue; // specialize for Pair
	public:

		virtual bool add(const T& item)
		{
			if (m_noOfItems < CAPACITY)
			{
				m_items[m_noOfItems++] = item;
				return true;
			}
			return false;
		}

		size_t size() const
		{
			return m_noOfItems;
		}

		void display(std::ostream& out = std::cout) const
		{
			std::cout << "----------------------\n";
			std::cout << "| Collection Content |\n";
			std::cout << "----------------------\n";

			for (auto i = 0u; i < m_noOfItems; ++i)
				out << m_items[i] << "\n";
			std::cout << "----------------------\n";
		}

		T operator[](size_t idx) const
		{
			if (idx < m_noOfItems)
				return m_items[idx];

			return m_defaultValue;
		}

		virtual ~Collection() = default;
	};

	template<typename T, int CAPACITY>
	T Collection<T, CAPACITY>::m_defaultValue{};

	template<>
	seneca::Pair Collection<seneca::Pair, 100>::m_defaultValue("No Key", "No Value");
}
#endif
