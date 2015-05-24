#pragma once

#include "CParsedFcnEq.h"
#include "CC_Common.h"

#include <vector>



class CFunctionsPool
{
public:

	CFunctionsPool();

	// used to define function by a single string
	// accepts: f(x,y):=sin(x)+0.3y
	bool defineFunction(std::string statement);

	bool loadFunctionsDb(std::string path);

	CParsedFcnEq* getFunctionByName(std::string name);


private:

	// functions array
	std::vector<CParsedFcnEq*> functions;

	// Init built-in functions
	bool _initFunctions();


	//// Parser utility
	//
	// f(x,y):=sin(x)+0.3y
	//
	// Validation
	static bool _validateStmt(std::string &stmt);
	// static bool _advancedValidation(fcnName, paramNames);
	//
	// TODO:	advancedValidation()
	//			If params removed: 
	//			Do all strings match to existing functions?
	//			(Dependency Check)
	//
	// 
	static int _getDefOpIt(std::string &stmt);
	//
	// Function name
	static std::string _getFcnName(std::string &stmt, int defOpIt);
	//
	// Equation string
	static std::string _getFcnEquation(std::string &stmt, int defOpIt);
	//
	// Param names
	static std::vector<std::string> _getFcnParamNames(std::string &stmt, int defOpIt);
	
};