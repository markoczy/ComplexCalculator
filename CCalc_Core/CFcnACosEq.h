#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnACosEq : public CAbstractFcnEq
{
public:

	CFcnACosEq(CAbstractEq* value)
	{
		this->values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		return acos(values.at(0)->getValue());
	}

private:

};