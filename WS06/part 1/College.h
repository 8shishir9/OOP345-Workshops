#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <vector>
#include <list>
#include <iostream>
#include "Person.h"

namespace seneca
{
	class College
	{
		std::vector<Person*> m_persons{};

	public:
		College() = default;
		College(const College&) = delete;
		College& operator=(const College&) = delete;

		College& operator +=(Person* thePerson);

		void display(std::ostream& out) const;

		~College();
	};
}

#endif
