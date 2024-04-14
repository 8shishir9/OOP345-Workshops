//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca
{
	extern size_t g_sysClock; // time of the day: number of seconds since midnight

	class Event
	{
		char* m_evDescription{ nullptr };
		size_t m_startTime{ 0 };
	public:
		void set(const char* desc = nullptr);
		void display() const;

		Event() = default;
		Event(const Event& other);
		Event& operator=(const Event& other);
		~Event();
	};
}
#endif
