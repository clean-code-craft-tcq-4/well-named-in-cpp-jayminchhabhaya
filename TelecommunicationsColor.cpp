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

	ColorPair ColorPair::GetColorFromPairNumber(int pairNumber) {
    int BasedPairNumber = pairNumber - 1;
    MajorColor majorColor = 
        (MajorColor)(BasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(BasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
    }
    int ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
       return major * numberOfMinorColors + minor + 1;
    }
	std::string ColorPair::ToString() {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " \t    ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
	void ColorPair::print_colorpair()
	{
		std::cout << "25-pair color code" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "| Pair no. | Major color | Minor color |" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		for(int i = 1 ;i <=(numberOfMajorColors * numberOfMinorColors);++i)
		{
			ColorPair colorPair = GetColorFromPairNumber(i);
			std::cout <<"|   "<<i<<" \t   |  "<<colorPair.ToString()<<"\t |"<<std::endl;
			if(i%5 == 0)
			{
				std::cout << "----------------------------------------" << std::endl;
			}
		}
	}
}
