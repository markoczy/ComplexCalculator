#include "CFcnChainEq.h"

void CFcnChainEq::addOperation(CAbstractEq* value, eOpType oper)
{
	// Superclass method call
	this->CChainEq::addOperation(value, oper);
	
	// Add var to pool
	if (value->getEqType()==eOpType::VAR_EQ)
	{
		vars.push_back((CVarEq*)value);
	}

}

int CFcnChainEq::setVar(std::string name, double value)
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
			varCount += chain->setVar(name, value);
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
