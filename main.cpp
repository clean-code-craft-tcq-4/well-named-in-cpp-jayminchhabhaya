#include <iostream>
#include <assert.h>
#include"TelecommunicationsColor.hpp"
using namespace TelecommunicationsColor;

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
	std::cout << "25-pair color code" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
	std::cout << "| Pair no. | Major color | Minor color |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
	for(int i = 1 ;i <=(numberOfMajorColors * numberOfMinorColors);++i)
	{
		ColorPair colorPair = GetColorFromPairNumber(i);
		std::cout <<i<<"|   "<<colorPair.ToString()<<"\t |"<<std::endl;
		if(i%5 == 0)
		{
			 std::cout << "----------------------------------------" << std::endl;
		}
	}
    return 0;
}

