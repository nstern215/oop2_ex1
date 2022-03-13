#pragma once
#include <vector>

#include "BaseFunction.h"
#include "Group.h"

class FunctionNode
{
public:
	FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left = nullptr, std::shared_ptr<FunctionNode> right = nullptr);
	~FunctionNode();

	BaseFunction* getFunction() const;
	void getGroups(std::vector< Group*> groups);
	int getRequiredGroups() const;
	void printFunction(std::ostream& os, char groupName);
	std::unique_ptr<Group> evaluate(std::vector<Group*>& groupsList);

private:
	int m_numOfGroups;

	BaseFunction* m_function;
	
	std::shared_ptr<FunctionNode> m_left;
	std::shared_ptr<FunctionNode> m_right;
};

std::ostream& operator<<(std::ostream& os, FunctionNode& other);