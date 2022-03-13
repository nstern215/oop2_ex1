#include <algorithm>
#include <iostream>

#include "Group.h"

#include <string>

Group::Group(int size) :
	m_data(std::make_unique<std::vector<int>>())
{
	readData(size);
}

Group::Group(std::vector<int>& data) :
	m_data(std::make_unique<std::vector<int>>())
{
	for (const auto i : data)
		m_data->push_back(i);

	order();
}

void Group::readData(int size) const
{
	int num;

	for (int i = 0; i < size; ++i)
	{
		std::cin >> num;
		m_data->push_back(num);
	}

	order();
}

std::vector<int>* Group::getData() const
{
	return m_data.get();
}

void Group::order() const
{
	std::ranges::sort(*m_data);
	auto [newEnd, end] = std::ranges::unique(*m_data);
	m_data->erase(newEnd, end);
}

std::ostream& operator<<(std::ostream& os, const Group& other)
{
	os << "{ ";

	std::string dataStr;
	for (const int i : *(other.getData()))
		dataStr+= std::to_string(i) + ", ";

	const std::string fixedStr = dataStr.substr(0, dataStr.size() - 2);
	
	os << fixedStr << " }";
	return os;
}