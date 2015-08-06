#pragma once

#include "CC_Common.h"

class CSubEq : public CAbstractEq
{
public:
	CSubEq(CAbstractEq* value1, CAbstractEq* value2);
	virtual int getValue(double &aValue);
	
	virtual void clear();

private:
	CAbstractEq* value1;
	CAbstractEq* value2;
};