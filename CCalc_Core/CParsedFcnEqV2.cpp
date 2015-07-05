#include "CParsedFcnEqV2.h"

// Since name is vital, name is in Constr.
CParsedFcnEqV2::CParsedFcnEqV2(std::string name)
{
	this->mName = name;
}

void CParsedFcnEqV2::init(CFcnChainEq* chain)
{
	this->mChain = chain;

	mParamCount = chain->getParamCount();
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
		return 0;
	}

	for (unsigned int i = 0; i < paramValues.size(); i++)
	{
		mChain->setParam(i, paramValues.at(i));
	}

	// TODO: Error Check!!!

	return mChain->getValue();
}

