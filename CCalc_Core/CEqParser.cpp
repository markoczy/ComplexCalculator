#include "CEqParser.h"

bool CEqParser::validate(std::string equation)
{
	int paranthOpen = 0;

	for (unsigned int i = 0; i < equation.length(); i++)
	{
		char chr = equation.at(i);

		if (!_validateChar(chr))
		{
			std::cout << "Found invalid char: " << chr << std::endl;
			return false;
		}

		if (_isParOpen(chr))
		{
			paranthOpen++;
			continue;
		}
		else if (_isParClose(chr))
		{
			paranthOpen--;
			continue;
		}
		

	}

	return paranthOpen==0;
}


double CEqParser::parse(std::string equation)
{
	CChainEq* eq = (CChainEq*)_parse(equation);
	double rVal = eq->getValue();
	
	eq->clear();
	delete eq;

	return rVal;
}


bool CEqParser::_isParOpen(char chr)
{
	return chr=='(';
}

bool CEqParser::_isParClose(char chr)
{
	return chr == ')';
}

bool CEqParser::_isDecimal(char chr)
{
	for (int i = 0; i < DECIMALS_COUNT; i++)
	{
		if (chr == DECIMALS[i]) return true;
	}

	return false;
}

bool CEqParser::_isOperator(char chr)
{
	for (int i = 0; i < OPS_COUNT; i++)
	{
		if (chr == OPS[i]) return true;
	}

	return false;
}

eOpType CEqParser::_parseOperator(char chr)
{
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

CAbstractEq* CEqParser::_parse(std::string &eq)
{
	CChainEq* rVal = new CChainEq();

	//std::cout << "Trying to parse equation: " << eq.c_str() << std::endl;

	bool numReaderActive = false;
	bool createNumber = false;
	std::string numReader = "";
	CAbstractEq* number = NULL;

	bool hasNumber = false;
	bool hasOperator = false;

	bool hasChainEq = false;

	bool opReaderActive = false;
	bool createOp = false;
	std::string opReader = "";

	bool negateParam = false;

	int parCount = 0;

	eOpType op = eOpType::NULL_EQ;


	// Main loop
	for (unsigned int i = 0; i < eq.size(); i++)
	{
		char chr = eq.at(i);

		if (!opReaderActive)
		{
			

			// Activate Operation reader 
			// (means: create new linear Equation)
			if (_isParOpen(chr))
			{
				opReaderActive = true;
			}

			//// When closing paranthesis and not
			//// having any operator -> setOperator(*)
			//if (lastIsParClose)
			//{
			//	if (!_isOperator(chr))
			//	{
			//		// Not found operator: set MPL

			//	}
			//	else
			//	{
			//	
			//	}
			//}

			//////////////////////// NUMBERS ////////////////////////

			// Check Decimals
			bool isDecimal = _isDecimal(chr);

			// If no more decimals found:
			// Set flag to create number
			if (numReaderActive && !isDecimal)
			{
				createNumber = true;
			}

			// De- / Activate numReader
			numReaderActive = isDecimal;

			// Add Decimal
			if (numReaderActive)
			{
				numReader.push_back(chr);
			}

			// Convert number
			if (createNumber)
			{
				//std::cout << "Trying to parse number: " << numReader.c_str() << std::endl;
				number = new CConstEq(std::stod(numReader));
				numReader = "";
				createNumber = false;
				hasNumber = true;
			}

			// Look for negative nums
			if (!hasNumber && _parseOperator(chr) == SUB_EQ)
			{
				//std::cout << "Setting negate(true)" << std::endl;
				negateParam = true;
			}

			/////////////////////// OPERATORS ///////////////////////

			// If found Operator -> set
			if (_isOperator(chr))
			{
				op = _parseOperator(chr);
			}
			// Default Operators if paranthesis found
			// And number alrdy defined
			// NB: This is the failsave for eqs like: 2(3+4)5
			else if (hasNumber)
			{
				op = eOpType::MPL_EQ;
			}

			///////////////////////// UPDATE ////////////////////////

			hasOperator = (op != eOpType::NULL_EQ);
			
			if (hasNumber && hasOperator)
			{
				if (negateParam)
				{
					//std::cout << "Inside negate(true)" << std::endl;
					number = new CMplEq(number, new CConstEq(-1));
				}

				rVal->addOperation(number, op);

				// reset values
				hasNumber = false;
				op = eOpType::NULL_EQ;
				negateParam = false;
			}

		}
		else // if opReaderActive
		{
			////////////////////// SUBEQUATIONS /////////////////////

			if (_isParOpen(chr))
			{
				parCount++;
			}

			if (_isParClose(chr))
			{
				parCount--;
			}


			if (parCount < 0)
			{
				// parse
				number = _parse(opReader);

				hasNumber = true;
				opReaderActive = false;
				opReader="";
				parCount = 0;
			}
			else
			{
				opReader.push_back(chr);
			}

		}

	} // for all chars in str


	//////////////////////// FAILSAVE ///////////////////////

	if (numReaderActive)
	{
		//std::cout << "Trying to parse number: " << numReader.c_str() << std::endl;
		number = new CConstEq(std::stod(numReader));
		hasNumber = true;
		//std::cout << "Added Operator: const" << std::endl;
	}

	if (hasNumber)
	{
		if (negateParam)
		{
			number = new CMplEq(number, new CConstEq(-1));
		}

		rVal->addOperation(number, eOpType::CONST_EQ);
		negateParam = false;
	}

	return rVal;
}

bool CEqParser::_validateChar(char chr)
{
	for (int i = 0; i < DECIMALS_COUNT; i++)
	{
		if (chr == DECIMALS[i])
		{
			return true;
		}
	}
	
	for (int i = 0; i < OPS_COUNT;i++)
	{
		if (chr==OPS[i])
		{
			return true;
		}
	}

	for (int i = 0; i < ALPHAS_COUNT; i++)
	{
		if (chr == ALPHAS[i])
		{
			return true;
		}
	}

	if (chr == ')' || chr == '(')
	{
		return true;
	}

	return false;
}
