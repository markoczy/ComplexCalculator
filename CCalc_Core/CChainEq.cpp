#include "CChainEq.h"

CChainEq::CChainEq()
{
	this->eqType = eOpType::CHAIN_EQ;
}


CChainEq::CChainEq(std::vector<CAbstractEq*> values, std::vector<eOpType> operators)
{
	for (unsigned int i = 0; i < values.size(); i++)
	{
		SOperation op;
		op.conOp = operators.at(i);
		op.value = values.at(i);
		ops.push_back(op);
	}
	this->eqType = eOpType::CHAIN_EQ;
}

CChainEq::CChainEq(std::vector<SOperation> ops)
{
	this->ops = ops;
	this->eqType = eOpType::CHAIN_EQ;
}

void CChainEq::addOperation(CAbstractEq* value, eOpType oper)
{
	SOperation op;
	op.conOp = oper;
	op.value = value;
	ops.push_back(op);
}

// XXX Not yet right: tmpOps(0) needed for recursive clear
void CChainEq::clear()
{
	DBOUT("Try Clear");
	cc::clearEquation(parsedOp);
	DBOUT("Clear OK");
}

int CChainEq::getValue(double &aValue)
{
	bool error = false;
	int eqCount = ops.size();

	std::vector<SOperation> tmpOps = ops;

	int first;

	// Exponentials
	//
	while ((first = _getFirstOf(tmpOps, eOpType::EXP_EQ)) != -1)
	{
		_solveOp(tmpOps, first);
	}

	// Divisions
	//
	while ((first = _getFirstOf(tmpOps, eOpType::DIV_EQ)) != -1)
	{
		_solveOp(tmpOps, first);
	}

	// Multiplications
	//
	while ((first = _getFirstOf(tmpOps, eOpType::MPL_EQ)) != -1)
	{
		_solveOp(tmpOps, first);
	}
	
	// Subtractions
	//
	while ((first = _getFirstOf(tmpOps, eOpType::SUB_EQ)) != -1)
	{
		_solveOp(tmpOps, first);
	}

	// Additions
	//
	while ((first = _getFirstOf(tmpOps, eOpType::ADD_EQ)) != -1)
	{
		_solveOp(tmpOps, first);
	}

	if (!tmpOps.at(0).value == NULL)
	{
		return tmpOps.at(0).value->getValue(aValue);
	}
	else
	{
		return NOK_BAD_INIT;
	}

}

bool CChainEq::_solveOp(std::vector<SOperation> &vec, int it)
{
	// Failsave
	//
	if ((unsigned)it >= vec.size())
	{
		return false;
	}

	// Parse Operator
	//
	eOpType op = vec.at(it).conOp;
	//
	if (op==eOpType::ADD_EQ)
	{
		vec.at(it).value = new CAddEq(vec.at(it).value, vec.at(it + 1).value);
	}
	else if (op == eOpType::SUB_EQ)
	{
		vec.at(it).value = new CSubEq(vec.at(it).value, vec.at(it + 1).value);
	}
	else if (op == eOpType::MPL_EQ)
	{
		vec.at(it).value = new CMplEq(vec.at(it).value, vec.at(it + 1).value);
	}
	else if (op == eOpType::DIV_EQ)
	{
		vec.at(it).value = new CDivEq(vec.at(it).value, vec.at(it + 1).value);
	}
	else if (op == eOpType::EXP_EQ)
	{
		vec.at(it).value = new CExpEq(vec.at(it).value, vec.at(it + 1).value);
	}
	else
	{
		return false;
	}

	// Merge Operator
	//
	vec.at(it).conOp = vec.at(it + 1).conOp;

	// Delete old value XXX: Not working!!!
	//
	//delete vec.at(it + 1).value;
	vec.erase(vec.begin() + it + 1);

	return true;
}


int CChainEq::_getCountOf(std::vector<SOperation> &vec, eOpType op)
{
	int count = 0;

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).conOp == op)
		{
			count++;
		}
	
	}

	return count;
}

int CChainEq::_getFirstOf(std::vector<SOperation> &vec, eOpType op)
{
	if (vec.size() < 1)
	{
		return -1;
	}

	int first = 0;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i).conOp == op)
		{
			return i;
		}

	}

	return -1;
}