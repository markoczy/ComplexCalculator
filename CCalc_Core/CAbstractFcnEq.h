#pragma once

#include "CAbstractEq.h"
#include "CConstEq.h"
#include "CVarEq.h"

class CAbstractFcnEq : public CAbstractEq
{
	
public:

	// Overload is for costants
	CAbstractFcnEq();

	virtual bool setParamValue(std::string name, double value);

protected:

	std::vector<CAbstractEq*> values;
};