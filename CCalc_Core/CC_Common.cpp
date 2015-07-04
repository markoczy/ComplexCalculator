#include "CC_Common.h"


/////////////////////////// NAMESPACE: "cc" ///////////////////////////////////
//
bool cc::isDecimal(char chr)
{
	for (int i = 0; i < DECIMALS_COUNT; i++)
	{
		if (chr == DECIMALS[i]) return true;
	}

	return false;
}
//
bool cc::isAlpha(char chr)
{
	for (int i = 0; i < ALPHAS_COUNT; i++)
	{
		if (chr == ALPHAS[i]) return true;
	}
	
	return false;
}
//
bool cc::isOperator(char chr)
{
	for (int i = 0; i < OPS_COUNT; i++)
	{
		if (chr == OPS[i]) return true;
	}

	return false;
}
//
bool cc::isParOpen(char chr)
{
	return chr == '(';
}
//
bool cc::isParClose(char chr)
{
	return chr == ')';
}
//
bool cc::isFcnDefOp(char chr1, char chr2)
{
	if (chr1 == ':')
	{
		return chr2 == '=';
	}

	return false;
}
//
bool cc::validateChar(char chr)
{
	for (int i = 0; i < DECIMALS_COUNT; i++)
	{
		if (chr == DECIMALS[i])
		{
			return true;
		}
	}

	for (int i = 0; i < OPS_COUNT; i++)
	{
		if (chr == OPS[i])
		{
			return true;
		}
	}

	for (int i = 0; i < ALPHAS_COUNT; i++)
	{
		if (chr == ALPHAS[i])
		{
			return true;
		}
	}

	if (chr == ')' || chr == '(')
	{
		return true;
	}

	return false;
}
//
eOpType cc::parseOperator(char chr)
{
	switch (chr)
	{
	case '+':
		return eOpType::ADD_EQ;
		break;
	case '-':
		return eOpType::SUB_EQ;
		break;
	case '/':
		return eOpType::DIV_EQ;
		break;
	case '*':
		return eOpType::MPL_EQ;
		break;
	case '^':
		return eOpType::EXP_EQ;
		break;
	default:
		return eOpType::NULL_EQ;
	}
}

int cc::parseParanthesis(char chr)
{
	if (cc::isParOpen(chr))
	{
		return 1;
	}
	else if (cc::isParClose(chr))
	{
		return -1;
	}

	return 0;
}

