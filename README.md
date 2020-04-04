## cpsc350-assign3

Author Info:
* Logan Welsh
* 2325215
* lwelsh@chapman.edu
* CPSC-350-01

Description:
* A simple syntax checker: Checks whether all open brackets and parentheses in a given file are eventually closed.
* Utilises a custom-made array-based generic template stack.
* Easy to add other delimiters to check for (ex. \", \', \*).

Files:
* GenStack.h
* GenStack.cpp
* main.cpp
* example.txt


Instructions:
* Compile the included files (g++ \*.cpp).
* Run the executable (./a.out).
	* When run without any arguments, the program will use the included example file.
	* The program can accept one filename as an argument (./a.out foo.bar).

Sources:
* The GenStack class is a modified version of the stack we wrote in class.
* http://www.cplusplus.com/doc/tutorial/exceptions/
* http://www.cplusplus.com/reference/string/string/find/
* http://www.cplusplus.com/doc/oldtutorial/templates/
