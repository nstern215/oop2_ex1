#include <ostream>
#include "FunctionNode.h"

FunctionNode::FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left, std::shared_ptr<FunctionNode> right) :
	m_function(function),
	m_left(left),
	m_right(right)
{}


FunctionNode::~FunctionNode()
{}

BaseFunction* FunctionNode::getFunction() const
{
	return m_function;
}

std::ostream& operator<<(std::ostream& os, const FunctionNode& other)
{
	other.getFunction()->print(os);
	//os << "Function";
	return os;
}