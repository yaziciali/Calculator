#ifndef OP_H
#define OP_H

#include <iostream>

using namespace std;

namespace Op{
	string operate(string input);
	double operation(char op, double a, double b); 						//Check which operation and return its result.
	string recursiveHell(string input);
	int run(string);			//run the actual Calculator feature, returning possible sub-input errors. 
}

#endif
