#pragma once

#include "CFcnChainEq.h"
#include "CChainEq.h"

class CParsedFcnEqV2
{

public:

	// Since name is vital, name is in Constr.
	CParsedFcnEqV2(std::string name);


	void init(CFcnChainEq* chain);


	std::string getName();

	//// ParamCount:
	//
	// >0 = N Params
	// 0  = Const.
	// -1 = Lambda
	int getParamCount();

	double getValue(std::vector<double> paramValues);


private:

	CFcnChainEq* mChain;
	std::string mName = "";
	std::vector<std::string> paramNames;

	int mParamCount=0;

};