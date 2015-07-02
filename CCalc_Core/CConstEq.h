#pragma once

#include "CC_Common.h"

class CConstEq : public CAbstractEq
{
public:
	CConstEq(double value);
	virtual double getValue();
	virtual void setValue(double value);

private:
	double value;
};