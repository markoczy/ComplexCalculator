#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnSinEq : public CAbstractFcnEq
{
public:

	CFcnSinEq(CAbstractEq* value)
	{
		this->values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return sin(values.at(0)->getValue());
	}

};