#include "CInvEq.h"

CInvEq::CInvEq(CAbstractEq* value)
{
	this->value = value;
	this->eqType = eOpType::INV_EQ;
}

double CInvEq::getValue()
{
	return -1.0*(this->value->getValue());
}
