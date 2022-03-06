#pragma once
#include "Group.h"

class BaseFunction
{
public:
	BaseFunction() = default;
	virtual Group eval(Group a, Group b) = 0;
};
