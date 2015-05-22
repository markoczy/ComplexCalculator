#pragma once

#include "CAbstractEq.h"

class CVarEq : public CAbstractEq
{
public:
	CVarEq(std::string name);

	virtual std::string getName();

	virtual void setValue(double val);

	virtual bool hasValue();

	virtual double getValue();

protected:
	bool valExists = false;
	double value = 0;
	std::string name;
};