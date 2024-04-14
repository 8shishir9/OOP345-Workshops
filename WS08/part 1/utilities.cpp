//==============================================
// Name:          
// Student Number: 
// Email:          
// Section:        NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto i = 0u; i < desc.size(); i++) {
			for (auto j = 0u; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					// raw pointer solution
					Product* p = new Product(desc[i].desc, price[j].price);
					try
					{
						p->validate();
						priceList += p;
						delete p;
					}
					catch ( ...)
					{
						delete p;
						throw;
					}
				}
			}
		}
		return priceList;
	}
}