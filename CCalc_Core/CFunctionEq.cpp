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


double CFunctionEq::getValue()
{
	// failsave
	if (fcnReference == NULL) return 0;
	
	DBOUT("values.size() = " << values.size());
	
	std::vector<double> tVals;

	for (unsigned int i = 0; i < values.size(); i++)
	{
		tVals.push_back(values.at(i)->getValue());
	}

	return fcnReference->getValue(tVals);

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
