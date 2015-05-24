#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnLogEq : public CAbstractFcnEq
{
public:

	CFcnLogEq(CAbstractEq* value, CAbstractEq* base)
	{
		this->value = value;
		this->base = base;
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return std::log(value->getValue()) / std::log(base->getValue());
	}

private:
	CAbstractEq* value;
	CAbstractEq* base;
};