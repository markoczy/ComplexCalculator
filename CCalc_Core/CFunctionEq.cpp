#include "CFunctionEq.h"

CFunctionEq::CFunctionEq()
{
	this->eqType = eOpType::FCN_EQ;
}

bool CFunctionEq::init(CFunctionsPool * aPool, std::string name)
{
	fcnReference = aPool->getFunctionByName(name);
	
	if (fcnReference == NULL)
	{
		return false;
	}
	
	mParamCount = fcnReference->getParamCount();

	return true;
}


bool CFunctionEq::addParamValue(CAbstractEq * value)
{
	if (mParamCount!=-1 && (unsigned)mParamCount < values.size() + 1)
	{
		return false;
	}

	values.push_back(value);
	return true;
}

int CFunctionEq::getParamCount()
{
	return mParamCount;
}


int CFunctionEq::getValue(double &aValue)
{
	int rVal = 0;

	// failsave
	if (fcnReference == NULL) return NOK_FCNREF_UNSET;

	DBOUT("values.size() = " << values.size());
	
	std::vector<double> tVals;

	for (unsigned int i = 0; i < values.size(); i++)
	{
		double val = 0;

		// Get value, exit on error
		rVal = values.at(i)->getValue(val);
		if (!cc::err::isSuccess(rVal)) return rVal;

		tVals.push_back(val);
	}

	return fcnReference->getValue(tVals,aValue);

}

void CFunctionEq::clear()
{
	DBOUT("Try Clear");
	for (unsigned int i = 0; i < values.size(); i++)
	{
		cc::clearEquation(values.at(i));
	}

	values.resize(0);
	DBOUT("Clear OK");
}

int CFunctionEq::setParam(std::string name, double value)
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
			CFunctionEq* chain = (CFunctionEq*)eq;

			// Set the value
			varCount += chain->setParam(name, value);
		}

	}

	return varCount;
}


//
//
//bool CAbstractFcn::setParamValue(std::string name, double value)
//{
//	// TODO: recursive
//	for (unsigned int i = 0; i < values.size();i++)
//	{
//		eOpType type = values.at(i)->getEqType();
//
//		if (type==eOpType::VAR_EQ)
//		{
//			CVarEq* var = (CVarEq*)values.at(i);
//			
//			if (!var->getName().compare(name))
//			{
//				var->setValue(value);
//			}
//		}
//	}
//
//	return true;
//}
