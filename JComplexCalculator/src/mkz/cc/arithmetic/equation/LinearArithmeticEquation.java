/**
 * File: JComplexCalculator::LinearArithmeticEquation.java
 * 
 * Copyright (C) 2016  Aleistar Mark�czy
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
package mkz.cc.arithmetic.equation;

import java.util.ArrayList;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.linear.LinearOperation;
import mkz.cc.util.IO;


/**
 * The Class LinearEquation. Implements an array of LinearOperation elements that is solved in a 
 * predefined order ("^" before "/" before "*" before "-" before "+")
 */
public class LinearArithmeticEquation implements IEquation<Double>
{
	
	/** The member operations. */
	private ArrayList<LinearOperation<Double>> mOperations = new ArrayList<LinearOperation<Double>>();
	
	/**
	 * Instantiates a new linear equation.
	 */
	public LinearArithmeticEquation()
	{
	}
	
	/**
	 * Adds the operation.
	 *
	 * @param aEquation the reference equation
	 * @param aOperation the reference operation
	 */
	public void addOperation(IEquation<Double> aEquation, Operation aOperation)
	{
		mOperations.add(new LinearOperation<Double>(aEquation, aOperation));
	}

	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.IEquation#getValue()
	 */
	@Override
	public Double getValue() throws CCalcException
	{
		int lPos=0;
		while((lPos=_getFirstOf(mOperations,Operation.EXP))!=-1)
		{
			IO.SysOutV("Solving "+Operation.EXP);
			_solveOp(mOperations,lPos);
		}
		
		while((lPos=_getFirstOf(mOperations,Operation.DIV))!=-1)
		{
			IO.SysOutV("Solving "+Operation.DIV);
			_solveOp(mOperations,lPos);
		}
		
		while((lPos=_getFirstOf(mOperations,Operation.MPL))!=-1)
		{
			IO.SysOutV("Solving "+Operation.MPL);
			_solveOp(mOperations,lPos);
		}
		
		while((lPos=_getFirstOf(mOperations,Operation.SUB))!=-1)
		{
			IO.SysOutV("Solving "+Operation.SUB);
			_solveOp(mOperations,lPos);
		}
		
		while((lPos=_getFirstOf(mOperations,Operation.ADD))!=-1)
		{
			IO.SysOutV("Solving "+Operation.ADD);
			_solveOp(mOperations,lPos);
		}
		
		
		if(mOperations.size()>1) IO.SysOutE("Operations size too big: "+mOperations.size());
		return mOperations.get(0).getEquation().getValue();
	}
	
	
	/**
	 * [restricted] get first of.
	 *
	 * @param aOpArr the reference op array
	 * @param aOperation the reference operation
	 * @return the int
	 */
	private static int _getFirstOf(ArrayList<LinearOperation<Double>> aOpArr,Operation aOperation)
	{
		for(int i = 0;i<aOpArr.size();i++)
		{
			if(aOpArr.get(i).getOperation().equals(aOperation)) return i;
		}
		
		return -1;
	}
	
	/**
	 * [restricted] solve op.
	 *
	 * @param aOpArr the reference op array
	 * @param index the index
	 * @return true, if successful
	 */
	private static boolean _solveOp(ArrayList<LinearOperation<Double>> aOpArr,int index)
	{
		if(aOpArr.size()-1<index)
		{
			IO.SysOutE("Wrong index, is "+index+", should be >"+(aOpArr.size()-1));
		}
		
		// get current linear operation
		LinearOperation<Double> lLinOp1=aOpArr.get(index);
		LinearOperation<Double> lLinOp2=aOpArr.get(index+1);
		
		// For hard debugging ;-)
//		try
//		{
//			if(lLinOp1.getEquation()==null) IO.SysOutW("First op is null");
//			else{IO.SysOutD("v1= "+lLinOp1.getEquation().getValue());}
//			
//			if(lLinOp2.getEquation()==null) IO.SysOutW("First op is null");
//			else{IO.SysOutD("v2= "+lLinOp2.getEquation().getValue());}
//		}
//		catch (Exception lE)
//		{
//		}
		
		
		// create the new equation (2 + 4 => eq(2,4,ADD))
		Equation<Double> lEquation=ArithmeticEquationFactory.createBasicEquation(lLinOp1.getOperation());
		lEquation.addParam(lLinOp1.getEquation());
		lEquation.addParam(lLinOp2.getEquation());
		
		// create new linear operation element ( 2+4-.. -> (2+4)- )
		LinearOperation<Double> lNewOp = new LinearOperation<Double>(lEquation,lLinOp2.getOperation());
		aOpArr.set(index, lNewOp);
		aOpArr.remove(index+1);
		
		return true;
	}
	
}
