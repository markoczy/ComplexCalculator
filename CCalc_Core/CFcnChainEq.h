#pragma once

#include <vector>
#include "CVarEq.h"
#include "CChainEq.h"

class CFcnChainEq : public CChainEq
{

public:

	virtual void addOperation(CAbstractEq* value, eOpType oper) ;

	/// @returns count of set items
	virtual int setVar(std::string name, double value);
	
	virtual bool isEqSolvable();

protected:
	std::vector<CVarEq*> vars;

	bool solvable = false;

};