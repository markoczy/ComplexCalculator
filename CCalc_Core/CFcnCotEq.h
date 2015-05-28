#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnCotEq : public CFcnChainEq
{
public:

	CFcnCotEq(CAbstractEq* value)
	{
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