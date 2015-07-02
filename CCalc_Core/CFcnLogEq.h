#pragma once

#include "CC_Common.h"
#include "CFcnChainEq.h"


class CFcnLogEq : public CFcnChainEq
{
public:

	

	CFcnLogEq()
	{
		CVarEq * value = new CVarEq("X");
		CVarEq * base = new CVarEq("Y");

		SOperation lValue;
		lValue.value = value;
		lValue.conOp = eOpType::CONST_EQ;
		ops.push_back(lValue);

		SOperation lBase;
		lBase.value = base;
		lBase.conOp = eOpType::CONST_EQ;
		ops.push_back(lBase);

		this->addParam(value->getName());
		this->addParam(base->getName());
		this->eqType = eOpType::FCN_CH_EQ;
	}

	virtual double getValue()
	{
		return std::log(ops.at(0).value->getValue()) / std::log(ops.at(1).value->getValue());
	}


};