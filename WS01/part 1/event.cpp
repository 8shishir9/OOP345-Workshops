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

		if (desc)
			strncpy(this->m_evDescription, desc, 128);
		else
			this->m_evDescription[0] = '\0';
	}

	void Event::display() const
	{
		static size_t cnt = 0;
		cout << setw(2) << ++cnt << ". ";
		if (m_evDescription[0])
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
}
