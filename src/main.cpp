#include <iostream>
#include <vector>

#include "Union.h"
#include "Difference.h"
#include "Intersection.h"
#include "FunctionNode.h"
#include "Composite.h"
#include "Product.h"

using std::string;

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const string help = "The available commands are:\n"
		"*eval(uate) num ... - compute the result of function #num on the following\n"
		"set(s); each set is prefixed with the count of numbers to read\n"
		"* uni(on) num1 num2 - Creates an operation that is the union of operation\n"
		"#num1 and operation #num2\n"
		"* inter(section) num1 num2 - Creates an operation that is the intersection\n"
		"of operation #num1 and operation #num2\n"
		"* diff(erence) num1 num2 - Creates an operation that is the difference of\n"
		"operation #num1 and operation #num2\n"
		"* prod(uct) num1 num2 - Creates an operation that returns the product of\n"
		"the items from the results of operation #num1 and operation #num2\n"
		"* comp(osite) num1 num2 - creates an operation that is the composition of\n"
		"operation #num1 and operation #num2\n"
		"* del(ete) num - delete operation #num from the operation list\n"
		"* help - print this command list\n"
		"* exit - exit the program";
	
	const auto unionFunc = std::make_unique<Union>();
	const auto intersectionFunc = std::make_unique<Intersection>();
	const auto differenceFunc = std::make_unique<Difference>();

	const auto compositeFunc = std::make_unique<Composite>();
	const auto productFunc = std::make_unique<Product>();

	std::vector<std::shared_ptr<FunctionNode>> operations = {
		std::make_shared<FunctionNode>(unionFunc.get(), nullptr, nullptr),
		std::make_shared<FunctionNode>(intersectionFunc.get(), nullptr, nullptr),
		std::make_shared<FunctionNode>(differenceFunc.get(), nullptr, nullptr)
	};

	string command;
	int right, left;


	while (true)
	{
		cout << "List of available set of operations:\n" << endl;

		for (int i = 0; i < operations.size(); ++i) 
		{
			char groupName = 65;

			cout << i << ".\t";

			operations[i]->printFunction(groupName);

			cout << "\n";
		}

		cout << "Enter command ('help' for the list of available commands): ";

		cin >> command;

		pos = command.find(" ");
		
		if (command == "exit")
			break;

		else if (command == "help")
			cout << help << endl;

		else if (command == "eval")
		{
			cin >> left;

			std::vector<Group*> groups;

			operations[left]->getGroups(groups);

			operations[left]->evaluate(groups);

		}
	
		else if (command == "uni")
		{
			cin >> left >> right;
			operations.push_back(std::make_shared<FunctionNode>(unionFunc.get(), operations[left], operations[right]));
		}

		else if (command == "comp")
		{
			cin >> left >> right;
			operations.push_back(std::make_shared<FunctionNode>(compositeFunc.get(), operations[left], operations[right]));
		}

		else if (command == "prod")
		{
			cin >> left >> right;
			operations.push_back(std::make_shared<FunctionNode>(productFunc.get(), operations[left], operations[right]));
		}

		else if (command == "inter")
		{
			cin >> left >> right;
			operations.push_back(std::make_shared<FunctionNode>(intersectionFunc.get(), operations[left], operations[right]));
		}

		else if (command == "diff")
		{
			cin >> left >> right;
			operations.push_back(std::make_shared<FunctionNode>(differenceFunc.get(), operations[left], operations[right]));
		}

		else if (command == "del")
		{
			cin >> left;
			operations.erase(operations.begin()+left);
		}
	
	}	
	
	return EXIT_SUCCESS;
}
