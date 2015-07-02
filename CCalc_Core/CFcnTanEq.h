#pragma once

#include "CC_Common.h"
#include "CFcnChainEq.h"

class CFcnTanEq : public CFcnChainEq
{
public:

	CFcnTanEq()
	{
		CVarEq * value = new CVarEq("X");

		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->addParam(value->getName());
		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return tan(ops.at(0).value->getValue());
	}

};