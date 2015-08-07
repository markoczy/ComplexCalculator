#pragma once

#include <string>
#include <sstream>

namespace cc
{
	namespace err
	{
		
		bool isSuccess(int code);
		std::string getReturnString(int code);
	}

}

//struct SReturn
//{
//	int mRetCode;
//	std::string mObject = NULL;
//	int mIt = 0;
//
//	void setCode(int retCode, std::string object = NULL, int it = 0)
//	{
//		mRetCode = retCode;
//		mObject = object;
//		mIt = it;
//	}
//};

enum eRetCode
{
	///////////////////////////////////////////////////
	//// Happy Cases: 0 <= x < 100
	///////////////////////////////////////////////////
	//
	OK_GENERAL = 0,
	//
	OK_PARSED_EQUATION = 1,
	//
	OK_CREATED_FUNCTION = 2,

	///////////////////////////////////////////////////
	//// Software Errors
	///////////////////////////////////////////////////
	//
	NOK_BAD_INIT = 110,
	//
	NOK_VAR_UNSET = 111,
	//
	NOK_PARAMCOUNT_LOW = 112,
	//
	NOK_PARAMCOUNT_HIGH = 113,
	//
	NOK_FCNREF_UNSET = 114,



	///////////////////////////////////////////////////
	//// Parsing Errors: 1000 <= x < 2000
	///////////////////////////////////////////////////
	//
	//
	/////////////////////////////////
	// General: 1100 <= x < 1200 
	/////////////////////////////////
	//
	NOK_BAD_CHAR = 1000,
	//
	NOK_CLOSED_PARANTHESIS = 1001,
	//
	NOK_OPENED_PARANTHESIS = 1002,
	//
	/////////////////////////////////
	// Equation: 1100 <= x < 1200 
	/////////////////////////////////
	//
	NOK_EQ_FCNNAME_NOTFOUND = 1100,
	//
	NOK_EQ_FCNPARAMCOUNT_LOW = 1101,
	//
	NOK_EQ_FCNPARAMCOUNT_HIGH = 1102,
	//
	/////////////////////////////////
	// Function: 1200 <= x < 1300 
	/////////////////////////////////
	//
	NOK_FCN_NAME_EXISTS = 1200,
	//
	NOK_FCN_PARAMCOUNT_LOW = 1201,
	//
	NOK_FCN_PARAMCOUNT_HIGH = 1202,




};