#include "CAbstractEq.h"
#include "CAddEq.h"
#include "CSubEq.h"
#include "CMplEq.h"
#include "CDivEq.h"
#include "CConstEq.h"
#include "CExpEq.h"
#include "CChainEq.h"

#include "CFunctionsPool.h"

#include <string>

/**
*	@version	0.1.0
*	@author		A.Markoczy
*/
#define CC_VERSION "0.1.0"
#define CC_VER_STRLEN 10		//<! Must match with C# / Java header

/////////////////////// CONSTANTS ///////////////////////

const char ALPHAS[] =	{	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
							'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
							'u', 'v', 'w', 'x', 'y', 'z' };
const int ALPHAS_COUNT = 26;

const char DECIMALS[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
const int DECIMALS_COUNT = 11;

const char OPS[] = { '+', '-', '*', '/', '^' };
const int OPS_COUNT = 5;

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

	bool _isDecimal(char chr);
	bool _isOperator(char chr);

	bool _isParOpen(char chr);
	bool _isParClose(char chr);

	bool _validateChar(char chr);

	CAbstractEq* _parse(std::string &equation);

	eOpType _parseOperator(char chr);
};