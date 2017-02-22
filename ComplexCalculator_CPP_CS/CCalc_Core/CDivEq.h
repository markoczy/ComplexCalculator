#pragma once

#include "CC_Common.h"

class CDivEq : public CAbstractEq
{
public:
	CDivEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual int getValue(double &aValue);

	virtual void clear();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};