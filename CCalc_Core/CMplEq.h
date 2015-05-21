#pragma once

#include "CAbstractEq.h"

class CMplEq : public CAbstractEq
{
public:
	CMplEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};