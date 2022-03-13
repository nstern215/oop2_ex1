#include "Composite.h"

std::unique_ptr<Group> Composite::eval(Group* a, Group* b)
{
	return nullptr;
}

std::ostream& Composite::print(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Composite& other)
{
	os << "->";
	return os;
}