#pragma once

#include <iostream>
#include <vector>
#include <math.h>

/**
* @brief Operation Types (i.e. child classes)
*/
enum eOpType
{
	NULL_EQ		= 0,
	CONST_EQ	= 1,
	ADD_EQ		= 2,
	SUB_EQ		= 3,
	MPL_EQ		= 4,
	DIV_EQ		= 5,
	EXP_EQ		= 6,
	FCN_EQ		= 7, // nyi
	CHAIN_EQ	= 8
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
