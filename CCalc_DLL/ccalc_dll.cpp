#include "ccalc_dll.h"


// Get Version
DLL int ccalc_getVersion(char* out)
{
	if (out == NULL)
	{
		return cc::getVersion().length();
	}
	else
	{
		std::string rVal = cc::getVersion();
		std::copy(rVal.begin(), rVal.end(), out);
		out[rVal.length()] = '\0';

		return rVal.length();
	}
}

// De / -Init
DLL CCalcEngine * ccalc_create()
{
	return new CCalcEngine();
}
//
DLL void ccalc_destroy(CCalcEngine * cc)
{
	delete cc;
}

// Use
DLL bool ccalc_validate(CCalcEngine * cc, char* stmt)
{
	DBOUT("Warning: untested method");
	bool rVal = cc->validate(stmt);
	DBOUT("Success");
	return rVal;
}

DLL int ccalc_parse(CCalcEngine * cc, char* stmt, double *aValue)
{
	return cc->parse(stmt, *aValue);
}

DLL int ccalc_getReturnString(int retCode, char* out)
{
	if (out == NULL)
	{
		return cc::err::getReturnString(retCode).length();
	}
	else
	{
		std::string rVal = cc::err::getReturnString(retCode);
		std::copy(rVal.begin(), rVal.end(), out);
		out[rVal.length()] = '\0';

		return rVal.length();
	}
}

DLL bool ccalc_isSuccess(int retCode)
{
	return cc::err::isSuccess(retCode);
}
