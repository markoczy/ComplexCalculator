#pragma once
//

#include "CC_Common.h"
#include "CChainEq_FCN.h"


class CFcnExpEq : public CChainEq_FCN
{
public:

	CFcnExpEq()
	{
		CVarEq * base = new CVarEq("X");
		CVarEq * exp = new CVarEq("Y");

		SOperation lBase;
		lBase.value = base;
		lBase.conOp = eOpType::CONST_EQ;
		ops.push_back(lBase);

		SOperation lExp;
		lExp.value = exp;
		lExp.conOp = eOpType::CONST_EQ;
		ops.push_back(lExp);

		this->eqType = eOpType::FCN_CH_EQ;
	}
	
	virtual int getValue(double &aValue)
	{
		int rVal = 0;
		double v1 = 0, v2 = 0;

		// Get first value, exit on error
		rVal = ops.at(0).value->getValue(v1);
		if (!cc::err::isSuccess(rVal)) return rVal;

		// Get second value, exit on error
		rVal = ops.at(1).value->getValue(v2);
		if (!cc::err::isSuccess(rVal)) return rVal;

		aValue = pow(v1, v2);

		return OK_GENERAL;
	}

};