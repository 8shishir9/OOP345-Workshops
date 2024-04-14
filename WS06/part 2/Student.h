#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H
#include <string>
#include <iostream>
#include "Person.h"

namespace seneca
{
	class Student : public Person
	{
		std::string m_name;
		int m_age;
		std::string m_id;
		std::string* courses;
		unsigned int m_count;

	public:
		Student(const Student&) = delete;
		Student& operator=(const Student&) = delete;
		Student(std::istream& in);
		std::string status() const override;
		std::string name() const override;
		std::string id() const override;
		std::string age() const override;

		void display(std::ostream&) const override;

		virtual ~Student() override;
	};
}

#endif