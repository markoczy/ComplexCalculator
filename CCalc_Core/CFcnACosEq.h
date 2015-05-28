#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnACosEq : public CFcnChainEq
{
public:

	CFcnACosEq(CAbstractEq* value)
	{
		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return acos(ops.at(0).value->getValue());
	}

private:

};