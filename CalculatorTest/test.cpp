#include "pch.h"
#include <string>
#include <vector>
#include "..\Calculator\op.cpp"
#include "..\Calculator\memoryHandling.cpp"
#include "..\Calculator\validation.cpp"
#include "..\Calculator\dataManipulation.cpp"


using namespace std;

TEST(operationTest, Add) {
	const char operand = '+';
	EXPECT_EQ(Op::operation(operand, 2, 3), 5);
	EXPECT_EQ(Op::operation(operand, -1, 4), 3);
	EXPECT_EQ(Op::operation(operand, 500001, 2001), 502002);
	EXPECT_EQ(Op::operation(operand, 0, 0), 0);
	EXPECT_EQ(Op::operation(operand, 5.4, 10.2), 15.6);
	EXPECT_EQ(Op::operation(operand,  16.5, -6.5), 10);
}

TEST(operationTest, Subtract) {
	const char operand = '-';
	EXPECT_EQ(Op::operation(operand, 2, 3), -1);
	EXPECT_EQ(Op::operation(operand, -1, 4), -5);
	EXPECT_EQ(Op::operation(operand, 500001, 2001), 498000);
	EXPECT_EQ(Op::operation(operand, 0, 0), 0);
	//EXPECT_EQ(Op::operation(operand, 10.2, 5.4), 4.8);
	EXPECT_EQ(Op::operation(operand, 16.5 , -6.5 ), 23);
}

TEST(operationTest, Multiply) {
	const char operand = '*';
	EXPECT_EQ(Op::operation(operand, 2, 3), 6);
	EXPECT_EQ(Op::operation(operand, -1, 4), -4);
	EXPECT_EQ(Op::operation(operand, 500001, 2001), 1000502001);
	EXPECT_EQ(Op::operation(operand, 0, 0), 0);
	EXPECT_EQ(Op::operation(operand, 5.4, 10.2), 55.08);
	EXPECT_EQ(Op::operation(operand, 16.5, -6.5), -107.25);
}

TEST(operationTest, Divide) {

	const char operand = '/';
	EXPECT_EQ(Op::operation(operand, 2, 3), (double)2/3);
	EXPECT_EQ(Op::operation(operand, -1, 4), -0.25);
	EXPECT_EQ(Op::operation(operand, 500001, 2001), (double)500001/2001);
	EXPECT_EQ(Op::operation(operand, 0, 0), 0);
	EXPECT_EQ(Op::operation(operand, 5.4, 10.2), 5.4/10.2);
	EXPECT_EQ(Op::operation(operand, 16.5, -6.5), -16.5/6.5);
}


TEST(operateTest, StrAdd) {
	ASSERT_STREQ(Op::operate("2+3").c_str(), "5");
	ASSERT_STREQ(Op::operate("#1+4").c_str(), "3");
	ASSERT_STREQ(Op::operate("500001+2001").c_str(), "502002");
	ASSERT_STREQ(Op::operate("0+0").c_str(), "0");
	ASSERT_STREQ(Op::operate("5.4+10.2").c_str(), "15.6");
	ASSERT_STREQ(Op::operate("16.5+#6.5").c_str(), "10");

}

TEST(operateTest, StrSubtract) {
	ASSERT_STREQ(Op::operate("2-3").c_str(), "#1");
	ASSERT_STREQ(Op::operate("#1-4").c_str(), "#5");
	ASSERT_STREQ(Op::operate("500001-2001").c_str(), "498000");
	ASSERT_STREQ(Op::operate("0-0").c_str(), "0");
	ASSERT_STREQ(Op::operate("10.2-5.4").c_str(), "4.8");
	ASSERT_STREQ(Op::operate("16.5-#6.5").c_str(), "23");
}

TEST(operateTest, StrMultiply) {
	ASSERT_STREQ(Op::operate("2*3").c_str(), "6");
	ASSERT_STREQ(Op::operate("#1*4").c_str(), "#4");
	ASSERT_STREQ(Op::operate("1*2001").c_str(), "2001");
	ASSERT_STREQ(Op::operate("0*0").c_str(), "0");
	ASSERT_STREQ(Op::operate("5.4*10.2").c_str(), "55.08");
	ASSERT_STREQ(Op::operate("16.5*#6.5").c_str(), "#107.25");
}

TEST(operateTest, StrDivide) {

	ASSERT_STREQ(Op::operate("#1/4").c_str(), "#0.25");
	ASSERT_STREQ(Op::operate("0/0").c_str(), "0");
	ASSERT_STREQ(Op::operate("10/5").c_str(), "2");
	ASSERT_STREQ(Op::operate("30000/5000").c_str(), "6");

}

