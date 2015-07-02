#pragma once

#include "CC_Common.h"

class CAddEq : public CAbstractEq
{
public:
	CAddEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};