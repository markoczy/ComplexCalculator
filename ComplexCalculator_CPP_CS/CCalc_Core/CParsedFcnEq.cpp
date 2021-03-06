//#include "CParsedFcnEq.h"
//
//
//CParsedFcnEq::CParsedFcnEq(std::string name)
//{
//	this->fcnName = name;
//}
//
//bool CParsedFcnEq::addParam(std::string name)
//{
//	// Check if param alrdy exists
//	for (unsigned int i = 0; i < params.size(); i++)
//	{
//		if (!params.at(i).getName().compare(name))
//		{
//			return false;
//		}
//	}
//
//	// Create param
//	CVarEq param(name);
//	params.push_back(param);
//
//	return true;
//}
//
//
//
//bool CParsedFcnEq::setParamValues(std::vector<double> values)
//{
//	// Check input size
//	if (values.size() != params.size())
//	{
//		return false;
//	}
//	
//	// Copy Values
//	for (unsigned int i = 0; i < params.size(); i++)
//	{
//		setParamValueAt(i, values.at(i));
//	}
//
//	return true;
//
//}
//
//bool CParsedFcnEq::setParamValueAt(int it,double value)
//{
//	if ((unsigned)it>params.size())
//	{
//		return false;
//	}
//	
//	params.at(it).setValue(value);
//
//	return true;
//}
//
//bool CParsedFcnEq::validate()
//{
//	return false;// fcnEquation.validateParams(params);
//}
//
//void CParsedFcnEq::addOperation(CAbstractEq* value, eOpType oper)
//{
//	return;// fcnEquation.addOperation(value, oper);
//}
//
//std::string CParsedFcnEq::getName()
//{
//	return this->fcnName;
//}
//
//int CParsedFcnEq::getParamCount()
//{
//	return this->params.size();
//}
//
//// @override
//double CParsedFcnEq::getValue()
//{
//	// Admitted that validation is made.. otherwise BOOM!
//	for (unsigned int i = 0; i < params.size(); i++)
//	{
//		// Must test...
//		fcnEquation.setParam(params.at(i).getName(), params.at(i).getValue());
//	}
//
//	return fcnEquation.getValue();
//}
//


