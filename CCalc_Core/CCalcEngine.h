#include "CEqParserV2.h"
#include "CFunctionsPool.h"
#include "CFcnParser.h"

#include "StringTools.h"



class CCalcEngine
{
	
public:
	CCalcEngine();
	~CCalcEngine();
	
	int parse(std::string equation, double &aValue);
	
	int parseEquation(std::string equation, double &aValue);
	
	int parseFunction(std::string equation);


	int validate(std::string equation);

	std::string parseReturnCode(int code);
	

private:
	CEqParserV2	mParser;
	CFcnParser mFcnParser;
	CFunctionsPool mFunctions;

	int _parse(std::string &equation, double &aValue);
	int _parseEquation(std::string &equation, double &value, bool validate = true);
	int _parseFunction(std::string &equation, bool validate = true);

	int _validate(std::string &equation);

	bool _isFcnDefEq(std::string eq);

};