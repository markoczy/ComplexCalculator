#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnExpEq : public CFcnChainEq
{
public:

	CFcnExpEq(CAbstractEq* base, CAbstractEq* exp)
	{
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
	
	virtual double getValue()
	{
		return pow(ops.at(0).value->getValue(), ops.at(1).value->getValue());
	}

};