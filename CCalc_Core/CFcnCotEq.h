#pragma once

#include "CAbstractFcnEq.h"
#include "CAbstractEq.h"
#include "CExpEq.h"

class CFcnCotEq : public CAbstractFcnEq
{
public:

	CFcnCotEq(CAbstractEq* value)
	{
		this->values.push_back(value);
		this->eqType = eOpType::FCN_EQ;
	}

	virtual double getValue()
	{
		// cot(x) = cos(x)/sin(x)
		double val = values.at(0)->getValue();

		return cos(val) / sin(val);
	}


};