#include <algorithm>
#include "Product.h"

std::unique_ptr<Group> Product::eval(Group* a, Group* b)
{

	std::vector<int> productData;

	std::ranges::set_product(a->getData()->begin(), a->getData()->end(), b->getData()->begin(), b->getData()->end(), productData.begin());

	return std::unique_ptr<Group>(productData);
}

std::ostream& Product::print(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Product& other)
{
	os << "*";
	return os;
}

