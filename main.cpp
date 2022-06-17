#include <iostream>
#include <assert.h>
#include"TelecommunicationsColor.hpp"
using namespace TelecommunicationsColor;

TelecommunicationsColor::ColorPair *ObjectOfColorPair{};
void testNumberToPair(int pairNumber,
   MajorColor expectedMajor,
   MinorColor expectedMinor)
{
    TelecommunicationsColor::ColorPair colorPair = ObjectOfColorPair->GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    MajorColor major,
    MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = ObjectOfColorPair->GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}
int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
	ObjectOfColorPair->print_colorpair();
    return 0;
}

