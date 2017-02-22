#include "CChainEq_FCN.h"

CChainEq_FCN::CChainEq_FCN()
{
	this->eqType = eOpType::FCN_CH_EQ;
}

void CChainEq_FCN::addOperation(CAbstractEq* value, eOpType oper)
{
	// Superclass method call
	this->CChainEq::addOperation(value, oper);
	
	// Add var to pool
	if (value->getEqType()==eOpType::VAR_EQ)
	{
		paramFields.push_back((CVarEq*)value);
	}
	// Add fcnChain to pool
	else if (value->getEqType() == eOpType::FCN_CH_EQ)
	{
		fcnChnFields.push_back((CChainEq_FCN*)value);
	}
	// Add Function to pool
	/*else if (value->getEqType() == eOpType::FCN_EQ)
	{
		fcnFields.push_back((CChainEq_FCN*)value);
	}*/
}

//void CChainEq_FCN::addParam(std::string name)
//{
//	CVarEq p(name);
//	params.push_back(p);
//
//	// Recursive
//	for (unsigned int iOp = 0; iOp < ops.size();iOp++)
//	{
//		if (ops.at(iOp).value->getEqType() == eOpType::FCN_CH_EQ)
//		{
//			CChainEq_FCN* chain =(CChainEq_FCN*)ops.at(iOp).value;
//
//			chain->addParam(name);
//		}
//	
//	}
//}

//int CChainEq_FCN::getParamCount()
//{
//	if (isLambda)
//	{
//		return -1;
//	}
//	else
//	{
//		return params.size();
//	}
//}


/// XXX doubled effort! (get pointers, then use ops)
int CChainEq_FCN::setParam(std::string name, double value)
{
	int varCount=0;

	//std::string name = params.at(it).getName();

	DBOUT("Setting param " << name.c_str() <<", value = "<<value);

	for (unsigned int i = 0; i < ops.size(); i++)
	{
		CAbstractEq* eq = ops.at(i).value;

		// Assign variables of this equation (horizontal)
		if (eq->getEqType()==eOpType::VAR_EQ)
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
			//CAbstractFcn* func = (CAbstractFcn*)eq;
			CAbstractFcn* func = dynamic_cast<CAbstractFcn*>(eq);

			// Set the value
			DBOUT("FCN_CH_EQ : Try set param");
			varCount += func->setParam(name, value);
			DBOUT("FCN_CH_EQ : Params set");
		}
		else if (eq->getEqType() == eOpType::FCN_EQ)
		{
			//CAbstractFcn* func = (CAbstractFcn*)eq;
			CAbstractFcn* func = dynamic_cast<CAbstractFcn*>(eq);

			// Set the value
			DBOUT("FCN_EQ : Try set param");
			varCount += func->setParam(name, value);
			DBOUT("FCN_EQ : Params set");
		}

		// Assign variables of child equations (recursive)
		//else if (eq->getEqType() == eOpType::FCN_EQ)
		//{
		//	CFcnAbstractFcnEq* chain = (CFcnAbstractFcnEq*)eq;

		//	// Set the value
		//	varCount += chain->setParam(name, value);
		//}
		

	}

	return varCount;

}

bool CChainEq_FCN::isEqSolvable()
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
			CChainEq_FCN* chain = (CChainEq_FCN*)eq;
			rVal &= chain->isEqSolvable();
		}

	}

	return rVal;

}


bool CChainEq_FCN::validateParams(std::vector<CVarEq> &params)
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
	for (unsigned int iFcnField = 0; iFcnField < fcnChnFields.size(); iFcnField++)
	{
		// Validate child(s)
		rVal &= fcnChnFields.at(iFcnField)->validateParams(params);

		// lazy exit
		if (!rVal) return false;
	}

	return true;
}


int CChainEq_FCN::getParamIt(std::string name)
{
	for (unsigned int i = 0; i < params.size(); i++)
	{
		if (!params.at(i).getName().compare(name))
		{
			return i;
		}
	}

	return -1;

}
