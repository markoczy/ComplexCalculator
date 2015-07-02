/// CC_Function.h
///
/// Header for functions 
///
#pragma once

#include "CC_Common.h"
//#include "CC_Equation.h"

#include "CVarEq.h"

//#include "CAbstractFcnEq.h"
#include "CParsedFcnEqV2.h"
//// Built-In Functions
//
#include "CFcnChainEq.h"
#include "CParsedFcnEq.h"
//
#include "CFcnExpEq.h"
#include "CFcnLogEq.h"
//
#include "CFcnCosEq.h"
#include "CFcnACosEq.h"
//
#include "CFcnCotEq.h"
#include "CFcnACotEq.h"
//
#include "CFcnSinEq.h"
#include "CFcnASinEq.h"
//
#include "CFcnTanEq.h"
#include "CFcnATanEq.h"


namespace cc
{
	namespace fcn
	{
		void removeParam(std::string &stmt, std::string paramName);

		bool initFunctions(std::vector<CParsedFcnEqV2*> &functions);
	}
}
//namespace cc
//{
//	namespace fcn
//	{
//		/// XXX unfinished!!!
//		void removeParam(std::string &stmt, std::string paramName);
//	}
//}