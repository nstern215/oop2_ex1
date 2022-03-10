#pragma once
#include "BaseFunction.h"

class Union : public BaseFunction
{
public:
	Union() = default;
	std::unique_ptr<Group> eval(Group a, Group b) override;
};
