#include "CFcnParser.h"

CParsedFcnEqV2* CFcnParser::parse(std::string equation)
{
	///
	/// Example:
	///
	/// func(x,y):=10x+(sin(y)/3)
	///
	/// 1. Parse fcn name (parent)
	/// 2. Parse param names (new child)
	/// 3. Parse equation
	///
	///   Loop
	///   {
	///       if number -> parse number
	///       if op     -> parse operator
	///       if alpha  -> is param ? set CVarEq : ParseFcnEq
	///   }
	///



	std::string fcnName = CFcnParser::_parseIdentifier(equation, it);

	DBOUT("fcnName = " << fcnName);

	CParsedFcnEqV2* rVal = new CParsedFcnEqV2(fcnName);

	mParamNames = _parseFcnParamNames(equation, it);

	DBOUT("current char = " << equation.at(it));

	it++;

	DBOUT("current char = " << equation.at(it));

	bool hasOp = _parseDefineOperator(equation, it);

	DBOUT("hasOp = " << hasOp);
	DBOUT("current char = " << equation.at(it));

	CChainEq_FCN * num = _parseEquation(equation, it);

	//DBOUT("value = " << num->getValue());


	/*while ((unsigned)it < equation.length() && equation.at(it) != ')')
	{
		char chr = equation.at(it);

		if (cc::isAlpha(chr))
		{
			std::string paramName = CEqParserV2::_parseIdentifier(equation, it);
			paramNames.push_back(paramName);
			DBOUT("parsing param: " << paramName);
		}
		else
		{
			it++;
		}
	}*/


	for (unsigned int i = 0; i < mParamNames.size();i++) 
	{
		DBOUT("param it = "<<i<<", name ="<<mParamNames.at(i));
		//num->addParam(mParamNames.at(i));
	}

	rVal->init(num,mParamNames);

	mParamNames.clear();
	it = 0;

	return rVal;
}


std::vector<std::string> CFcnParser::_parseFcnParamNames(std::string &equation, int &it)
{
	std::vector<std::string> rVal;

	while ((unsigned)it < equation.length() && equation.at(it) != ')')
	{
		char chr = equation.at(it);

		if (cc::isAlpha(chr))
		{
			std::string paramName = CEqParserV2::_parseIdentifier(equation, it);
			rVal.push_back(paramName);
			DBOUT("parsing param: " << paramName);
		}
		else
		{
			it++;
		}
	}

	return rVal;

}

bool CFcnParser::_parseDefineOperator(std::string &equation, int & it)
{
	bool rVal = false;

	if ((unsigned)it > equation.length() - 2)
	{
		return false;
	}

	return equation.at(it++) == ':' && equation.at(it++) == '=';

}

CChainEq_FCN* CFcnParser::_parseEquation(std::string &equation, int &it)
{
	CChainEq_FCN* rVal = new CChainEq_FCN();

	CAbstractEq* number = NULL;

	bool hasNum = false;
	bool hasOp = false;

	bool inverseNum = false;

	char chr = equation.at(it);

	while ((unsigned)it < equation.length())
	{

		//// Fast exit if statement ends
		//if(cc::isParClose(equation.at(it)))
		//{
		//	DBOUT("Called break");
		//	it+=2;
		//	break;
		//}

		chr = equation.at(it);
		DBOUT("it = " << it << ", char = " << chr);


		eOpType op = eOpType::NULL_EQ;

		if (cc::isDecimal(chr))
		{
			DBOUT("Found decimal: " << chr);
			number = _parseNumber(equation, it);
		}
		else if (cc::isParOpen(chr))
		{
			std::string sub = _getEqSubstr(equation, ++it);
			DBOUT("Found subEquation " << sub);

			int subIt = 0; // dummy
			number = _parseEquation(sub, subIt);
		}
		else if (cc::isAlpha(chr))
		{
			DBOUT("Found alpha " << chr);

			std::string ident = _parseIdentifier(equation, it);

			if (isFcnParam(ident))
			{
				DBOUT("Found function param : " << ident);
				number = new CVarEq(ident);
			}
			else
			{
				number = _parseFunction(ident,equation, it);
			}

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
				DBOUT("Try autoadd MPL (203) char is: " << chr);

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

				DBOUT("Adding Operation " << op);
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

	DBOUT("Returning equation, it = " << it);
	return rVal;

}


//CAbstractFcn* CFcnParser::_parseFunction(std::string &equation, int &it)
//{
//	//-//-//-//-//-//-//-//-//-//-//-//
//	// Example:	2+func((2+1),3)+42
//	//            ^
//	//-//-//-//-//-//-//-//-//-//-//-//
//
//
//	std::string fcnName = _parseIdentifier(equation, it);
//	DBOUT("Function name is " << fcnName);
//
//	CAbstractFcn * fcnEq = new CAbstractFcn();
//
//	// If function parsing failed or function 
//	// not found return
//	if (!fcnEq->init(mFcns, fcnName))
//	{
//		EROUT("Init Function failed, name not found: " << fcnName);
//		return fcnEq;
//	}
//
//	// Parse params -> CChain(2,1),CConst(3)
//	// (need subequations...)
//	int paramCount = fcnEq->getParamCount();
//	DBOUT("Init successful, paramCount is " << paramCount);
//
//	std::vector<CAbstractEq*> params; // XXX unneeded??
//
//	// skip first parOpen
//	if (paramCount>0) it++;
//
//	// TODO: Lambda -> paramCount=-1
//	for (int i = 0; i < paramCount; i++)
//	{
//		std::string paramSubstr = _getFcnParamSubstr(equation, it);
//		DBOUT("Param " << i << ", substring is: " << paramSubstr);
//		int subIt = 0;
//		CAbstractEq* param = _parseEquation(paramSubstr, subIt);
//		params.push_back(param);
//
//		fcnEq->addParamValue(param);
//	}
//
//
//	return fcnEq;
//}


bool CFcnParser::isFcnParam(std::string id)
{
	for (unsigned int i = 0; i < mParamNames.size(); i++)
	{
		if (!id.compare(mParamNames.at(i)))
		{
			return true;
		}
	}

	return false;
}