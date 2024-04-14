//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include <ostream>
#include "Toy.h"

namespace seneca
{
	class ConfirmOrder
	{
		const seneca::Toy** m_pToys = nullptr;
		size_t m_count = 0u;
	public:
		ConfirmOrder() {}
		~ConfirmOrder();
		ConfirmOrder(const ConfirmOrder&);
		ConfirmOrder& operator=(const ConfirmOrder&);
		ConfirmOrder(ConfirmOrder&&) noexcept;
		ConfirmOrder& operator=(ConfirmOrder&&) noexcept;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
	};
}
#endif// SENECA_CONFIRMORDER_H
