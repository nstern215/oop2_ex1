#pragma once
#include "BaseFunction.h"

class Difference : public BaseFunction
{
public:
	Difference() = default;
	std::unique_ptr<Group> eval(Group* a, Group* b) override;
	std::ostream& print(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, const Difference& other);