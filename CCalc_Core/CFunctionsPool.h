#pragma once

#include "CFcnChainEq.h"

#include <vector>

// TODO: delete logic

class CFunctionsPool
{
public:
	bool parseFunctionString(std::string function);
	bool loadFunctionsDb(std::string path);

private:

	// Init built-in functions
	void _initFunctions();

	std::vector<CFcnChainEq*> functions;



};