#include "CMplEq.h"

CMplEq::CMplEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::MPL_EQ;
}

double CMplEq::getValue()
{
	return value1->getValue() * value2->getValue();
}

void CMplEq::clear()
{
	DBOUT("Try Clear");
	cc::clearEquation(value1);
	cc::clearEquation(value2);
	DBOUT("Clear OK");
}