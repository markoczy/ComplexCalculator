#pragma once

#include "CChainEq_FCN.h"
#include "CChainEq.h"

class CParsedFcnEqV2
{

public:

	// Since name is vital, name is in Constr.
	CParsedFcnEqV2(std::string name);

	void init(CChainEq_FCN* chain, std::vector<std::string> paramNames);

	std::string getName();
	std::string getDescription();

	//// ParamCount:
	//
	// >0 = N Params
	// 0  = Const.
	// -1 = Lambda
	int getParamCount();

	double getValue(std::vector<double> paramValues);

private:

	CChainEq_FCN* mChain;
	std::string mName = "";

	std::string mDescripition = "";

	std::vector<std::string> mParamNames;

	int mParamCount = 0;

};