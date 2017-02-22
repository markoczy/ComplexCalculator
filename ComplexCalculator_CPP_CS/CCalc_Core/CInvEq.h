#pragma once

#include "CC_Common.h"

class CInvEq : public CAbstractEq
{
public:
	CInvEq(CAbstractEq* value);
	virtual int getValue(double &aValue);

private:
	CAbstractEq* value;
};