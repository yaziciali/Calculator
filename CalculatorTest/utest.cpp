#include "pch.h"
#include <errno.h>
#include <string.h>
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
	// EXPECT_THROW(Op::operation(operand, 0, 0), std::invalid_argument); // std::invalid_argument
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