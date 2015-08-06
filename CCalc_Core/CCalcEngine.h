#include "CEqParserV2.h"
#include "CFunctionsPool.h"
#include "CFcnParser.h"

#include "StringTools.h"



class CCalcEngine
{
	
public:
	CCalcEngine();
	~CCalcEngine();
	
	int parse(std::string equation, double &value);
	
	int parseEquation(std::string equation, double &value);
	
	int parseFunction(std::string equation);


	int validate();

	std::string parseReturnCode(int code);
	

private:
	CEqParserV2	mParser;
	CFcnParser mFcnParser;
	CFunctionsPool mFunctions;

	int _parse(std::string &equation, bool validate = true);
	int _parseEquation(std::string &equation, double &value, bool validate = true);
	int _parseFunction(std::string &equation, bool validate = true);

	int _validate(std::string &equation);

	bool _isFcnDefEq(std::string eq);

};