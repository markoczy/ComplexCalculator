#include "CCalcEngine.h"

//////////////////// PUBLIC ////////////////////


CCalcEngine::CCalcEngine()
{
	mParser.init(&mFunctions);
	mFcnParser.init(&mFunctions);

}

CCalcEngine::~CCalcEngine()
{


}

int CCalcEngine::parse(std::string equation, double &aValue)
{
	if (cc::isFcnDefEq(equation))
	{
		aValue = 0;
		return _parseFunction(equation, false);
	}
	else
	{
		return _parseEquation(equation, aValue, false);
	}
}

int CCalcEngine::parseEquation(std::string equation, double &aValue)
{
	return _parseEquation(equation, aValue);
}

int CCalcEngine::parseFunction(std::string equation)
{
	return _parseFunction(equation);
}


int CCalcEngine::deleteFunction(std::string name)
{
	if (mFunctions.deleteFunctionByName(name))
	{
		return OK_GENERAL;
	}
	else
	{
		return NOK_GENERAL;
	}

}


int CCalcEngine::validate(std::string equation)
{

	return 0;
}

std::string CCalcEngine::parseReturnCode(int code)
{

	return 0;
}

//////////////////// PRIVATE ////////////////////


int CCalcEngine::_parseEquation(std::string &equation, double &aValue, bool validate)
{
	/// TODO: Validate

	double val = 0;
	int rVal = mParser.parse(equation, aValue);

	if (cc::err::isSuccess(rVal))
	{
		return OK_PARSED_EQUATION;
	}
	else
	{
		return rVal;
	}

	return 0;
}

int CCalcEngine::_parseFunction(std::string &equation, bool validate)
{
	CParsedFcnEqV2* fcn = mFcnParser.parse(equation);

	// TODO: more error codes
	if (mFunctions.addFunction(fcn))
	{
		return OK_CREATED_FUNCTION;
	}
	else
	{
		return NOK_FCN_NAME_EXISTS;
	}
}



int CCalcEngine::_validate(std::string &equation)
{

	return 0;
}
