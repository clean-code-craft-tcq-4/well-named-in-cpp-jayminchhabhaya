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
   MajorColor expectedMajor,
   MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    MajorColor major,
    MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}
int main() {
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    std::cout << "Pair no. "<<"   "<<"Major color"<<"   "<<"Minor color"<<std::endl;
	for(int i = 1 ;i <=(numberOfMajorColors * numberOfMinorColors);++i)
	{
		ColorPair colorPair = GetColorFromPairNumber(i);
		std::cout <<i<<"   "<<colorPair.ToString()<<std::endl;
	}
    return 0;
}

