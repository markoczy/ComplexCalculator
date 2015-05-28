#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnACotEq : public CFcnChainEq
{
public:

	CFcnACotEq(CAbstractEq* value)
	{
		SOperation op;
		op.value = value;
		op.conOp = eOpType::CONST_EQ;
		ops.push_back(op);

		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		// acot(x)=atan(1/x)
		return atan(1 / ops.at(0).value->getValue());
	}


};