#pragma once
#include "BaseFunction.h"

class Intersection : public BaseFunction
{
public:
	Group eval(Group a, Group b) override;
	std::ostream& operator<<(std::ostream& os, const BaseFunction& other) override;
};
