#include "CAddEq.h"

CAddEq::CAddEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::ADD_EQ;
}

double CAddEq::getValue()
{
	return value1->getValue() + value2->getValue();
}