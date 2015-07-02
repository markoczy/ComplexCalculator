#pragma once

#include "CC_Common.h"
#include "CFcnChainEq.h"

class CFcnACotEq : public CFcnChainEq
{
public:

	CFcnACotEq()
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
		// acot(x)=atan(1/x)
		return atan(1 / ops.at(0).value->getValue());
	}


};