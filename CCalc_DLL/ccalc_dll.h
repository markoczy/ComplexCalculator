#include "CCalcEngine.h"

// DLLIMPORT / DLLEXPORT
#ifdef CCALC_DLL
#define DLL extern "C" __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
class SQLiteHandler;
#endif


// Get Version
DLL int ccalc_getVersion(char* out = NULL);

// De / -Init
DLL CCalcEngine * ccalc_create();
DLL void ccalc_destroy(CCalcEngine * cc);

// Validate / Parse
DLL bool ccalc_validate(CCalcEngine * cc, char* stmt);
DLL int ccalc_parse(CCalcEngine * cc, char* stmt, double *aValue);

// Error
DLL bool ccalc_isSuccess(int retCode);
DLL int ccalc_getReturnString(int retCode, char* out = NULL);
