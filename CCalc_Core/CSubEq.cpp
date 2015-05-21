#include "CSubEq.h"

CSubEq::CSubEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::SUB_EQ;
}

double CSubEq::getValue()
{
	return value1->getValue() - value2->getValue();
}