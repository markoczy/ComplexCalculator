#include "CC_Error.h"

bool cc::err::isSuccess(int code)
{
	return code < 100 && 0 <= code;
}


std::string cc::err::getReturnString(int code)
{
	////////////////////////////////////////////////////
	// Definition of error codes:                     //
	//                                                //
	// ["NOK"|"OK"]#[ACTION|"GE"]::[ERROR_TXT|OK_TXT] //
	////////////////////////////////////////////////////
	
	switch (code)
	{
	
	//// OK

	case eRetCode::OK_GENERAL:
		return "OK#GE::GENERAL";
	
	case eRetCode::OK_PARSED_EQUATION:
		return "OK#GE::PARSED_EQUATION";

	case eRetCode::OK_CREATED_FUNCTION:
		return "OK#GE::CREATED_FUNCTION";

	//// NOK : General

	case eRetCode::NOK_BAD_CHAR:
		return "NOK#GE::BAD_CHAR";
	
	case eRetCode::NOK_CLOSED_PARANTHESIS:
		return "NOK#GE::CLOSED_PARANTHESIS";

	case eRetCode::NOK_OPENED_PARANTHESIS:
		return "NOK#GE::OPENED_PARANTHESIS";

	//// NOK : Equation Parser

	case eRetCode::NOK_EQ_FCNNAME_NOTFOUND:
		return "NOK#EQ::NAME_NOTFOUND";

	case eRetCode::NOK_EQ_FCNPARAMCOUNT_LOW:
		return "NOK#EQ::PARAMCOUNT_LOW";

	case eRetCode::NOK_EQ_FCNPARAMCOUNT_HIGH:
		return "NOK#EQ::PARAMCOUNT_HIGH";

	//// NOK : Function Parser

	case eRetCode::NOK_FCN_NAME_EXISTS:
		return "NOK#FCN::NAME_EXISTS";

	case eRetCode::NOK_FCN_PARAMCOUNT_LOW:
		return "NOK#FCN::PARAMCOUNT_LOW";

	case eRetCode::NOK_FCN_PARAMCOUNT_HIGH:
		return "NOK#FCN::PARAMCOUNT_HIGH";

	default:
		std::stringstream ss;
		ss << "UNDEF#" << code;
		return ss.str();

	}

}