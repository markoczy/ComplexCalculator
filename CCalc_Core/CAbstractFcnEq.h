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
	
	virtual int getParamCount();

	virtual double getValue();

	virtual void clear();

protected:

	std::vector<CAbstractEq*> values;

	CParsedFcnEqV2 * fcnReference = NULL;

	int mParamCount = 0;

};