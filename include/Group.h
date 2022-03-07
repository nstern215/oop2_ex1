#pragma once
#include <vector>

class Group
{
public:
	Group(int size);

	std::vector<int> getData() const;
private:
	void readData(int size);
	
	std::vector<int> m_data;
};
