#include "CDivEq.h"

CDivEq::CDivEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::DIV_EQ;
}

double CDivEq::getValue()
{
	return value1->getValue() / value2->getValue();
}