#pragma once

#include "CC_Common.h"
#include "CChainEq_FCN.h"


class CFcnLogEq : public CChainEq_FCN
{
public:

	CFcnLogEq()
	{
		CVarEq * value = new CVarEq("X");
		CVarEq * base = new CVarEq("Y");

		SOperation lValue;
		lValue.value = value;
		lValue.conOp = eOpType::CONST_EQ;
		ops.push_back(lValue);

		SOperation lBase;
		lBase.value = base;
		lBase.conOp = eOpType::CONST_EQ;
		ops.push_back(lBase);

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

		aValue = std::log(v1) / std::log(v2);

		return OK_GENERAL;
	}


};