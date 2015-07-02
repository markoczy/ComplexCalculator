#pragma once
//

#include "CC_Common.h"
#include "CFcnChainEq.h"


class CFcnExpEq : public CFcnChainEq
{
public:

	CFcnExpEq()
	{
		CVarEq * base = new CVarEq("X");
		CVarEq * exp = new CVarEq("Y");

		SOperation lBase;
		lBase.value = base;
		lBase.conOp = eOpType::CONST_EQ;
		ops.push_back(lBase);

		SOperation lExp;
		lExp.value = exp;
		lExp.conOp = eOpType::CONST_EQ;
		ops.push_back(lExp);

		this->addParam(base->getName());
		this->addParam(exp->getName());

		this->eqType = eOpType::FCN_CH_EQ;
	}
	
	virtual double getValue()
	{
		return pow(ops.at(0).value->getValue(), ops.at(1).value->getValue());
	}

};