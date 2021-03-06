#pragma once

#include "CParsedFcnEqv2.h"
#include "CC_Common.h"
#include "CC_Function.h"

//#include <vector>



class CFunctionsPool
{
public:

	CFunctionsPool();

	// used to define function by a single string
	// accepts: f(x,y):=sin(x)+0.3y
	bool addFunction(CParsedFcnEqV2* fcn);

	bool deleteFunctionByName(std::string name);

	bool loadFunctionsDb(std::string path);

	CParsedFcnEqV2* getFunctionByName(std::string name);


private:

	// functions array
	std::vector<CParsedFcnEqV2*> functions;

	// Init built-in functions
	bool _initFunctions();


	//// Parser utility ===> CFcnParser
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