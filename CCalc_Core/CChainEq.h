#pragma once

#include "DBOUT.h"

#include "CAbstractEq.h"
#include "CConstEq.h"
#include "CAddEq.h"
#include "CSubEq.h"
#include "CMplEq.h"
#include "CDivEq.h"
#include "CExpEq.h"

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
	CChainEq::CChainEq(std::vector<SOperation> ops);
	
	virtual double getValue();
	virtual void addOperation(CAbstractEq* value, eOpType oper);
	virtual void clear();

private:
	std::vector<SOperation> ops;

	static bool _solveOp(std::vector<SOperation> &vec, int it);
	static int _getCountOf(std::vector<SOperation> &vec, eOpType op);
	static int _getFirstOf(std::vector<SOperation> &vec, eOpType op);
};