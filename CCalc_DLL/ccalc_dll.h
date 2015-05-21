#include "CEqParser.h"

// DLLIMPORT / DLLEXPORT
#ifdef CCALC_DLL
#define DLL extern "C" __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
class SQLiteHandler;
#endif


// Get Version
DLL const char* ccalc_getVersion(char* out = NULL);

// De / -Init
DLL CEqParser * ccalc_create();
DLL void ccalc_destroy(CEqParser * parser);

// De / -Init
DLL bool ccalc_validate(CEqParser * parser,char* stmt);
DLL double ccalc_parse(CEqParser * parser,char* stmt);
