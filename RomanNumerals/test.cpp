#include "pch.h"

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

std::string arabic_to_roman(const int arabic)
{
	return "II";
}

TEST(RomanNumerals, 1_is_converted_to_I) {
	ASSERT_EQ("I", arabic_to_roman(1));
}