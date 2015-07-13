#include "CParsedFcnEqV2.h"

// Since name is vital, name is in Constr.
CParsedFcnEqV2::CParsedFcnEqV2(std::string name)
{
	this->mName = name;
}

void CParsedFcnEqV2::init(CChainEq_FCN* chain, std::vector<std::string> paramNames)
{
	this->mChain = chain;
	this->mParamNames = paramNames;

	// TODO: Lambda
	mParamCount = mParamNames.size();
}


std::string CParsedFcnEqV2::getName()
{
	return mName;
}


int CParsedFcnEqV2::getParamCount()
{
	return mParamCount;
}

double CParsedFcnEqV2::getValue(std::vector<double> paramValues)
{
	// Params must mach and not lambda
	if (mParamCount != -1 && paramValues.size() != mParamCount)
	{
		EROUT("Value count does not match: required = "<<mParamCount<<", provided = "<<paramValues.size());
		return 0;
	}

	for (unsigned int i = 0; i < paramValues.size(); i++)
	{
		mChain->setParam(mParamNames.at(i), paramValues.at(i));
	}

	// TODO: Error Check!!!

	return mChain->getValue();
}

