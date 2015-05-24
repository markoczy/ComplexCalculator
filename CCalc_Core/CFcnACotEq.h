#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnACotEq : public CAbstractFcnEq
{
public:

	CFcnACotEq(CAbstractEq* value)
	{
		values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		// acot(x)=atan(1/x)
		return atan(1 / values.at(0)->getValue());
	}


};