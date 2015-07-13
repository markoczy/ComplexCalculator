#pragma once

#include "CC_Common.h"
#include "CChainEq_FCN.h"

class CFcnCotEq : public CChainEq_FCN
{
public:

	CFcnCotEq()
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
		// cot(x) = cos(x)/sin(x)
		double val = ops.at(0).value->getValue();

		return cos(val) / sin(val);
	}


};