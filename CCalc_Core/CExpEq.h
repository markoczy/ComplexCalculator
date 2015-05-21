#pragma once

#include "CAbstractEq.h"

class CExpEq : public CAbstractEq
{
public:
	CExpEq(CAbstractEq* value1, CAbstractEq* value2);
	
	virtual double getValue();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};