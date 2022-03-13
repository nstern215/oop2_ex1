#pragma once
#include <vector>

#include "BaseFunction.h"
#include "Group.h"

class FunctionNode
{
public:
	FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left = nullptr, std::shared_ptr<FunctionNode> right = nullptr);

	BaseFunction* getFunction() const;
	int getRequiredGroups() const;
	void printFunction(std::ostream& os) const;
	std::unique_ptr<Group> evaluate(std::vector<std::unique_ptr<Group>>& groupsList) const;

private:
	int m_numOfGroups;

	BaseFunction* m_function;
	
	std::shared_ptr<FunctionNode> m_left;
	std::shared_ptr<FunctionNode> m_right;
};

std::ostream& operator<<(std::ostream& os, FunctionNode& other);