TEST(recursiveHellTest, Simple) {

	ASSERT_STREQ(Op::recursiveHell("-10-5").c_str(), "#15");
	ASSERT_STREQ(Op::recursiveHell("-11+55").c_str(), "44");
}

TEST(recursiveHellTest, Complex) {

	ASSERT_STREQ(Op::recursiveHell("-10+55*2").c_str(), "100");
	ASSERT_STREQ(Op::recursiveHell("(50/2)*2").c_str(), "50");

}

TEST(RunTest, SimpleCalc) {

	ASSERT_EQ(Op::run("10-5;"), 6);
	ASSERT_EQ(Op::run("5+6*(15-5);"), 6);
	ASSERT_EQ(Op::run("65/5;"), 6);

}

TEST(RunTest, AssignVar) {

	ASSERT_EQ(Op::run("x=10-5;"), 7);
	ASSERT_EQ(Op::run("y=5+6*(15-5);"), 7);
	ASSERT_EQ(Op::run("z=65/5;"), 7);

}

/*
TEST(RunTest, ErrorCode2) {
	EXPECT_EQ(Op::run("65/5"), 2);

}
*/


/*
TEST(MainTest, MockTest) {

	MockDataM NewMockDataM;

	string input = NewMockDataM.getUserInput();


	ASSERT_STREQ(input.c_str(), "");

}
*/


