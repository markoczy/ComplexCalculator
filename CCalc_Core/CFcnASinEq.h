#pragma once

#include "CC_Common.h"
#include "CChainEq_FCN.h"

class CFcnASinEq : public CChainEq_FCN
{
public:

	CFcnASinEq()
	{
		CVarEq * value = new CVarEq("X");

		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return asin(ops.at(0).value->getValue());
	}


};