#include <algorithm>
#include "Difference.h"

std::unique_ptr<Group> Difference::eval(Group a, Group b)
{
	std::vector<int> differenceData;
	std::ranges::set_difference(a.getData()->begin(), a.getData()->end(), b.getData()->begin(), b.getData()->end(), differenceData.begin());
	
	return std::make_unique<Group>(differenceData);
}

std::ostream& operator<<(std::ostream& os, const Difference& other)
{
	os << "^";
	return os;
}