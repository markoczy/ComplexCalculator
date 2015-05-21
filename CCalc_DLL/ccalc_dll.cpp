#include "ccalc_dll.h"


// Get Version
DLL const char* ccalc_getVersion(char* out)
{
	if (out == NULL)
	{
		return CC_VERSION;
	}
	else
	{
		strcpy_s(out, CC_VER_STRLEN, CC_VERSION);
	}

	return NULL;

}

// De / -Init
DLL CEqParser * ccalc_create()
{
	return new CEqParser();
}
//
DLL void ccalc_destroy(CEqParser * parser)
{
	delete parser;
}

// Use
DLL bool ccalc_validate(CEqParser * parser,char* stmt)
{
	DBOUT("Warning: untested method");
	bool rVal = parser->validate(stmt);
	DBOUT("Success");
	return rVal;
}

DLL double ccalc_parse(CEqParser * parser, char* stmt)
{
	DBOUT("Warning: untested method");
	double rVal = parser->parse(stmt);
	DBOUT("Success");
	return rVal;
}