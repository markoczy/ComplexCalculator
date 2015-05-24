#pragma once

#include "CAbstractEq.h"
#include "CVarEq.h"

class CAbstractFcnEq : public CAbstractEq
{
	
public:
	CAbstractFcnEq();

	virtual bool setParamValue(std::string name, double value);

protected:

	std::vector<CAbstractEq*> values;

};