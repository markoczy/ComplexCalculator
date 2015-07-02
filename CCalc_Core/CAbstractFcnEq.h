#pragma once

#include "CC_Common.h"
#include "CVarEq.h"
#include "CFunctionsPool.h"
//
//
class CAbstractFcnEq : public CAbstractEq
{
	
public:

	// Overload is for costants
	CAbstractFcnEq();

	// Initialize: call getFcnByName
	virtual bool init(CFunctionsPool * aPool, std::string name);

	virtual bool addParamValue(CAbstractEq * value);
	
	virtual double getValue();

protected:

	std::vector<CAbstractEq*> values;

	CParsedFcnEqV2 * fcnReference;

	int mParamCount = 0;

};