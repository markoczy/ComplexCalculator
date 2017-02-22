#pragma once

#include "CC_Common.h"
#include "CChainEq_FCN.h"


class CFcnACosEq : public CChainEq_FCN
{
public:

	CFcnACosEq()
	{
		CVarEq * value = new CVarEq("X");

		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);
		
		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual int getValue(double &aValue)
	{
		int rVal = 0;
		double v1 = 0;

		// Get first value, exit on error
		rVal = ops.at(0).value->getValue(v1);
		if (!cc::err::isSuccess(rVal)) return rVal;

		aValue = acos(v1);

		return OK_GENERAL;
	}

private:

};