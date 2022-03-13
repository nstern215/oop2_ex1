#include <ostream>
#include <iostream>

#include "Union.h"
#include "Composite.h"
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

void FunctionNode::getGroups(std::vector< Group*> groups)
{
	for (int i = 0; i < m_numOfGroups; i++)
	{
		int size;

		std::cin >> size;
		Group* group(size);

		group->getData();

		groups.push_back(group);
	}
}

void FunctionNode::printFunction(char groupName)
{
	if (m_right == nullptr || m_left == nullptr)
	{
		std::cout << "(" << groupName << " ";
		std::cout << *this;
		groupName++;
		std::cout << " " << groupName << ")" << " ";
		groupName++;

		m_numOfGroups += 2;

		return;
	}

	m_left->printFunction(groupName);

	std::cout << *this << " ";

	m_right->printFunction(groupName);
	
	return;
}

std::unique_ptr<Group> FunctionNode::evaluate(std::vector<Group*> groupsList)
{
	if (m_right == nullptr || m_left == nullptr)
	{
		Group* a = groupsList[0];
		Group* b = groupsList[1];
		groupsList.erase(groupsList.begin(), groupsList.begin() + 2);

		return m_function->eval(a, b);
	}

	auto a = m_left->evaluate(groupsList);

	if (dynamic_cast<Composite*>(m_function))
	{
		groupsList.insert(groupsList.begin(), a.get());
		return  m_right->evaluate(groupsList);
	}

	//todo: if function is hasma then add output to begin of the groupslist
	// return m_right->evaluate(groupsList);
	//else continue as usual

	auto b = m_right->evaluate(groupsList);

	return m_function->eval(a.get(), b.get());
}

std::ostream& operator<<(std::ostream& os, const FunctionNode& other)
{
	other.getFunction()->print(os);
	//os << "Function";
	return os;
}