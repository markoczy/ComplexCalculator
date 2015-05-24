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


	/////////////////////////////////////////////////////// TEST 1 ____

	//// 2+3+x+y
	//// x=20
	//// y=50
	/*CParsedFcnEq f1("f1");
	
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
	std::cout << "Value is: " <<f1.getValue()<< std::endl;*/

	/////////////////////////////////////////////////////// ____ TEST 1


	//// (0.125*x)*y*(y/3)
	//// x=8
	//// y=3
	CParsedFcnEq f1("f1");
	f1.addParam("x");
	f1.addParam("y");

	// 0.125*x
	CFcnChainEq* s1 = new CFcnChainEq();
	s1->addOperation(new CConstEq(0.125), eOpType::MPL_EQ);
	s1->addOperation(new CVarEq("x"), eOpType::CONST_EQ);

	// y/3
	CFcnChainEq* s2 = new CFcnChainEq();
	s2->addOperation(new CVarEq("y"), eOpType::DIV_EQ);
	s2->addOperation(new CConstEq(3), eOpType::CONST_EQ);

	// S1 * y * S2
	f1.addOperation(s1, eOpType::MPL_EQ);
	f1.addOperation(new CVarEq("y"), eOpType::MPL_EQ);
	f1.addOperation(s2, eOpType::CONST_EQ);

	if (f1.validate())
	{
		std::cout << "Validation returns true" << std::endl;
	}
	else
	{
		std::cout << "Validation returns false" << std::endl;
	}

	f1.setParamValueAt(0, new CConstEq(8));
	f1.setParamValueAt(1, new CConstEq(3));

	std::cout << "Try get Value" << std::endl;
	std::cout << "Value is: " << f1.getValue() << std::endl;


	/////////////////////////////////////////////////////////

	CFunctionsPool fcns;

	//fcns.defineFunction("f22(xyz,yhg):=42x+y");


	CParsedFcnEq* exp_eq = fcns.getFunctionByName("exp");
	
	if (exp_eq != NULL)
	{
		exp_eq->setParamValueAt(0, new CConstEq(2));
		exp_eq->setParamValueAt(1, new CConstEq(2));
	}
	else
	{
		std::cout << "Error: could not find function" << std::endl;
		return -1;
	}


	std::cout << "Try get value:" << std::endl;
	std::cout << "value = " <<exp_eq->getValue()<< std::endl;

	std::cin.get();


	return 0;
}