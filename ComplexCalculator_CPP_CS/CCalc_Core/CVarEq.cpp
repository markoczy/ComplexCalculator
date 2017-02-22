#include "CVarEq.h"


CVarEq::CVarEq(std::string name)
{
	this->name = name;
	this->eqType = eOpType::VAR_EQ;
}

std::string CVarEq::getName()
{
	return this->name;
}

void CVarEq::setValue(double val)
{
	this->value = val;
	valExists = true;
}

bool CVarEq::hasValue()
{
	return valExists;
}

// @override
int CVarEq::getValue(double &aValue)
{
	if (valExists)
	{
		aValue = value;
		return OK_GENERAL;
	}
	else
	{
		return NOK_VAR_UNSET;
	}
}