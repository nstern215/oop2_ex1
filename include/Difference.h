#pragma once
#include "BaseFunction.h"

class Difference : public BaseFunction
{
public:
	Difference() = default;
	std::unique_ptr<Group> eval(Group a, Group b) override;
};
