#pragma once

#include "dataManipulation.h"
//#include <gmock/gmock.h>

class MockDataM : public DataM {
public:
	virtual string getUserInput() = 0;
	MOCK_METHOD(string, getUserInput, ());
};

