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
	void getGroups();
	void printFunction(std::shared_ptr<FunctionNode> thisFunction, char groupName)const;
	/*void evaluate(std::shared_ptr<FunctionNode> thisFunction, std::vector<Group> groupsList);*/

private:
	int m_numOfGroups;

	std::vector<Group> m_groupsForEval;

	BaseFunction* m_function;
	
	std::shared_ptr<FunctionNode> m_left;
	std::shared_ptr<FunctionNode> m_right;
};

std::ostream& operator<<(std::ostream& os, const FunctionNode& other);