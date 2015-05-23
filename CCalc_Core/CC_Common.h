#pragma once


#include "CAbstractEq.h"





/////////////////////////////// PARSER CHARS ///////////////////////////////

const char ALPHAS[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
						'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
						'u', 'v', 'w', 'x', 'y', 'z' };
const int ALPHAS_COUNT = 26;

const char DECIMALS[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };
const int DECIMALS_COUNT = 11;

const char OPS[] = { '+', '-', '*', '/', '^' };
const int OPS_COUNT = 5;

namespace cc
{
	bool isDecimal(char chr);
	bool isOperator(char chr);

	bool isParOpen(char chr);
	bool isParClose(char chr);

	bool validateChar(char chr);

	eOpType parseOperator(char chr);
}