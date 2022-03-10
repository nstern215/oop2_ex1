#pragma once
#include "BaseFunction.h"

class Intersection : public BaseFunction
{
public:
	Intersection() = default;
	Group eval(Group a, Group b) override;
};
