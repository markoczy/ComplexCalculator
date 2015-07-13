#include "CEqParserV2.h"

class CFcnParser : public CEqParserV2
{
public:

	CParsedFcnEqV2 parse(std::string equation);



	// override parseEquation

protected:

	// Members
	std::vector<std::string> mParamNames;

	////
	//
	virtual std::vector<std::string> _parseFcnParamNames(std::string &equation, int &it);
	//
	virtual bool _parseDefineOperator(std::string &equation, int & it);
	//
	// overridden parseEquation
	virtual CChainEq_FCN* _parseEquation(std::string &equation, int &it);
	//
	// Checks if identifier is a param name
	virtual bool isFcnParam(std::string id);

	//CAbstractFcn* CFcnParser::_parseFunction(std::string &equation, int &it);

};