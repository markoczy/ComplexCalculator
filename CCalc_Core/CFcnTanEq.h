#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnTanEq : public CAbstractFcnEq
{
public:

	CFcnTanEq(CAbstractEq* value)
	{
		this->values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return tan(values.at(0)->getValue());
	}

};