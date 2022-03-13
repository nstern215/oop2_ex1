#pragma once
#include <vector>

class Group
{
public:
	Group(int size);
	Group(std::vector<int>& data);

	std::vector<int>* getData() const;

private:
	void readData(int size) const;
	void order() const;

	std::unique_ptr<std::vector<int>> m_data;
};
std::ostream& operator<<(std::ostream& os, const Group& other);