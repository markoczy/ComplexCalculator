/**
 * File: JComplexCalculator::ALinearEquation.java
 * 
 * Copyright (C) 2016  Aleistar Markóczy
 * 
 * This file is part of JComplexCalculator.
 *
 * JComplexCalculator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * JComplexCalculator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with JComplexCalculator.  If not, see <http://www.gnu.org/licenses/>.
 */
package mkz.cc.core.equation.linear;

import java.util.ArrayList;

import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.util.io.IO;

/**
 * The Class ALinearEquation.
 *
 * @param <T> the generic type
 */
public abstract class ALinearEquation<T> implements IEquation<T>
{

	/** The member valid ops. */
	Operation[] mValidOps=null;
	
	/** The member operations. */
	private ArrayList<LinearOperation<T>> mOperations = new ArrayList<LinearOperation<T>>();
	
	
	/**
	 * Instantiates a new a linear equation.
	 * ATTENTION: Operation table must be in right order
	 *
	 * @param aOpsTable the reference ops table
	 */
	public ALinearEquation(Operation[] aOpsTable)
	{
		mValidOps=aOpsTable;
	}
	
	/**
	 * Adds the operation.
	 *
	 * @param aEquation the reference equation
	 * @param aOperation the reference operation
	 */
	public void addOperation(IEquation<T> aEquation, Operation aOperation)
	{
		mOperations.add(new LinearOperation<T>(aEquation, aOperation));
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.definition.IEquation#getValue()
	 */
	@Override
	public T getValue() throws CCalcException
	{
		int lPos=0;
		
		for(Operation iOp:mValidOps)
		{
			while((lPos=_getFirstOf(iOp))!=-1)
			{
				IO.dbOutV("Solving "+iOp);
				_solveOp(lPos);
			}
		}
		
		if(mOperations.size()>1) IO.dbOutE("Operations size too big: "+mOperations.size());
		return mOperations.get(0).getEquation().getValue();
	}
	
	/**
	 * [resrticted] get first of.
	 *
	 * @param aOperation the reference operation
	 * @return the int
	 */
	protected int _getFirstOf(Operation aOperation)
	{
		for(int i = 0;i<mOperations.size();i++)
		{
			if(mOperations.get(i).getOperation().equals(aOperation)) return i;
		}
		
		return -1;
	}
	
	/**
	 * [resrticted] solve op.
	 *
	 * @param index the index
	 * @return true, if successful
	 */
	protected boolean _solveOp(int index)
	{
		if(mOperations.size()-1<index)
		{
			IO.dbOutE("Wrong index, is "+index+", should be >"+(mOperations.size()-1));
		}
		
		// get current linear operation
		LinearOperation<T> lLinOp1=mOperations.get(index);
		LinearOperation<T> lLinOp2=mOperations.get(index+1);
		
		// create the new equation (2 + 4 => eq(2,4,ADD))
		Equation<T> lEquation=_getEquation(lLinOp1.getOperation());
		if(lEquation==null) IO.dbOutE("Equation is null!");
		lEquation.addParam(lLinOp1.getEquation());
		lEquation.addParam(lLinOp2.getEquation());
		
		// create new linear operation element ( 2+4-.. -> (2+4)- )
		LinearOperation<T> lNewOp = new LinearOperation<T>(lEquation,lLinOp2.getOperation());
		mOperations.set(index, lNewOp);
		mOperations.remove(index+1);
		
		return true;
	}
	
	
	/**
	 * [resrticted] get equation.
	 *
	 * @return the equation
	 */
	protected abstract Equation<T> _getEquation(Operation aOperation);

	
}
