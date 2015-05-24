#include "CAbstractFcnEq.h"

CAbstractFcnEq::CAbstractFcnEq()
{
	this->eqType = eOpType::FCN_EQ;
}


bool CAbstractFcnEq::setParamValue(std::string name, double value)
{
	// TODO: recursive
	for (unsigned int i = 0; i < values.size();i++)
	{
		eOpType type = values.at(i)->getEqType();

		if (type==eOpType::VAR_EQ)
		{
			CVarEq* var = (CVarEq*)values.at(i);
			
			if (!var->getName().compare(name))
			{
				var->setValue(value);
			}
		}
	}

	return true;
}
