#pragma once
#include <ostream>

#include "Group.h"

class BaseFunction
{
public:
	BaseFunction() = default;
	virtual ~BaseFunction() = default;
	
	virtual Group eval(Group a, Group b) = 0;
	//virtual std::ostream& operator<<(std::ostream& os, const BaseFunction& other) = 0;
};
