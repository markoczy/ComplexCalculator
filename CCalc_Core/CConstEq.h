#pragma once

#include "CAbstractEq.h"

class CConstEq : public CAbstractEq
{
public:
	CConstEq(double value);
	virtual double getValue();

private:
	double value;
};