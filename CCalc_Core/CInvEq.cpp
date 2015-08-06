#include "CInvEq.h"

CInvEq::CInvEq(CAbstractEq* value)
{
	this->value = value;
	this->eqType = eOpType::INV_EQ;
}

int CInvEq::getValue(double &aValue)
{
	int rVal = 0;
	double val = 0;

	// Get first value, exit on error
	rVal = value->getValue(val);
	if (!cc::err::isSuccess(rVal)) return rVal;

	aValue = -1.0*(val);

	return OK_GENERAL;
}
