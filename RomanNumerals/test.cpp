#include "pch.h"

std::string arabic_to_roman(unsigned int);

struct ArabicRoman {
	unsigned int Arabic;
	std::string Roman;
};

const std::size_t MappingSize = 13;

using ArabicRomanMappings = std::array<ArabicRoman, MappingSize>;

const ArabicRomanMappings arabic_roman_mappings =
{ { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} } };

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

std::string arabic_to_roman(unsigned int arabic)
{
	std::string roman;

	for (auto& mapping : arabic_roman_mappings)
	{
		while (arabic >= mapping.Arabic)
		{
			roman += mapping.Roman;
			arabic -= mapping.Arabic;
		}
	}

	return roman;
}

TEST(RomanNumerals, conversion_works_on_all_samples) {
	assertThat(1).isConvertedToRoman("I");
	assertThat(2).isConvertedToRoman("II");
	assertThat(3).isConvertedToRoman("III");
	assertThat(4).isConvertedToRoman("IV");
	assertThat(5).isConvertedToRoman("V");
	assertThat(6).isConvertedToRoman("VI");
	assertThat(9).isConvertedToRoman("IX");
	assertThat(10).isConvertedToRoman("X");
	assertThat(20).isConvertedToRoman("XX");
	assertThat(30).isConvertedToRoman("XXX");
	assertThat(33).isConvertedToRoman("XXXIII");
	assertThat(40).isConvertedToRoman("XL");
	assertThat(50).isConvertedToRoman("L");
	assertThat(90).isConvertedToRoman("XC");
	assertThat(100).isConvertedToRoman("C");
	assertThat(200).isConvertedToRoman("CC");
	assertThat(300).isConvertedToRoman("CCC");
	assertThat(333).isConvertedToRoman("CCCXXXIII");
	assertThat(400).isConvertedToRoman("CD");
	assertThat(500).isConvertedToRoman("D");
	assertThat(900).isConvertedToRoman("CM");
	assertThat(1000).isConvertedToRoman("M");
	assertThat(2000).isConvertedToRoman("MM");
	assertThat(3000).isConvertedToRoman("MMM");
	assertThat(3333).isConvertedToRoman("MMMCCCXXXIII");
	assertThat(3999).isConvertedToRoman("MMMCMXCIX");
}