//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_SET_H
#define SENECA_SET_H
#include <cmath>     // for std::fabs()
#include "Collection.h"

namespace seneca
{
	// unique items
	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:
		bool add(const T& item) override
		{
			for (auto i = 0u; i < this->size(); ++i)
			{
				if ((*this)[i] == item)
					return false;
			}

			return Collection<T, 100>::add(item);
		}
	};

	// Specialization for double: numbers that are 0.01 from eachother are considered the same
	template<>
	bool Set<double>::add(const double& item)
	{
		double epsilon = 0.01;

		for (auto i = 0u; i < this->size(); ++i)
		{
			if (std::fabs((*this)[i] - item) <= epsilon)
				return false;
		}

		return Collection::add(item);
	}
}

#endif
