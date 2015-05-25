#include "CC_Common.h"



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

bool cc::fcn::initFunctions(std::vector<CParsedFcnEq*> &functions)
{
	CParsedFcnEq* eq;
	
	//// Exponential
	//
	// exp
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.EXP);
		
		CFcnExpEq* fcn = new CFcnExpEq(new CVarEq(X), new CVarEq(Y));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);
		eq->addParam(Y);

		functions.push_back(eq);
	}
	//
	// log
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.LOG);

		CFcnLogEq* fcn = new CFcnLogEq(new CVarEq(X), new CVarEq(Y));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);
		eq->addParam(Y);

		functions.push_back(eq);
	}

	//// Trigonometry
	//
	// sin
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.SIN);

		CFcnSinEq* fcn = new CFcnSinEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);
	
		functions.push_back(eq);
	}
	//
	// asin
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.ASIN);

		CFcnASinEq* fcn = new CFcnASinEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// cos
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.COS);

		CFcnCosEq* fcn = new CFcnCosEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// acos
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.ACOS);

		CFcnACosEq* fcn = new CFcnACosEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// tan
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.TAN);

		CFcnTanEq* fcn = new CFcnTanEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// atan
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.ATAN);

		CFcnATanEq* fcn = new CFcnATanEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// cot
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.COT);

		CFcnCotEq* fcn = new CFcnCotEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// acot
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.ACOT);

		CFcnACotEq* fcn = new CFcnACotEq(new CVarEq(X));

		eq->addOperation((CAbstractEq*)fcn, eOpType::CONST_EQ);
		eq->addParam(X);

		functions.push_back(eq);
	}
	//
	// pi
	if (true)
	{
		eq = new CParsedFcnEq(fcnNames.PI);

		CAbstractFcnEq* fcn = new CAbstractFcnEq();
		eq->addOperation(new CConstEq(3.14159265359), eOpType::CONST_EQ);

		functions.push_back(eq);
	}

	return true;
}
