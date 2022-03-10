#pragma once
#include "BaseFunction.h"

class Intersection : public BaseFunction
{
public:
	Intersection() = default;
	std::unique_ptr<Group> eval(Group a, Group b) override;
};
