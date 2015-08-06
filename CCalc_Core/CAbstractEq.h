#pragma once

#include "CC_Error.h"

/**
* @brief Operation Types (i.e. child classes)
*/
enum eOpType
{
	//////////////////////////////////////////////////
	// 100+  : Single Operations (e.g. Constant)	//
	// 200+  : Dual Operations (e.g. Add)			//
	// 300+  : Built-in functions					//
	// 1000+ : Chains								//
	// 2000+ : Special								//
	//////////////////////////////////////////////////
	NULL_EQ = 0,	// unset value					//
	//////////////////////////////////////////////////
	CONST_EQ = 101,	// constant (double)			//
	INV_EQ = 102,	// inversed						//
	VAR_EQ = 110,	// variable (for functions)		//
	//////////////////////////////////////////////////
	ADD_EQ = 201,	// addition						//
	SUB_EQ = 202,	// subtraction					//
	MPL_EQ = 203,	// multiplication				//
	DIV_EQ = 204,	// division						//
	//////////////////////////////////////////////////
	EXP_EQ = 301,	// exponential function			//
	//////////////////////////////////////////////////
	CHAIN_EQ = 1000, // linear chain equation		//
	FCN_CH_EQ = 1001,	// function chain			//
	//////////////////////////////////////////////////
	FCN_EQ = 2000	// parsed function				//
	//////////////////////////////////////////////////
};

class CAbstractEq
{
public:
	
	// Method will be overridden
	virtual int getValue(double &aValue){ return NOK_BAD_INIT; };

	// Used to delete all member Equations
	// is called during getValue() call
	virtual void clear(){};

	virtual eOpType getEqType(){ return eqType; }


protected:

	eOpType eqType = NULL_EQ;

	
};
