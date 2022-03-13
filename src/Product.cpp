#include <algorithm>
#include "Product.h"

std::unique_ptr<Group> Product::eval(Group* a, Group* b)
{
	std::vector<int> productData;

	for (const int i : *(a->getData()))
		for (const int j : *(b->getData()))
			productData.push_back(i * j);

	return std::make_unique<Group>(productData);
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

