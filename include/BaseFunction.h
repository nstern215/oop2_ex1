#pragma once
#include <ostream>

#include "Group.h"

class BaseFunction
{
public:
	BaseFunction() = default;
	virtual ~BaseFunction() = default;
	
	virtual std::ostream& print(std::ostream& os) = 0;
	virtual std::unique_ptr<Group> eval(Group* a, Group* b) = 0;
};
