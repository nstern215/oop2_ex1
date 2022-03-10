#include <iterator>
#include <algorithm>
#include <iostream>

#include "Group.h"

Group::Group(int size):
	m_pdata(std::make_unique<std::vector<int>>())
{
	readData(size);
}

//todo use pointer for the vector
Group::Group(std::vector<int>& data):
	m_pdata(std::make_unique<std::vector<int>>())
{
	for (const auto i : data)
		m_pdata->push_back(i);
	
	order();
}

void Group::readData(int size)
{
	int num;
	
	for (int i = 0; i < size; ++i)
	{
		std::cin >> num;
		m_pdata->push_back(num);
	}

	order();
}

std::vector<int>* Group::getData() const
{
	return m_pdata.get();
}

void Group::order() const
{
	std::ranges::sort(*m_pdata);
	auto [newEnd, end] = std::ranges::unique(*m_pdata);
	m_pdata->erase(newEnd, end);
}

std::ostream& operator<<(std::ostream& os, const Group& other)
{
	os << "{ ";
	std::ranges::copy(*(other.getData()), std::ostream_iterator<int>(os, ", "));
	os << " }";
	return os;
}