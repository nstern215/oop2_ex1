#pragma once
#include "BaseFunction.h"

class Union : public BaseFunction
{
public:
	Union() = default;
	std::unique_ptr<Group> eval(Group* a, Group* b) override;
	std::ostream& print(std::ostream& os) override;
};

std::ostream& operator<<(std::ostream& os, const Union& other);