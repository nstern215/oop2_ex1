#include <algorithm>
#include "Intersection.h"

std::unique_ptr<Group> Intersection::eval(Group* a, Group* b)
{
	std::vector<int> intersectionData;
	std::ranges::set_intersection(a->getData()->begin(), a->getData()->end(), b->getData()->begin(), b->getData()->end(), std::back_inserter(intersectionData));
	
	return std::make_unique<Group>(intersectionData);
}

std::ostream& Intersection::print(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Intersection& other) 
{
	os << "^";
	return os;
}