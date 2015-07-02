#pragma once

#include "CC_Common.h"

class CInvEq : public CAbstractEq
{
public:
	CInvEq(CAbstractEq* value);
	virtual double getValue();

private:
	CAbstractEq* value;
};