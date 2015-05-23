#include "CEqParser.h"
#include "CParsedFcnEq.h"

int main(int argc, char *argv[])
{
	////////////////////////////////// OLD CLI ____

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

	////////////////////////////////// ____ OLD CLI 

	//CFcnChainEq eq();

	
	//eq.addOperation(new CConstEq(2), eOpType::ADD_EQ);
	//eq.addOperation(new CConstEq(3), eOpType::ADD_EQ);
	//eq.addOperation(new CVarEq("x"), eOpType::ADD_EQ);
	//eq.addOperation(new CVarEq("y"), eOpType::CONST_EQ);

	//eq.setVar("x", 20);
	//eq.setVar("y", 50);

	//std::cout << "Value = " << eq.getValue() << std::endl;

	//// 2+3+x+y
	//// x=20
	//// y=50
	CParsedFcnEq f1("f1");
	
	f1.addOperation(new CConstEq(2), eOpType::ADD_EQ);
	f1.addOperation(new CConstEq(3), eOpType::ADD_EQ);
	f1.addOperation(new CVarEq("x"), eOpType::ADD_EQ);
	f1.addOperation(new CVarEq("y"), eOpType::CONST_EQ);
	f1.addParam("x");
	f1.addParam("y");

	if (f1.validate())
	{
		std::cout << "Validation returns true" << std::endl;
	}
	else
	{
		std::cout << "Validation returns false" << std::endl;
	}

	f1.setParamValueAt(0, new CConstEq(20));
	f1.setParamValueAt(1, new CConstEq(50));

	std::cout << "Try get Value" << std::endl;
	std::cout << "Value is: " <<f1.getValue()<< std::endl;


	std::cin.get();

}