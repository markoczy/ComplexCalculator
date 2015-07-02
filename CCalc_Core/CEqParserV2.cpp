#include "CEqParserV2.h"

//-//-//-//-//-// PUBLIC //-//-//-//-//-//

void CEqParserV2::setFunctions(CFunctionsPool *fcns)
{
	mFcns = fcns;
}

// Checks if equation is valid
bool CEqParserV2::validate(std::string equation)
{

	return false;
}

// Parses double value from equation
double CEqParserV2::parse(std::string equation)
{
	it = 0;
	return _parseEquation(equation,it)->getValue();
}

//-//-//-//-//-// PRIVATE //-//-//-//-//-//

CAbstractEq* CEqParserV2::_parseEquation(std::string &equation, int &it)
{
	CChainEq* rVal = new CChainEq();

	CAbstractEq* number = NULL;

	bool hasNum = false;
	bool hasOp = false;

	bool inverseNum = false;

	char chr = equation.at(it);

	while ((unsigned)it < equation.length())
	{
		DBOUT("it = " << it<< ", char = "<<chr);

		//// Fast exit if statement ends
		//if(cc::isParClose(equation.at(it)))
		//{
		//	DBOUT("Called break");
		//	it+=2;
		//	break;
		//}

		char chr = equation.at(it);

		
		eOpType op = eOpType::NULL_EQ;
		
		if (cc::isDecimal(chr))
		{
			DBOUT("Found decimal: " << chr);
			number = _parseNumber(equation, it);
		}
		else if (cc::isParOpen(chr))
		{
			std::string sub = _getEqSubstr(equation, ++it);
			DBOUT("Found subEquation "<<sub);

			int subIt = 0; // dummy
			number = _parseEquation(sub, subIt);
		}
		else if (cc::isAlpha(chr))
		{
			std::string sub = _getFcnSubstr(equation, it);

			int subIt = 0; // dummy
			number = _parseFunction(sub, subIt);
		}
		else if (cc::isOperator(chr))
		{
			op = _parseOperator(equation, it);
		}
		else
		{
			it++;
		}

		hasNum = (number != NULL);
		hasOp = (op != eOpType::NULL_EQ);

		DBOUT("hasOp = " << hasOp << " hasNum = " << hasNum);



		if (hasNum)
		{
			bool doAdd = false;
			
			// Has Number and Operator
			if (hasOp)
			{
				doAdd = true;
			}
			// Default Operator "CONST" if finished
			else if ((unsigned)it >= equation.length())
			{
				op = eOpType::CONST_EQ;
				doAdd = true;
			}
			// Default Operator "MPL" if undefined
			else
			{
				chr = equation.at(it);

				// Subequation e.g. 4(2+3)
				//                   ^   ^
				doAdd |= cc::isParOpen(chr);
				
				// Function e.g. 4x
				//                ^
				doAdd |= cc::isAlpha(chr);

				// Decimal e.g. (2+3)4
				//                   ^
				doAdd |= cc::isDecimal(chr);

				if (doAdd)
				{
					op = eOpType::MPL_EQ;
				}
			}

			if (doAdd)
			{
				if (inverseNum) number = new CInvEq(number);
				
				DBOUT("Adding Operation "<<op);
				rVal->addOperation(number, op);
				op = eOpType::NULL_EQ;
				number = NULL;
				//
				hasNum = false;
				hasOp = false;
				inverseNum = false;
			} 

		}
		// Inverse negative 
		else
		{
			if (op == eOpType::SUB_EQ)
			{
				DBOUT("Setting inversenum = true");
				inverseNum = true;
			}
		
		}

	}

	if (hasNum)
	{
		if (inverseNum) number = new CInvEq(number);
		
		DBOUT("Adding Operation 101");
		rVal->addOperation(number, eOpType::CONST_EQ);
	}

	DBOUT("Returning equation, it = "<<it);
	return rVal;
}


//-//-// TEST ME !!!
CConstEq* CEqParserV2::_parseNumber(std::string &equation, int &it)
{
	CConstEq* rVal = new CConstEq(0);
	
	std::string num;

	int charCount = 0;

	while ((unsigned)it < equation.length())
	{
		char chr = equation.at(it);

		if (cc::isDecimal(chr))
		{
			num.push_back(chr);
			charCount++;
			it++;
		}
		else
		{
			DBOUT("NumberString = " << num);

			// Happens number ends (i.e. no dec char)
			rVal->setValue(std::stod(num));
			return rVal;
		}

	}

	DBOUT("NumberString = "<<num);

	// Happens when eq.length exceeded
	rVal->setValue(charCount>0 ? std::stod(num) : 0);
	return rVal;
}

//-//-// TEST ME !!!
eOpType CEqParserV2::_parseOperator(std::string &equation, int &it)
{
	char chr = (unsigned)it < equation.length() ? equation.at(it) : '\0';
	it++;

	DBOUT("OperatorString = " << chr);

	switch (chr)
	{
	case '+':
		return eOpType::ADD_EQ;
		break;
	case '-':
		return eOpType::SUB_EQ;
		break;
	case '/':
		return eOpType::DIV_EQ;
		break;
	case '*':
		return eOpType::MPL_EQ;
		break;
	case '^':
		return eOpType::EXP_EQ;
		break;
	default:
		return eOpType::NULL_EQ;
	}
}

CAbstractFcnEq* CEqParserV2::_parseFunction(std::string &equation, int &it)
{

	return NULL;
}

std::string CEqParserV2::_getEqSubstr(std::string &equation, int &it)
{
	//-//-//-//-//-//-//-//-//-//-//-//
	// Example: 22+(24-5/3.43+12)
	//             ^^
	//-//-//-//-//-//-//-//-//-//-//-//
	
	// Params
	int parCount = 1;
	char chr = equation.at(it);
	std::string rVal = "";

	//// Skip first parOpen
	//if (cc::isParOpen(chr))
	//{
	//	it++;
	//	chr = equation.at(it);
	//}

	// Loop
	while ((unsigned)it < equation.length() && parCount>0)
	{
		chr = equation.at(it);

		if (cc::isParOpen(chr))
		{
			parCount++;
		}
		else if (cc::isParClose(chr))
		{
			parCount--;
		}

		if (parCount > 0)
		{
			rVal.push_back(chr);
		}
		else
		{
			return rVal;
		}
		it++;

	}

	return rVal;
}

std::string CEqParserV2::_getFcnSubstr(std::string &equation, int &it)
{
	//-//-//-//-//-//-//-//-//-//-//-//
	// Example:	2+func((2+1),3)+42
	//            ^
	//-//-//-//-//-//-//-//-//-//-//-//

	// Parse fcn name -> "func"


	// Parse params -> CChain(2,1),CConst(3)
	// (need subequations...)


	return NULL;
}

bool CEqParserV2::_validate()
{

	return NULL;
}