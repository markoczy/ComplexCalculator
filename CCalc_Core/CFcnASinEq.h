#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnASinEq : public CAbstractFcnEq
{
public:

	CFcnASinEq(CAbstractEq* value)
	{
		this->values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return asin(values.at(0)->getValue());
	}


};