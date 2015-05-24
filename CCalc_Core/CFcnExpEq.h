#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnExpEq : public CAbstractFcnEq
{
public:

	CFcnExpEq(CAbstractEq* base, CAbstractEq* exp)
	{
		values.push_back(base);
		values.push_back(exp);
		this->eqType = eOpType::FCN_EQ;
	}
	
	virtual double getValue()
	{
		return pow(values.at(0)->getValue(), values.at(1)->getValue());
	}

};