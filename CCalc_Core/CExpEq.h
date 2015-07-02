#pragma once

#include "CC_Common.h"

class CExpEq : public CAbstractEq
{
public:
	CExpEq(CAbstractEq* value1, CAbstractEq* value2);
	
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};