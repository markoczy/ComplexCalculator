#pragma once

#include "CC_Common.h"
#include "CFcnChainEq.h"

class CFcnCosEq : public CFcnChainEq
{
public:

	CFcnCosEq()
	{
		CVarEq * var = new CVarEq("X");

		SOperation op;
		op.value = var;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->addParam(var->getName());
		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return cos(ops.at(0).value->getValue());
	}

};