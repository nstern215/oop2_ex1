#pragma once
#include "BaseFunction.h"

class Union : public BaseFunction
{
public:
	Union() = default;
	Group eval(Group a, Group b) override;
	
};
