#include "CC_Function.h"



/// XXX unfinished!!!

void cc::fcn::removeParam(std::string &stmt, std::string paramName)
{
	int len = stmt.size();

	bool lastWasAlpha = false;

	for (int i = 0; i < len; i++)
	{
		if (stmt.at(i) == paramName.at(0))
		{

		}

	}
}

bool cc::fcn::initFunctions(std::vector<CParsedFcnEqV2*> &functions)
{
	CParsedFcnEqV2* eq;
	std::vector<std::string> paramNames;
	//CChainEq_FCN* chn;
	
	//// Exponential
	//
	// exp
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.EXP);
		
		CFcnExpEq* fcn = new CFcnExpEq();

		paramNames = { "X", "Y" };
		eq->init(fcn,paramNames);

		functions.push_back(eq);
	}
	//
	// log
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.LOG);

		CFcnLogEq* fcn = new CFcnLogEq();

		paramNames = { "X", "Y" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}

	//// Trigonometry
	//
	// sin
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.SIN);

		CFcnSinEq* fcn = new CFcnSinEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// asin
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ASIN);
		
		CFcnASinEq* fcn = new CFcnASinEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// cos
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.COS);

		CFcnCosEq* fcn = new CFcnCosEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// acos
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ACOS);
		
		CFcnACosEq* fcn = new CFcnACosEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// tan
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.TAN);
		
		CFcnTanEq* fcn = new CFcnTanEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// atan
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ATAN);
		
		CFcnATanEq* fcn = new CFcnATanEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// cot
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.COT);
		
		CFcnCotEq* fcn = new CFcnCotEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// acot
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ACOT);
		
		CFcnACotEq* fcn = new CFcnACotEq();

		paramNames = { "X" };
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// pi
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.PI);

		CChainEq_FCN* fcn = new CChainEq_FCN();
		
		fcn->addOperation(new CConstEq(3.14159265359),eOpType::CONST_EQ);

		paramNames = {};
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}
	//
	// e
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.E);

		CChainEq_FCN* fcn = new CChainEq_FCN();

		fcn->addOperation(new CConstEq(2.71828182845), eOpType::CONST_EQ);
		                               
		paramNames = {};
		eq->init(fcn, paramNames);

		functions.push_back(eq);
	}

	return true;
}
