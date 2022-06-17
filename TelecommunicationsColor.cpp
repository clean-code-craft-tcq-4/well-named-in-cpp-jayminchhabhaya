#include <string>
#include <iostream>
#include "TelecommunicationsColor.hpp"
namespace TelecommunicationsColor
{
    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

	ColorPair GetColorFromPairNumber(int pairNumber) {
    int BasedPairNumber = pairNumber - 1;
    MajorColor majorColor = 
        (MajorColor)(BasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(BasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
       return major * numberOfMinorColors + minor + 1;
    }
}
