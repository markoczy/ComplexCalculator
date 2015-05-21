#include "CExpEq.h"

CExpEq::CExpEq(CAbstractEq* value1, CAbstractEq* value2)
{
	this->value1 = value1;
	this->value2 = value2;
	this->eqType = eOpType::EXP_EQ;
}

double CExpEq::getValue()
{
	return pow(value1->getValue(),value2->getValue());
}