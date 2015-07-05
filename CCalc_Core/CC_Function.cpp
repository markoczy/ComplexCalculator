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
	//CFcnChainEq* chn;
	
	//// Exponential
	//
	// exp
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.EXP);
		
		CFcnExpEq* fcn = new CFcnExpEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// log
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.LOG);

		CFcnLogEq* fcn = new CFcnLogEq();

		eq->init(fcn);

		functions.push_back(eq);
	}

	//// Trigonometry
	//
	// sin
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.SIN);

		CFcnSinEq* fcn = new CFcnSinEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// asin
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ASIN);
		
		CFcnASinEq* fcn = new CFcnASinEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// cos
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.COS);

		CFcnCosEq* fcn = new CFcnCosEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// acos
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ACOS);
		
		CFcnACosEq* fcn = new CFcnACosEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// tan
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.TAN);
		
		CFcnTanEq* fcn = new CFcnTanEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// atan
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ATAN);
		
		CFcnATanEq* fcn = new CFcnATanEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// cot
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.COT);
		
		CFcnCotEq* fcn = new CFcnCotEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// acot
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.ACOT);
		
		CFcnACotEq* fcn = new CFcnACotEq();

		eq->init(fcn);

		functions.push_back(eq);
	}
	//
	// pi
	if (true)
	{
		eq = new CParsedFcnEqV2(fcnNames.PI);

		CFcnChainEq* fcn = new CFcnChainEq();
		
		fcn->addOperation(new CConstEq(3.14159265359),eOpType::CONST_EQ);

		eq->init(fcn);

		functions.push_back(eq);
	}

	return true;
}
