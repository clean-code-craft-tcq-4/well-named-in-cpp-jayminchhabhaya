#include <iostream>
#include <assert.h>
#include"ColorCoder.hpp"
using namespace TelecommunicationsColorCoder;

ColorPair GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = 
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}
int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}


void testNumberToPair(int pairNumber,
   TelecommunicationsColorCoder::MajorColor expectedMajor,
   TelecommunicationsColorCoder::MinorColor expectedMinor)
{
    TelecommunicationsColorCoder::ColorPair colorPair = TelecommunicationsColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelecommunicationsColorCoder::MajorColor major,
    TelecommunicationsColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelecommunicationsColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelecommunicationsColorCoder::WHITE, TelecommunicationsColorCoder::BROWN);
    testNumberToPair(5, TelecommunicationsColorCoder::WHITE, TelecommunicationsColorCoder::SLATE);

    testPairToNumber(TelecommunicationsColorCoder::BLACK, TelecommunicationsColorCoder::ORANGE, 12);
    testPairToNumber(TelecommunicationsColorCoder::VIOLET, TelecommunicationsColorCoder::SLATE, 25);

    return 0;
}

