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

int CCalcEngine::parse(std::string equation, double &value)
{
	if (cc::isFcnDefEq(equation))
	{
		value = 0;
		return _parseFunction(equation, false);
	}
	else
	{
		return _parseEquation(equation, value, false);
	}
}

int CCalcEngine::parseEquation(std::string equation, double &value)
{
	return _parseEquation(equation, value);
}

int CCalcEngine::parseFunction(std::string equation)
{
	return _parseFunction(equation);
}


int CCalcEngine::validate()
{

	return 0;
}

std::string CCalcEngine::parseReturnCode(int code)
{

	return 0;
}

//////////////////// PRIVATE ////////////////////

int CCalcEngine::_parse(std::string &equation, bool validate)
{

	return 0;
}

int CCalcEngine::_parseEquation(std::string &equation, double &value, bool validate)
{

	return 0;
}

int CCalcEngine::_parseFunction(std::string &equation, bool validate)
{

	return 0;
}

int CCalcEngine::_validate(std::string &equation)
{

	return 0;
}
