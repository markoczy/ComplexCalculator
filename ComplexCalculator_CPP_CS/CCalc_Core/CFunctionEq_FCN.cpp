#include "CFunctionEq_FCN.h"

int CFunctionEq_FCN::setParam(std::string name, double value)
{
	int varCount = 0;

	//std::string name = params.at(it).getName();

	DBOUT("Setting param " << name.c_str() << ", value = " << value);

	for (unsigned int i = 0; i < values.size(); i++)
	{
		CAbstractEq* eq = values.at(i);

		// Assign variables of this equation (horizontal)
		if (eq->getEqType() == eOpType::VAR_EQ)
		{
			DBOUT("Found CVar");

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
			CChainEq_FCN* chain = (CChainEq_FCN*)eq;

			// Set the value
			varCount += chain->setParam(name, value);
		}
		// Assign variables of child equations (recursive)
		else if (eq->getEqType() == eOpType::FCN_EQ)
		{
			CFunctionEq_FCN* chain = (CFunctionEq_FCN*)eq;

			// Set the value
			varCount += chain->setParam(name, value);
		}

	}

	return varCount;
}
