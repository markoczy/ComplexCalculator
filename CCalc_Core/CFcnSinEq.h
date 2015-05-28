#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnSinEq : public CFcnChainEq
{
public:

	CFcnSinEq(CAbstractEq* value)
	{
		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return sin(ops.at(0).value->getValue());
	}

};