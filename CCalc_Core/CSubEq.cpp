#include "CSubEq.h"

CSubEq::CSubEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::SUB_EQ;
}

int CSubEq::getValue(double &aValue)
{
	int rVal = 0;
	double v1 = 0, v2 = 0;

	// Get first value, exit on error
	rVal = value1->getValue(v1);
	if (!cc::err::isSuccess(rVal)) return rVal;

	// Get second value, exit on error
	rVal = value2->getValue(v2);
	if (!cc::err::isSuccess(rVal)) return rVal;

	aValue = v1 - v2;

	return OK_GENERAL;
}

void CSubEq::clear()
{
	DBOUT("Try Clear");
	cc::clearEquation(value1);
	cc::clearEquation(value2);
	DBOUT("Clear OK");
}