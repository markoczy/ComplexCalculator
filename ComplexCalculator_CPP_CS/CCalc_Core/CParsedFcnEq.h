//#pragma once
////
//#include "CC_Common.h"
//#include "CFcnChainEq.h"
//
//class CParsedFcnEq
//{
//
//public:
//
//	CParsedFcnEq(std::string name);
//
//	// Add a new param
//	// returns if param really was added
//	// (not the case if alrdy exists)
//	virtual bool addParam(std::string name);
//
//	// Sets param values
//	virtual bool setParamValues(std::vector<double> values);
//	virtual bool setParamValueAt(int it, double value);
//	
//	// Validates function Expression
//	// returns if expression all params
//	// match with the expression
//	virtual bool validate();
//
//	// Add operation to member chain
//	virtual void addOperation(CAbstractEq* value, eOpType oper);
//	
//	virtual std::string getName();
//
//	// @override
//	virtual double getValue();
//
//	virtual int getParamCount();
//
//
//
//protected:
//	
//	CFcnChainEq* fcnEquation = new CFcnChainEq();
//
//	// The name of the fcn (e.g. f)
//	std::string fcnName;
//	
//	// The input params (e.g: x,y)
//	std::vector<CVarEq> params;
//
//	bool valid = false;
//	bool solvable = false;
//
//};