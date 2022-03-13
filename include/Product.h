#pragma once
#include "BaseFunction.h"

class Product : public BaseFunction
{
public:
	Product() = default;
	std::unique_ptr<Group> eval(Group* a, Group* b) override;
	std::ostream& print(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, const Product& other);