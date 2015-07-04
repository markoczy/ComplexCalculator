#pragma once

#include "CC_Common.h"
#include "CC_Operation.h"

#include "CChainEq.h"
#include "CAbstractFcnEq.h"

#include "CFunctionsPool.h"

class CEqParserV2
{

public:

	void init(CFunctionsPool *fcns);
	
	// Checks if equation is valid
	bool validate(std::string equation);

	// Parses double value from equation
	double parse(std::string equation);

	static std::string _parseFunctionName(std::string &equation, int &it);


private:

	//// Class Members
	//
	int it;
	//
	std::string mEquation;
	//
	CFunctionsPool* mFcns;

	//// Parsing functions
	//
	CAbstractEq* _parseEquation(std::string &equation, int &it);
	//
	CConstEq* _parseNumber(std::string &equation, int &it);
	//
	eOpType _parseOperator(std::string &equation, int &it);
	//
	//static std::string _parseFunctionName(std::string &equation, int &it);
	//
	CAbstractFcnEq* _parseFunction(std::string &equation, int &it);
	
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


};