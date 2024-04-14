//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <utility>
#include "ConfirmOrder.h"
namespace seneca
{
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& other)
	{
		*this = other;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other)
	{
		if (this != &other)
		{
			this->m_count = other.m_count;
			delete[] this->m_pToys;

			this->m_pToys = new const Toy * [m_count];
			for (auto i = 0u; i < m_count; ++i)
				this->m_pToys[i] = other.m_pToys[i];
		}
		return *this;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept
	{
		*this = std::move(other);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept
	{
		if (this != &other)
		{
			this->m_count = other.m_count;
			delete[] this->m_pToys;

			this->m_pToys = other.m_pToys;
			other.m_pToys = nullptr;
			other.m_count = 0;
		}
		return *this;
	}

	ConfirmOrder::~ConfirmOrder()
	{
		delete[] this->m_pToys;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool found = false;
		for (auto i = 0u; i < m_count && found == false; ++i)
			if (&toy == m_pToys[i])
				found = true;

		if (found == false)
		{
			// resize & add
			const seneca::Toy** tmp = nullptr;
			tmp = new const Toy * [m_count + 1];
			for (auto i = 0u; i < m_count; ++i)
				tmp[i] = m_pToys[i];
			tmp[m_count] = &toy;

			++m_count;
			delete[] m_pToys;
			m_pToys = tmp;
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		for (auto i = 0u; i < m_count; ++i)
			if (&toy == m_pToys[i])
				m_pToys[i] = nullptr;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& sender)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (sender.m_count == 0)
			os << "There are no confirmations to send!\n";
		for (auto i = 0u; i < sender.m_count; ++i)
			if (sender.m_pToys[i] != nullptr)
				os << *(sender.m_pToys[i]);
		os << "--------------------------\n";
		return os;
	}
}
