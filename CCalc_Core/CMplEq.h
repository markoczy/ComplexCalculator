#pragma once

#include "CC_Common.h"

class CMplEq : public CAbstractEq
{
public:
	CMplEq(CAbstractEq* value1, CAbstractEq* value2);
	
	virtual int getValue(double &aValue);

	virtual void clear();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};