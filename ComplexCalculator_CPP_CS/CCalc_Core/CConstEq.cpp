#include "CConstEq.h"

CConstEq::CConstEq(double value)
{
	this->value = value;
	this->eqType = eOpType::CONST_EQ;
}

int CConstEq::getValue(double &aValue)
{
	aValue = value;

	return OK_GENERAL;
}

void CConstEq::setValue(double value)
{
	this->value=value;
}