#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnCosEq : public CAbstractFcnEq
{
public:

	CFcnCosEq(CAbstractEq* value)
	{
		values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return cos(values.at(0)->getValue());
	}

};