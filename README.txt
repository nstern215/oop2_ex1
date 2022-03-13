1.
ex01 "Group Calculator"

2.
Netanel Stern, ID 206342255
Daniel Yosef, ID 322017518

3.
	This program will represent a calculator for group problems. The program
	will allow the user to define different types of problems. In addition 
	the program will give the user the ability to give the program groups and
	the number of the type of problem he would like the program to solve.

4.
	we created a unique pointer for each type of function. And start of the 
	program with the three main types of functions.
	According to the command givin by the user, we will add/delete/eval and
	more, the gourps that will also be givin by the user.
	The program will print and caculate threw the recursion algorithem.	

5.
	HEADER: - FunctionNode: This file holds the class of FunctionNode and 
							all of its functions.
			- Composite: This file holds the class of Compsite that inherats
						 from BaseFunction and all of its functions and 
						 operators.
			
			- Difference: This file holds the class of Difference that inherats
						 from BaseFunction and all of its functions and 
						 operators.

			- BaseFunction: This file holds the class of BaseFunction 
							and all of its functions and operators.

			- Group: This file holds the class of Group and all of its 
					 functions and operators.

			- Intersction: This file holds the class of intersection that
						   inherats from BaseFunction and all of its functions
						   and operators.

			- Product: This file holds the class of Product that inherats
						 from BaseFunction and all of its functions and 
						 operators.

			- Union: This file holds the class of union that inherats
						 from BaseFunction and all of its functions and 
						 operators.

	CPP: - FunctionNode: Holds the setting of this classes functions. 

			- Composite: Holds the setting of this classes functions.
			
			- Difference: Holds the setting of this classes functions.

			- BaseFunction: Holds the setting of this classes functions.

			- Group: Holds the setting of this classes functions.

			- Intersction: Holds the setting of this classes functions.

			- Product: Holds the setting of this classes functions.

			- Union: Holds the setting of this classes functions.

6.
	- Vector holding the commands added to the list.

	- Vector holding the list of groups that will be filled in according to the
	  need of the command that is wanted to be evalueted.

	-
7. 
	- recursion in order to print the list of commands.

	- recursion in order to calculate a command that was selected from the 
	  list.

	
