#include "../Project1/Project2/Price4.h"
#include "gtest/gtest.h"
#include "pch.h"

TEST(Price4Test, FromString) {
	Price4 price1 = Price4("1234");
	EXPECT_EQ(price1.unscaled(), 12340000);
}

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}