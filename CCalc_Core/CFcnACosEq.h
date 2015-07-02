#pragma once

#include "CC_Common.h"
#include "CFcnChainEq.h"


class CFcnACosEq : public CFcnChainEq
{
public:

	CFcnACosEq()
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
		return acos(ops.at(0).value->getValue());
	}

private:

};