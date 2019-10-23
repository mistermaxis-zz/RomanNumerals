#include "pch.h"

std::string arabic_to_roman(int);

class ArabicRomanAssert {
private:
	const unsigned int arabicToConvert;
public:
	ArabicRomanAssert() = delete;
	explicit ArabicRomanAssert(const unsigned int arabicNumber) : arabicToConvert(arabicNumber){}
	void isConvertedToRoman(std::string romanNumber) const { ASSERT_EQ(romanNumber, arabic_to_roman(arabicToConvert)); }
};

ArabicRomanAssert assertThat(const unsigned int arabic_assert) { ArabicRomanAssert assert{ arabic_assert }; return assert; }

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

std::string arabic_to_roman(int arabic)
{
	std::string roman;
	while (arabic >= 10)
	{
		roman += "X";
		arabic -= 10;
	}
	while (arabic >= 1)
	{
		roman += "I";
		arabic--;
	}
	return roman;
}

TEST(RomanNumerals, 33_is_converted_to_XXXIII) {
	assertThat(33).isConvertedToRoman("XXXII");
}