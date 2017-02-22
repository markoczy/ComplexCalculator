#pragma once

#include "CC_Common.h"
#include "CChainEq.h"
#include "CVarEq.h"


class CFcnChainEq : public CChainEq
{

public:

	CFcnChainEq();

	virtual void addOperation(CAbstractEq* value, eOpType oper) ;

	virtual void addParam(std::string name);

	//// ParamCount:
	//
	// >0 = N Params
	// 0  = Const.
	// -1 = Lambda
	virtual int getParamCount();


	/// @returns count of set items
	virtual int setParam(int it, double value); // -> private
	
	virtual bool isEqSolvable();

	virtual bool validateParams(std::vector<CVarEq> &params);

	// To know wether the param is used
	// And to set the param value by name
	//
	// returns -1 if unused
	virtual int getParamIt(std::string name);

protected:

	// The input params (e.g: x,y)
	std::vector<CVarEq> params;
	
	// The param fields of the function
	// are stored in an array for quick access
	std::vector<CVarEq*> paramFields;

	// The child operation chains
	// are stored in an array for quick access
	std::vector<CFcnChainEq*> fcnChnFields;

	// fcnFields
	//std::vector<CAbstractFcnEq*> fcnFields;

	////////////////////////////////////////////////////// TODO: Function superclass
	std::vector<CFcnChainEq*> fcnFields;

	void _setParamCount(int count);

	bool solvable = false;
	bool isLambda = false;
};