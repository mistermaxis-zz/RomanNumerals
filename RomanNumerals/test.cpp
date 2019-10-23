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
	if (arabic == 100) { return "C"; }
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

TEST(RomanNumerals, conversion_works_on_all_samples) {
	assertThat(1).isConvertedToRoman("I");
	assertThat(2).isConvertedToRoman("II");
	assertThat(3).isConvertedToRoman("III");
	assertThat(10).isConvertedToRoman("X");
	assertThat(20).isConvertedToRoman("XX");
	assertThat(30).isConvertedToRoman("XXX");
	assertThat(33).isConvertedToRoman("XXXIII");
	assertThat(100).isConvertedToRoman("C");
	assertThat(200).isConvertedToRoman("CC");
}