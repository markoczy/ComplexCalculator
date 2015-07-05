#include <iostream>

#ifdef _MYDBG_
#define DBOUT(a) std::cout<<"Debug."<<__FUNCTION__<<": "<<a<<std::endl
#else
#define DBOUT(a)
#endif

#define EROUT(a) std::cout<<"ERROR."<<__FUNCTION__<<": "<<a<<std::endl
