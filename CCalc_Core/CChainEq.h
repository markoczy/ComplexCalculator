#pragma once

#include "CC_Common.h"
#include "CC_Operation.h"

// Operation:
// 0 dimensional (atomar) element of an 
// equation e.g. 2+
//
struct SOperation
{
	CAbstractEq* value;
	eOpType conOp;
};

// Chain Equation:
// 1 Dimensional equation e.g. 2+3/5
//
class CChainEq : public CAbstractEq
{
public:
	CChainEq();
	//~CChainEq(){ clear(); }

	CChainEq(std::vector<CAbstractEq*> values, std::vector<eOpType> operators);
	CChainEq(std::vector<SOperation> ops);
	
	virtual int getValue(double &aValue);

	virtual void clear();

	virtual void addOperation(CAbstractEq* value, eOpType oper);

protected:
	std::vector<SOperation> ops;

	// Recursive refereence to ops array (as parsed)
	// Needed to call clear()
	CAbstractEq * parsedOp = NULL;

	static bool _solveOp(std::vector<SOperation> &vec, int it);
	static int _getCountOf(std::vector<SOperation> &vec, eOpType op);
	static int _getFirstOf(std::vector<SOperation> &vec, eOpType op);
};