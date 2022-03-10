#pragma once
#include "BaseFunction.h"

class Difference : public BaseFunction
{
public:
	Difference() = default;
	Group eval(Group a, Group b) override;
};
