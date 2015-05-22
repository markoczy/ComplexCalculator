#include "CEqParser.h"

int main(int argc, char *argv[])
{
	/*CEqParser parser;

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
	}*/


	CFcnChainEq eq;

	// 2+3+x+y
	// x=20
	// y=50

	eq.addOperation(new CConstEq(2), eOpType::ADD_EQ);
	eq.addOperation(new CConstEq(3), eOpType::ADD_EQ);
	eq.addOperation(new CVarEq("x"), eOpType::ADD_EQ);
	eq.addOperation(new CVarEq("y"), eOpType::CONST_EQ);

	eq.setVar("x", 20);
	eq.setVar("y", 50);

	std::cout << "Value = " << eq.getValue() << std::endl;

	std::cin.get();

}