#include <ostream>
#include <iostream>

#include "FunctionNode.h"

FunctionNode::FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left, std::shared_ptr<FunctionNode> right) :
	m_function(function),
	m_left(left),
	m_right(right)
{
	m_numOfGroups = 0;
}

FunctionNode::~FunctionNode()
{}

BaseFunction* FunctionNode::getFunction() const
{
	return m_function;
}

//void FunctionNode::getGroups()
//{
//	for (int i = 0; i < m_numOfGroups; i++)
//	{
//		int size;
//
//		std::cin >> size;
//		Group group(size);
//
//		group.getData();
//
//		this->m_groupsForEval.push_back(group);
//	}
//}

//void FunctionNode::printFunction(std::shared_ptr<FunctionNode> thisFunction, char groupName) const
void FunctionNode::printFunction(char groupName)
{
	if (m_right == nullptr || m_left == nullptr) 
	{
		std::cout << groupName << " ";
		std::cout << *this;
		groupName++;
		std::cout << " " << groupName << std::endl;
		groupName++;

		m_numOfGroups += 2;

		return;
	}

	m_left->printFunction(groupName);
	
	m_right->printFunction(groupName);
}

void FunctionNode::evaluate(std::shared_ptr<FunctionNode> thisFunction, std::vector<Group> groupsList)
{
	if (m_right == nullptr || m_left == nullptr)
	{
		return m_function->eval(groupsList[0], groupsList[1]);
	}

	auto resultLeft = evaluate(thisFunction->m_left, groupsList);

	auto resultRight = evaluate(thisFunction->m_right, groupsList);

	m_function->eval(resultLeft, resultRight)
	
	return;
}

std::ostream& operator<<(std::ostream& os, const FunctionNode& other)
{
	other.getFunction()->print(os);
	//os << "Function";
	return os;
}