#include "pch.h"
#include "..\Calculator\op.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CubbyCalcTest, TestAdd) {
	CubbyCalc calc;
	EXPECT_EQ(calc.add(2, 3), 5);
	EXPECT_EQ(calc.add(-1, 4), 3);
	EXPECT_EQ(calc.add(0, 0), 0);
}

TEST(CubbyCalcTest, TestSubtract) {
	CubbyCalc calc;
	EXPECT_EQ(calc.subtract(2, 3), -1);
	EXPECT_EQ(calc.subtract(-1, 4), -5);
	EXPECT_EQ(calc.subtract(0, 0), 0);
}

TEST(CubbyCalcTest, TestMultiply) {
	CubbyCalc calc;
	EXPECT_EQ(calc.multiply(2, 3), 6);
	EXPECT_EQ(calc.multiply(-1, 4), -4);
	EXPECT_EQ(calc.multiply(0, 0), 0);
}

TEST(CubbyCalcTest, TestDivide) {
	CubbyCalc calc;
	EXPECT_EQ(calc.divide(6, 3), 2);
	EXPECT_EQ(calc.divide(-8, 4), -2);
	EXPECT_THROW(calc.divide(5, 0), std::invalid_argument);
}