TEST(ParameterizedOpTest, ParameterizedAdd)
{
	const char operand = '+';
	
	struct Test {
		int a;
		int b;
		int sum;
	};

	const std::vector<Test> tests{ {
		{1, 2, 3},
		{4, 5, 9},
		{-5, 15, 10},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.sum;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOpTest, ParameterizedSubtract)
{
	const char operand = '-';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{2, 1, 1},
		{14, 5, 9},
		{1000, 0, 1000},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOpTest, ParameterizedMultiply)
{
	const char operand = '*';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{2, 1, 2},
		{14, 5, 70},
		{1000, 0, 0},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOpTest, ParameterizedDivide)
{
	const char operand = '/';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{0, 1000, 0},
		{15, 5, 3},
		{1000, 500, 2},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOperateTest, ParameterizedStrAdd)
{
	const char operand = '+';

	struct Test {
		int a;
		int b;
		int sum;
	};

	const std::vector<Test> tests{ {
		{1, 2, 3},
		{4, 5, 9},
		{-5, 15, 10},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.sum;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOperateTest, ParameterizedStrSubtract)
{
	const char operand = '-';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{2, 1, 1},
		{14, 5, 9},
		{1000, 0, 1000},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOperateTest, ParameterizedStrMultiply)
{
	const char operand = '*';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{2, 1, 2},
		{14, 5, 70},
		{1000, 0, 0},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedOperateTest, ParameterizedStrDivide)
{
	const char operand = '/';

	struct Test {
		int a;
		int b;
		int result;
	};

	const std::vector<Test> tests{ {
		{0, 1000, 0},
		{15, 5, 3},
		{1000, 500, 2},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::operation(operand, test.a, test.b);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}
}

TEST(ParameterizedRunTest, SimpleCalc) {

	struct Test {
		string a;
		int result;
	};

	const std::vector<Test> tests{ {
		{"10-5;", 6},
		{"5+6*(15-5);", 6},
		{"65/5;", 6},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::run(test.a);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}

}

TEST(ParameterizedRunTest, AssignVar) {

	struct Test {
		string a;
		int result;
	};

	const std::vector<Test> tests{ {
		{"x=10-5;", 7},
		{"x=5+6*(15-5);", 7},
		{"x=65/5;", 7},
	} };

	for (const auto& test : tests) {
		const auto actual = Op::run(test.a);
		const auto expected = test.result;
		ASSERT_EQ(actual, expected);
	}



}


TEST(EntegrasyonoperateTest, StrAdd) {
	struct Test {
		string a;
		string b;
		string result;
	};
	const std::vector<Test> inputs{ {
		{"10+5;","10+5","15"},
		{"6*10;","6*10","60"},
		{"65/5;","65/5","13"},
	} };

	for (const auto& input : inputs) {

		const auto input1 = DataM::delSpaces(input.a);
		const auto input2 = DataM::insMult(input1);
		const auto err = Val::inputVal(input2);
		ASSERT_EQ(err, 0);
		if (err == 0)
			ASSERT_STREQ(Op::operate(input.b).c_str(), input.result.c_str());
	}



}

TEST(EntegrasyonoperateTest, StrSubtract) {
	string a = "5-1;";
	string b = "5-1";
	string result = "4";

	const auto input1 = DataM::delSpaces(a);
	const auto input2 = DataM::insMult(input1);
	const auto err = Val::inputVal(input2);
	ASSERT_EQ(err, 0);
	if (err == 0)
		ASSERT_STREQ(Op::operate(b).c_str(), result.c_str());
}

TEST(EntegrasyonoperateTest, StrMultiply) {
	string a = "5*1;";
	string b = "5*1";
	string result = "5";

	const auto input1 = DataM::delSpaces(a);
	const auto input2 = DataM::insMult(input1);
	const auto err = Val::inputVal(input2);
	ASSERT_EQ(err, 0);
	if (err == 0)
		ASSERT_STREQ(Op::operate(b).c_str(), result.c_str());
}

TEST(EntegrasyonoperateTest, StrDivide) {

	string a = "5/1;";
	string b = "5/1";
	string result = "5";

	const auto input1 = DataM::delSpaces(a);
	const auto input2 = DataM::insMult(input1);
	const auto err = Val::inputVal(input2);
	ASSERT_EQ(err, 0);
	if (err == 0)
		ASSERT_STREQ(Op::operate(b).c_str(), result.c_str());

}

TEST(EntegrasyonrecursiveTest, Simple) {


	string a = "5-1;";
	string b = "5-1";
	string result = "4";

	const auto input1 = DataM::delSpaces(a);
	const auto input2 = DataM::insMult(input1);
	const auto err = Val::inputVal(input2);
	ASSERT_EQ(err, 0);
	if (err == 0)
		ASSERT_STREQ(Op::recursiveHell(b).c_str(), result.c_str());
}

TEST(EntegrasyonrecursiveTest, Complex) {

	string a = "(50/2)*2;";
	string b = "(50/2)*2";
	string result = "50";

	const auto input1 = DataM::delSpaces(a);
	const auto input2 = DataM::insMult(input1);
	const auto err = Val::inputVal(input2);
	ASSERT_EQ(err, 0);
	if (err == 0)
		ASSERT_STREQ(Op::recursiveHell(b).c_str(), result.c_str());

}

TEST(FakerOpTest, Add) {
	const char operand = '+';
	srand((unsigned)time(NULL));
	int a = rand();
	srand((unsigned)time(NULL));
	int b = rand();
	int result = a + b ;

	ASSERT_EQ(Op::operation(operand, a, b), result);

}

TEST(FakerOpTest, Subtract) {
	const char operand = '-';
	srand((unsigned)time(NULL));
	int a = rand();
	srand((unsigned)time(NULL));
	int b = rand();
	int result = a - b;

	ASSERT_EQ(Op::operation(operand, a, b), result);

}

TEST(FakerOpTest, Multiply) {
	const char operand = '*';
	srand((unsigned)time(NULL));
	int a = rand();
	srand((unsigned)time(NULL));
	int b = rand();
	int result = a * b;

	ASSERT_EQ(Op::operation(operand, a, b), result);

}

TEST(FakerOpTest, Divide) {

	const char operand = '/';
	srand((unsigned)time(NULL));
	int a = rand();
	srand((unsigned)time(NULL));
	int b = rand();
	int result = a / b;

	ASSERT_EQ(Op::operation(operand, a, b), result);

}

TEST(FakerOpTest, DivideToZero) {

	const char operand = '/';
	srand((unsigned)time(NULL));
	int a = rand();
	srand((unsigned)time(NULL));
	int b = 0;
	int result = 0;

	ASSERT_EQ(Op::operation(operand, a, b), result);

}


TEST(ValTest, inputValNotValid) {

	ASSERT_EQ(Val::inputVal("5+6*(15-5)"), 2); // If las charachter is not ';', return 0 

}

TEST(ValTest, inputValValid) {

	ASSERT_EQ(Val::inputVal("65/5;"), 0); // Otherwise return 0

}

TEST(ValTest, inputValQuit) {

	ASSERT_EQ(Val::inputVal("quit;"), 1); // Return 1 when input is quit;
	ASSERT_EQ(Val::inputVal("quit"), 1); // Return 1 when input is quit;

}


TEST(RunTest, quit) {

	EXPECT_EQ(Op::run("quit"), 1);


}