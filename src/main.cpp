#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> a;

	int count = 0;
	std::cout << "Enter group A size" << std::endl;
	std::cin >> count;

	int num;
	
	for (int i = 0; i < count; ++i)
	{
		std::cin >> num;
		a.push_back(num);
	}

	std::ranges::sort(a);
	auto [newEnd, end] = std::ranges::unique(a);
	a.erase(newEnd, end);
	
	for (int i : a)
		std::cout << i << ", ";

	return 0;
}
