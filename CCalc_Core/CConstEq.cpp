#include "CConstEq.h"

CConstEq::CConstEq(double value)
{
	this->value = value;
	this->eqType = eOpType::CONST_EQ;
}

double CConstEq::getValue()
{
	return this->value;
}