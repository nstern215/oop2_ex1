#include <algorithm>
#include "Intersection.h"

std::unique_ptr<Group> Intersection::eval(Group a, Group b)
{
	std::vector<int> intersectionData;
	std::ranges::set_difference(a.getData()->begin(), a.getData()->end(), b.getData()->begin(), b.getData()->end(), intersectionData.begin());

	return std::make_unique<Group>(intersectionData);
}

std::ostream& operator<<(std::ostream& os, const Intersection& other) 
{
	os << "-";
	return os;
}