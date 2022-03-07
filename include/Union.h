#pragma once
#include "BaseFunction.h"

class Union : public BaseFunction
{
public:
	Group eval(Group a, Group b) override;
	
};
