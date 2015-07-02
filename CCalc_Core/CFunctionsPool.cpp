#include "CFunctionsPool.h"

CFunctionsPool::CFunctionsPool()
{
	if (_initFunctions())
	{
		DBOUT("Functions loaded");
	}
	else
	{
		EROUT("Could not load functions");
	}
}

// ===> CFcnParser
//bool CFunctionsPool::defineFunction(std::string stmt)
//{
//	// e.g. f(x):=23x
//	//		g(x,y):=(2y+3)x
//
//	// 1. Get Param Names
//
//	// 2. Create Chain
//
//	if (_validateStmt(stmt))
//	{
//		DBOUT("Validation successful");
//	}
//	else
//	{
//		EROUT("Validation not successful");
//	}
//
//	int defOpIt = _getDefOpIt(stmt);
//
//	std::string fcnName = _getFcnName(stmt, defOpIt);
//	std::vector<std::string> paramNames = _getFcnParamNames(stmt, defOpIt);
//	std::string equ = _getFcnEquation(stmt, defOpIt);
//
//	DBOUT("fcnName = " << fcnName.c_str());
//	DBOUT("fcnEquation = " << equ.c_str());
//	DBOUT("param Names size = " << paramNames.size());
//
//	// Create function and fill param names
//	//
//	CParsedFcnEqV2 eq(fcnName);
//	for (unsigned int i = 0; i < paramNames.size(); i++)
//	{
//		eq.addParam(paramNames.at(i));
//		DBOUT("param Name at " << i << " = " << paramNames.at(i).c_str());
//	}
//	
//	// TODO: parse equation
//
//	return true;
//}

CParsedFcnEqV2* CFunctionsPool::getFunctionByName(std::string name)
{
	int len = functions.size();

	for (int i = 0; i < len;i++)
	{
		if (!functions.at(i)->getName().compare(name))
		{
			DBOUT("Found matching function: "<<name.c_str());
			return functions.at(i);
		}
	}

	DBOUT("Not Found matching function: " << name.c_str());
	return NULL;
}



bool CFunctionsPool::_initFunctions()
{
	return cc::fcn::initFunctions(functions);
}



////////////////////////// PARSER //////////////////////////

bool CFunctionsPool::_validateStmt(std::string &stmt)
{
	// Stmt must be like: f(x,y):=sin(x)+0.3y
	//
	// 1. Check opened / closed params
	// 2. Check if ":=" exists

	// Locals
	//
	int parCount = 0;
	int defOpIt = 0;
	
	// Loop for Actions 1 and 2
	//
	for (unsigned int i = 0; i < stmt.length(); i++)
	{
		// Init
		//
		char chr = stmt.at(i);

		// Parantheses (1)
		//
		if (cc::isParOpen(chr))
		{
			parCount++;
		}
		//
		else if (cc::isParClose(chr))
		{
			parCount--;
		}

		// Define Operator (2)
		//
		else if (defOpIt==0 && i<stmt.length()-1)
		{
			char chr2 = stmt.at(i + 1);

			if (cc::isFcnDefOp(chr, chr2))
			{
				defOpIt = i;
			}
		}

	}

	return parCount==0;
}

int CFunctionsPool::_getDefOpIt(std::string &stmt)
{
	int len = stmt.length();
	
	for (int i = 0; i < len - 1; i++)
	{
		char chr = stmt.at(i);
		char chr2 = stmt.at(i + 1);

		if (cc::isFcnDefOp(chr, chr2))
		{
			return i;
		}
		
	}

	return -1;

}


std::string CFunctionsPool::_getFcnName(std::string &stmt, int defOpIt)
{
	std::string name="";

	// Length in scope
	int len = defOpIt + 1;

	for (int i = 0; i < len; i++)
	{
		char chr = stmt.at(i);

		if (cc::isParOpen(chr))
		{
			return name;
		}
		else
		{
			name.push_back(stmt.at(i));
		}
	}

	return name;
}

std::vector<std::string> CFunctionsPool::_getFcnParamNames(std::string &stmt, int defOpIt)
{
	//
	std::vector<std::string> pNames;

	// Length in scope
	int len = defOpIt;

	int parOpenIt = 0;
	int parCloseIt = defOpIt - 1;

	// 1. Verify if a constant
	//
	bool hasParam = false;
	//
	for (int i = 0; i < len; i++)
	{
		char chr = stmt.at(i);
		if (cc::isParOpen(chr))
		{
			parOpenIt = i;
			hasParam = true;
		}
	}
	//
	if (!hasParam)
	{
		return pNames;
	}

	// 2. Get Params
	//
	std::string pName="";
	//
	std::size_t begin = stmt.find_first_of('(')+1;
	std::size_t end = stmt.find_first_of(',');
	//
	while (end != std::string::npos && end < (unsigned)defOpIt)
	{
		pName = stmt.substr(begin, end-begin);
		begin = end + 2;
		end = stmt.find_first_of(',',begin);
		pNames.push_back(pName);
	}
	//
	// 
	begin--;
	end = stmt.find_first_of(')', begin);
	pName = stmt.substr(begin, end-begin);
	pNames.push_back(pName);

	return pNames;
}

std::string CFunctionsPool::_getFcnEquation(std::string &stmt, int defOpIt)
{
	return stmt.substr(defOpIt + 2, stmt.length() - (defOpIt + 2));
}