#include "pch.h"
#include "../Project2/Price4.h"


TEST(Price4Test, FromString)
{
	const Price4 price1("1234");
	EXPECT_EQ(price1.unscaled(), 12340000);

	const Price4 price2("123.4");
	EXPECT_EQ(price2.unscaled(), 1234000);

	const Price4 price3("12.34");
	EXPECT_EQ(price3.unscaled(), 123400);

	const Price4 price4("1.234");
	EXPECT_EQ(price4.unscaled(), 12340);

	const Price4 price5("0.1234");
	EXPECT_EQ(price5.unscaled(), 1234);

	const Price4 price6("0.01234");
	EXPECT_EQ(price6.unscaled(), 123);

	const Price4 price7("0.001234");
	EXPECT_EQ(price7.unscaled(), 12);
}
