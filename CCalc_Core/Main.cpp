#include "CEqParserV2.h"
#include "CFunctionsPool.h"


int main(int argc, char *argv[])
{
	CEqParserV2 p;
	CFunctionsPool f;
	p.setFunctions(&f);

	double val = 0;

	//val = p.parse("-(3+2)3/1.5");
	//val = p.parse("-((3*2)+5-2)*2");
	//val = p.parse("2-(5*0.52)");
	//val = p.parse("2*-3");

	CAbstractFcnEq eq;
	if (eq.init(&f, "sin"))
	{
		std::cout << "Equation found!"<<std::endl;
	}

	eq.addParamValue(new CConstEq(3.14/2));
	val = eq.getValue();

	std::cout << "Value = " << val;

	std::cin.get();

	//delete f;
	return 0;
}