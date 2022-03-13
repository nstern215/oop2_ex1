#include "Composite.h"

std::unique_ptr<Group> Composite::eval(Group* a, Group* b)
{
	std::vector<int> compositeData;
	std::ranges::set_composite(a->getData()->begin(), a->getData()->end(), b->getData()->begin(), b->getData()->end(), intersectionData.begin());

	return std::make_unique<Group>(compositeData);
}

std::ostream& Composite::print(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Intersection& other)
{
	os << "->";
	return os;
}