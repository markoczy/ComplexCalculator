#pragma once

#include "CC_Common.h"

#include "CAbstractEq.h"
#include "CAddEq.h"
#include "CSubEq.h"
#include "CMplEq.h"
#include "CDivEq.h"
#include "CConstEq.h"
#include "CExpEq.h"
#include "CChainEq.h"

#include "CFunctionsPool.h"
#include "CC_Common.h"

#include <string>

/**
*	@version	0.1.0
*	@author		A.Markoczy
*/
#define CC_VERSION "0.1.0"
#define CC_VER_STRLEN 10		//<! Must match with C# / Java header


///////////////////////// CLASS /////////////////////////

class CEqParser
{
public:
	
	/**
	* @brief Validates the equation string 
	* 
	* @param[in] equation The equation string
	*
	* @returns Equation valid
	*/
	bool validate(std::string equation);

	/**
	* @brief Parses string and returns value
	*
	* @param[in] equation The equation string
	*
	* @returns The result
	*/
	double parse(std::string equation);

private:

	//! 2-Dimensional Chain Equation
	CChainEq mainChn;

	/*bool _isDecimal(char chr);
	bool _isOperator(char chr);

	bool _isParOpen(char chr);
	bool _isParClose(char chr);

	bool _validateChar(char chr);*/

	CAbstractEq* _parse(std::string &equation);

	//eOpType _parseOperator(char chr);
};