#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>

using namespace std;

namespace Val{
	int inputVal (std::string);			//Validates the string the user inputs.
	int subInputVal (std::string);		//Validate each substring the user inputs.

	int sentenceVal(std::string input);
}

#endif
