#include <iterator>
#include <algorithm>
#include <iostream>

#include "Group.h"

Group::Group(int size)
{
	readData(size);
}

void Group::readData(int size)
{
	int num;
	
	for (int i = 0; i < size; ++i)
	{
		std::cin >> num;
		m_data.push_back(num);
	}

	std::ranges::sort(m_data);
	auto [newEnd, end] = std::ranges::unique(m_data);
	m_data.erase(newEnd, end);
}

std::vector<int> Group::getData() const
{
	return m_data;
}

std::ostream& operator<<(std::ostream& os, const Group& other)
{
	auto data = other.getData();
	os << "{ ";
	std::ranges::copy(data, std::ostream_iterator<int>(os, ", "));
	os << " }";
}