#include "CEqParser.h"

int main(int argc, char *argv[])
{
	CEqParser parser;

	if (argc == 2)
	{
		if (!parser.validate(argv[1]))
		{
			std::cout << "Error: Equation not valid" << std::endl;
			return -1;
		}
		
		double finalVal = parser.parse(argv[1]);
		std::cout.precision(15);
		std::cout<< finalVal << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Error: Argument count not matching: " << argc << std::endl;
		return -1;
	}

	//std::cin.get();

}