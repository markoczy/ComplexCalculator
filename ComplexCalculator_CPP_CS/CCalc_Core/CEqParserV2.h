#pragma once

#include "CC_Common.h"
#include "CC_Operation.h"

#include "CChainEq.h"
//#include "CFunctionEq.h"
#include "CFunctionEq.h"

#include "CFunctionsPool.h"

class CEqParserV2
{

public:

	virtual void init(CFunctionsPool *fcns);
	
	// Checks if equation is valid
	virtual bool validate(std::string equation);

	// Parses double value from equation
	int parse(std::string equation, double &aValue);

	static std::string _parseIdentifier(std::string &equation, int &it);


protected:

	//// Class Members
	//
	int it;
	//
	std::string mEquation;
	//
	CFunctionsPool* mFcns;

	//// Parsing functions
	//
	virtual CAbstractEq* _parseEquation(std::string &equation, int &it);
	//
	virtual CConstEq* _parseNumber(std::string &equation, int &it);
	//
	virtual eOpType _parseOperator(std::string &equation, int &it);
	//
	//static std::string _parseFunctionName(std::string &equation, int &it);
	//
	virtual CFunctionEq* _parseFunction(std::string fcnName, std::string &equation, int &it);
	
	//// Substring
	//
	static std::string _getEqSubstr(std::string &equation, int &it);
	//
	static std::string _getFcnSubstr(std::string &equation, int &it);
	//
	static std::string _getFcnParamSubstr(std::string &equation, int &it);

	//// Validating
	//
	bool _validate();

	//void _reset(); // considering...

};