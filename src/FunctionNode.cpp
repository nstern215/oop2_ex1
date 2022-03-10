#include <ostream>
#include "FunctionNode.h"

FunctionNode::FunctionNode(BaseFunction* function, std::shared_ptr<FunctionNode> left, std::shared_ptr<FunctionNode> right) :
	m_function(function),
	m_left(left),
	m_right(right)
{}


FunctionNode::~FunctionNode()
{
	delete m_function;
}

BaseFunction* FunctionNode::getFunction() const
{
	return m_function;
}

std::ostream& operator<<(std::ostream& os, const FunctionNode& other)
{
	//os << *(other.getFunction());
	os << "Function";
	return os;
}