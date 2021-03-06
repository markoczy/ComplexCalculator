#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

//#include "CC_Function.h"

//// Operations
//
#include "DBOUT.h"

#include "CAbstractEq.h"
#include "StringsUI.h"  /// <<< WTF`??


#include "CC_Version.h"

//
////// Functions
////
//#include "CParsedFcnEq.h"
////
//// Exponential
////
//#include "CFcnExpEq.h"
//#include "CFcnLogEq.h"
////
//// Trigonometry
////
//#include "CFcnACosEq.h"
//#include "CFcnCosEq.h"
////
//#include "CFcnASinEq.h"
//#include "CFcnSinEq.h"
////
//#include "CFcnATanEq.h"
//#include "CFcnTanEq.h"
////
//#include "CFcnACotEq.h"
//#include "CFcnCotEq.h"
////
//////
//
//#include "CChainEq_FCN.h"

/////////////////////////////// PARSER CHARS ///////////////////////////////

const char ALPHAS[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
						'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
						'u', 'v', 'w', 'x', 'y', 'z' };
const int ALPHAS_COUNT = 26;

const char DECIMALS[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
const int DECIMALS_COUNT = 11;

const char OPS[] = { '+', '-', '*', '/', '^', ':', '=' };
const int OPS_COUNT = 5;

//////////////////////////// PARSER FUNCTIONS /////////////////////////////

const std::string X = "x";
const std::string Y = "y";
const std::string Z = "z";

// ATTENTION: Do not change order!
const std::string EXP_FCN_NAMES[] = { "exp", "log" };
const int EXP_FCN_NAMES_COUNT = 2;

// ATTENTION: Do not change order!
const std::string TRI_FCN_NAMES[] = {	"sin", "asin","cos","acos",
										"tan","atan","cot","acot" };
const int TRI_FCN_NAMES_COUNT = 8;




struct sFcnNames
{
	// Exponential
	//
	const char* EXP = "exp";
	const char* LOG = "log";

	// Trigonometry
	//
	const char* SIN = "sin";
	const char* ASIN = "asin";
	const char* COS = "cos";
	const char* ACOS = "acos";
	//
	const char* TAN = "tan";
	const char* ATAN = "atan";
	const char* COT = "cot";
	const char* ACOT = "acot";
	//
	const char* PI = "pi";
	const char* E = "e";

};
static sFcnNames fcnNames;



namespace cc
{
	// i.e. {'0', ... '9', '.'}
	bool isDecimal(char chr);

	// i.e. {'a', ... 'z'}
	bool isAlpha(char chr);

	// i.e. {'+', '-', '*', '/', '^' }
	bool isOperator(char chr);
	
	// i.e. "("
	bool isParOpen(char chr);
	
	// i.e. ")"
	bool isParClose(char chr);
	
	// i.e. ":="
	bool isFcnDefOp(char chr1, char chr2);

	// i.e. contains ":="
	bool isFcnDefEq(std::string &eq);

	// returns if char is allowed
	// for a definition
	bool validateChar(char chr);

	// Checks if has paranthesis
	// returns -1 if ')', +1 if '('
	// 0 if no paranthesis
	int parseParanthesis(char chr);

	// returns the operation type
	// of the char (@see eOpType)
	eOpType parseOperator(char chr);

	// Clears equation and sets pointer to 0
	//
	void clearEquation(CAbstractEq* aValue);

}


