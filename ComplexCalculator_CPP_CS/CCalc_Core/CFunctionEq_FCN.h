#pragma once

#include "CFunctionEq.h"

class CFunctionEq_FCN : public CFunctionEq, public CAbstractFcn
{
public:
	int setParam(std::string name, double value);

};