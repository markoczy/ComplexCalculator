#include "CEqParserV2.h"
#include "CFunctionsPool.h"

#include "StringTools.h"


int main(int argc, char *argv[])
{
	/*CEqParserV2 p;
	CFunctionsPool f;
	p.setFunctions(&f);

	double val = 0;
*/
	//val = p.parse("-(3+2)3/1.5");
	//val = p.parse("-((3*2)+5-2)*2");
	//val = p.parse("2-(5*0.52)");
	//val = p.parse("2*-3");

	/*CAbstractFcnEq eq;
	if (eq.init(&f, "sin"))
	{
		std::cout << "Equation found!"<<std::endl;
	}

	eq.addParamValue(new CConstEq(3.14/2));
	val = eq.getValue();

	std::cout << "Value = " << val;*/

	 //TEST . . .
	//CEqParserV2 p;
	//std::string eq = "funct(23+(30+(3*2)-1),21+3/7)+42";
	///*std::string eq = "2+func((2+1),3)+42";*/
	//int it = 0;
	//std::string fcnSub = p._parseFunctionName(eq, it);
	//std::string rest = eq.substr(it);

	//DBOUT("Fcn =  " + fcnSub);
	//DBOUT("Rest =  " + rest);
	// . . . TEST
	std::cout << "+----------------------------------------------------------+"<<std::endl;
	std::cout << "|  ComplexCalculator V0.5 (test CLI)        Author: A.M.   |" << std::endl;
	std::cout << "|                                                          |" << std::endl;
	std::cout << "|  Source: https://github.com/markoczy/ComplexCalculator   |" << std::endl;
	std::cout << "+----------------------------------------------------------+" << std::endl;
	//std::cout << "+***********************************************************" << std::endl;
	//std::cout << "############################################################" << std::endl;
	std::cout << std::endl;
	
	CEqParserV2 p;
	CFunctionsPool f;
	p.init(&f);

	std::string input = "";
	while (str::toUpper(input).compare("/EXIT"))
	{
		char buf[256];
		std::cout << "Input : ";
		std::cin.getline(buf,256);
		input = buf;

		if (input.size()>0 && input.at(0)!='/')
		{
			double val = p.parse(input);
			std::cout << "Output: "<< val << std::endl << std::endl;
		}
	}
	/*double val = p.parse("exp(sin(0.8),2)");
	std::cout << "Value = " << val;*/
	
	std::cout << "Exit called, press <ENTER> to quit.";
	std::cin.get();

	//delete f;
	return 0;
}