#pragma once

#include <vector>
#include "CVarEq.h"
#include "CChainEq.h"

class CFcnChainEq : public CChainEq
{

public:

	CFcnChainEq();

	virtual void addOperation(CAbstractEq* value, eOpType oper) ;

	virtual void addParam(std::string name);

	/// @returns count of set items
	virtual int setParam(std::string name, double value); // -> private
	
	virtual bool isEqSolvable();

	virtual bool validateParams(std::vector<CVarEq> &params);

protected:

	// The input params (e.g: x,y)
	std::vector<CVarEq> params;
	
	// The param fields of the function
	// are stored in an array for quick access
	std::vector<CVarEq*> paramFields;

	// The child operation chains
	// are stored in an array for quick access
	std::vector<CFcnChainEq*> fcnFields;
	
	bool solvable = false;

};