//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

using namespace std;

namespace seneca
{
	size_t g_sysClock = 0; // time of the day: number of seconds since midnight

	void Event::set(const char* desc)
	{
		this->m_startTime = g_sysClock;

		// LO5: resize the string
		if (m_evDescription)
			delete[] this->m_evDescription;

		if (desc)
		{
			this->m_evDescription = new char[strlen(desc) + 1];
			strcpy(this->m_evDescription, desc);
		}
		else
			this->m_evDescription = nullptr;
	}

	void Event::display() const
	{
		static size_t cnt = 0;
		cout << setw(2) << ++cnt << ". ";
		if (m_evDescription)
		{
			cout << setw(2) << setfill('0') << (this->m_startTime / 3600) << ":"
			     << setw(2) << setfill('0') << (this->m_startTime % 3600) / 60 << ":"
			     << setw(2) << setfill('0') << (this->m_startTime % 60) << setfill(' ') << " => ";
			cout << this->m_evDescription;
		}
		else
			cout << "| No Event |";

		cout << endl;
	}

	Event::Event(const Event& other)
	{
		*this = other;
	}
	Event& Event::operator=(const Event& other)
	{
		if (this != &other)
		{
			this->m_startTime = other.m_startTime;

			delete[] this->m_evDescription;
			if (other.m_evDescription)
			{
				this->m_evDescription = new char[strlen(other.m_evDescription) + 1];
				strcpy(m_evDescription, other.m_evDescription);
			}
			else
				this->m_evDescription = nullptr;
		}
		return *this;
	}
	Event::~Event()
	{
		delete[] m_evDescription;
	}
}
