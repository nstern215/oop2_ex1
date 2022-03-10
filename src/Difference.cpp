#include <algorithm>
#include "Difference.h"

Group Difference::eval(Group a, Group b)
{
	std::vector<int> differenceData;
	std::ranges::set_difference(a.getData()->begin(), a.getData()->end(), b.getData()->begin(), b.getData()->end(), differenceData.begin());
	
	return Group(differenceData);
}

std::ostream& operator<<(std::ostream& os, const Difference& other)
{
	os << "^";
	return os;
}