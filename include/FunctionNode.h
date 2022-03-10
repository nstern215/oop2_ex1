#pragma once
#include "BaseFunction.h"

class FunctionNode
{
public:
	FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left = nullptr, std::shared_ptr<FunctionNode> right = nullptr);
	~FunctionNode();

	BaseFunction* getFunction() const;

private:
	BaseFunction* m_function;
	
	std::shared_ptr<FunctionNode> m_left;
	std::shared_ptr<FunctionNode> m_right;
};

std::ostream& operator<<(std::ostream& os, const FunctionNode& other);