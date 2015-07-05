#include "CAddEq.h"

CAddEq::CAddEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::ADD_EQ;
}

double CAddEq::getValue()
{
	double rVal = value1->getValue() + value2->getValue();
	return value1->getValue() + value2->getValue();
}

void CAddEq::clear()
{
	DBOUT("Try Clear");
	cc::clearEquation(value1);
	cc::clearEquation(value2);
	DBOUT("Clear OK");
}