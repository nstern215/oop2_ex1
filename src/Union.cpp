#include <algorithm>
#include <functional>
#include "Union.h"

std::unique_ptr<Group> Union::eval(Group* a, Group* b)
{
	std::vector<int> unionData;
	std::ranges::set_union(a->getData()->begin(), a->getData()->end(), b->getData()->begin(), b->getData()->end(), unionData.begin());

	return std::make_unique<Group>(unionData);
}

std::ostream& Union::print(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Union& other)
{
	os << "U";
	return os;
}
