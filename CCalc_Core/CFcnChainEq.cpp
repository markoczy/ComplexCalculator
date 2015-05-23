#include "CFcnChainEq.h"

CFcnChainEq::CFcnChainEq()
{
	this->eqType = eOpType::FCN_CH_EQ;
}

void CFcnChainEq::addOperation(CAbstractEq* value, eOpType oper)
{
	// Superclass method call
	this->CChainEq::addOperation(value, oper);
	
	// Add var to pool
	if (value->getEqType()==eOpType::VAR_EQ)
	{
		paramFields.push_back((CVarEq*)value);
	}
	// Add fcnChain to pool
	if (value->getEqType() == eOpType::FCN_CH_EQ)
	{
		fcnFields.push_back((CFcnChainEq*)value);
	}

}

void CFcnChainEq::addParam(std::string name)
{
	CVarEq p(name);
	params.push_back(p);
}


int CFcnChainEq::setParam(std::string name, double value)
{
	int varCount=0;

	for (unsigned int i = 0; i < ops.size(); i++)
	{
		CAbstractEq* eq = ops.at(i).value;

		// Assign variables of this equation (horizontal)
		if (eq->getEqType()==eOpType::VAR_EQ)
		{
			// Set the value
			CVarEq* var = (CVarEq*)eq;
			if (!var->getName().compare(name))
			{
				var->setValue(value);
				varCount++;
			}
			
		}
		// Assign variables of child equations (recursive)
		else if (eq->getEqType() == eOpType::FCN_CH_EQ)
		{
			// Set the values
			CFcnChainEq* chain = (CFcnChainEq*)eq;
			varCount += chain->setParam(name, value);
		}

	}

	return varCount;

}

bool CFcnChainEq::isEqSolvable()
{
	bool rVal=true;

	for (unsigned int i = 0; i < ops.size(); i++)
	{
		CAbstractEq* eq = ops.at(i).value;

		// Check variables of this equation (horizontal)
		if (eq->getEqType() == eOpType::VAR_EQ)
		{
			// Set the value
			CVarEq* var = (CVarEq*)eq;
			
			rVal &= var->hasValue();

		}
		// Check variables of child equations (recursive)
		else if (eq->getEqType() == eOpType::FCN_CH_EQ)
		{
			// Set the values
			CFcnChainEq* chain = (CFcnChainEq*)eq;
			rVal &= chain->isEqSolvable();
		}

	}

	return rVal;

}


bool CFcnChainEq::validateParams(std::vector<CVarEq> &params)
{
	bool rVal = true;

	////// Part 1: Validate Local
	for (unsigned int iPField = 0; iPField < paramFields.size();iPField++)
	{
		bool hasValue = false;

		// Get name of param field
		std::string fieldName = paramFields.at(iPField)->getName();

		for (unsigned int iSetPrm = 0; iSetPrm < params.size(); iSetPrm++)
		{
			std::string paramName = params.at(iSetPrm).getName();

			if (!fieldName.compare(paramName))
			{
				hasValue = true;
			}
		
		}

		rVal &= hasValue;

		// lazy exit
		if (!rVal) return false;

	}


	////// Part 2: Validate Recursive
	for (unsigned int iFcnField = 0; iFcnField < fcnFields.size(); iFcnField++)
	{
		// Validate child(s)
		rVal &= fcnFields.at(iFcnField)->validateParams(params);

		// lazy exit
		if (!rVal) return false;
	}

	return true;
}