#pragma once

#include "CAbstractEq.h"

class CSubEq : public CAbstractEq
{
public:
	CSubEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};