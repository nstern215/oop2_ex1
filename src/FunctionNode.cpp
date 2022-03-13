#include <ostream>
#include <iostream>
#include "Composite.h"
#include "FunctionNode.h"

FunctionNode::FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left, std::shared_ptr<FunctionNode> right) :
	m_function(function),
	m_left(left),
	m_right(right)
{
	m_numOfGroups = 0;
}

BaseFunction* FunctionNode::getFunction() const
{
	return m_function;
}

int FunctionNode::getRequiredGroups() const
{
	if (m_right == nullptr || m_left == nullptr)
		return 2;

	int sum = m_right->getRequiredGroups() + m_left->getRequiredGroups();

	if (dynamic_cast<Composite*>(m_function))
		sum -= 1;

	return sum;
}

void FunctionNode::printFunction(std::ostream& os) const
{
	os << "(";

	if (m_left != nullptr)
		os << " " << *m_left<< " ";

	if (m_left == nullptr)
		os << " A ";
	m_function->print(os);

	if (m_right == nullptr)
		os << " B ";

	if (m_right != nullptr)
		os << " " << *m_right << " ";

	os << ")";
}

std::unique_ptr<Group> FunctionNode::evaluate(std::vector<std::unique_ptr<Group>>& groupsList) const
{
	std::cout << "(";

	if (m_right == nullptr || m_left == nullptr)
	{
		auto result = m_function->eval(groupsList[0].get(), groupsList[1].get());
		std::cout << " " << (*groupsList[0]);
		m_function->print(std::cout);
		std::cout << " " << (*groupsList[1]);

		std::cout << ")";

		groupsList.erase(groupsList.begin(), groupsList.begin() + 2);
		return result;
	}

	auto a = m_left->evaluate(groupsList);

	m_function->print(std::cout);

	if (dynamic_cast<Composite*>(m_function))
	{
		groupsList.insert(groupsList.begin(), std::make_unique<Group>(*(a->getData())));
		return  m_right->evaluate(groupsList);
	}

	auto b = m_right->evaluate(groupsList);

	std::cout << ")";

	return m_function->eval(a.get(), b.get());
}

std::ostream& operator<<(std::ostream& os, FunctionNode& other)
{
	other.printFunction(os);
	return os;
}