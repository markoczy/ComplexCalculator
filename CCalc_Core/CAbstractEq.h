#pragma once

#include <iostream>
#include <vector>
#include <math.h>

/**
* @brief Operation Types (i.e. child classes)
*/
enum eOpType
{
	NULL_EQ		= 0, // unset value
	CONST_EQ	= 1, // constant double
	VAR_EQ		= 2, // variable (for functions)
	ADD_EQ		= 3, // add operation
	SUB_EQ		= 4, // subtraction
	MPL_EQ		= 5, // multiplication
	DIV_EQ		= 6, // division
	EXP_EQ		= 7, // exponential
	CHAIN_EQ	= 9, // linear chain equation
	FCN_CH_EQ	= 8	 // function chain
};

class CAbstractEq
{
public:
	
	// Method will be overridden
	virtual double getValue(){ return 0; };

	virtual eOpType getEqType(){ return eqType; }

protected:

	eOpType eqType = NULL_EQ;
};
