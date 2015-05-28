#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnLogEq : public CFcnChainEq
{
public:

	CFcnLogEq(CAbstractEq* value, CAbstractEq* base)
	{
		SOperation lValue;
		lValue.value = value;
		lValue.conOp = eOpType::CONST_EQ;
		ops.push_back(lValue);

		SOperation lBase;
		lBase.value = base;
		lBase.conOp = eOpType::CONST_EQ;
		ops.push_back(lBase);

		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return std::log(ops.at(0).value->getValue()) / std::log(ops.at(1).value->getValue());
	}


};