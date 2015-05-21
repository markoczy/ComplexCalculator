#pragma once

#include "CAbstractEq.h"

class CAddEq : public CAbstractEq
{
public:
	CAddEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};