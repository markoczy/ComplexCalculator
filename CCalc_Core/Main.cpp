#include "CEqParserV2.h"
#include "CFunctionsPool.h"
#include "CFcnParser.h"

#include "StringTools.h"

void initCLI()
{
	std::cout << "+----------------------------------------------------------+" << std::endl;
	std::cout << "|  ComplexCalculator V0.5 (test CLI)        Author: A.M.   |" << std::endl;
	std::cout << "|                                                          |" << std::endl;
	std::cout << "|  Source: https://github.com/markoczy/ComplexCalculator   |" << std::endl;
	std::cout << "+----------------------------------------------------------+" << std::endl;
	std::cout << std::endl;

	CEqParserV2 p;
	CFunctionsPool f;
	p.init(&f);

	std::string input = "";
	while (str::toUpper(input).compare("/EXIT"))
	{
		char buf[256];
		std::cout << "Input : ";
		std::cin.getline(buf, 256);
		input = buf;

		if (input.size()>0 && input.at(0) != '/')
		{
			double val = p.parse(input);
			std::cout << "Output: " << val << std::endl << std::endl;
		}
	}
	/*double val = p.parse("exp(sin(0.8),2)");
	std::cout << "Value = " << val;*/

	std::cout << "Exit called, press <ENTER> to quit.";
	std::cin.get();


}


////
//// Author: A. Markóczy
////
int main(int argc, char *argv[])
{
	CFcnParser p;
	CFunctionsPool pool;

	p.init(&pool);

	DBOUT("======= PARSING FUNCTION =======");
	//CParsedFcnEqV2 newFcn = p.parse("func(x,y,z):=10x+(y)+z*0.5");
	//CParsedFcnEqV2 newFcn = p.parse("func(x):=(((2x)+5)/2)+12+0.5+x");
	CParsedFcnEqV2 newFcn = p.parse("func(x):=sin((2x+15)0.125)");
	
	std::vector<double> input;
	input.push_back(10);
	//input.push_back(3);
	//input.push_back(6);
	
	DBOUT("======= PARSING EQUATION =======");

	double val = newFcn.getValue(input);
	DBOUT("value = " << val);

	std::cin.get();

	//initCLI();

	return 0;
}


