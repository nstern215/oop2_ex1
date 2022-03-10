#pragma once
#include "BaseFunction.h"

class Intersection : public BaseFunction
{
public:
	Intersection() = default;
	std::unique_ptr<Group> eval(Group* a, Group* b) override;
	std::ostream& print(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, const Intersection& other);