/**
 * File: JComplexCalculator::ParamLinearArithmeticEquation.java
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
package mkz.cc.arithmetic.equation;

import java.util.ArrayList;

import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IParamEquation;
import mkz.cc.util.IO;

/**
 * The Class ParamLinearArithmeticEquation. An extended version of the class LinearEquation that implements IParametrizable.
 * The method setParam() sets all params of the equation recursively.
 */
public class ParamLinearArithmeticEquation extends LinearArithmeticEquation implements IParamEquation<Double>
{
	/** The member params. */
	private ArrayList<IParamEquation<Double>> mParams = new ArrayList<IParamEquation<Double>>();
	
	/**
	 * Sets the param.
	 *
	 * @param aName the reference name
	 * @param aValue the reference value
	 * @see mkz.cc.core.equation.definition.IParametrizable#setParam(java.lang.String, mkz.cc.core.equation.definition.IEquation)
	 */
	@Override
	public void setParam(String aName, IEquation<Double> aValue)
	{
		for(IParamEquation<Double> iParam:mParams) iParam.setParam(aName, aValue);
	}
	
	/**
	 * Adds the operation.
	 *
	 * @param aEquation the reference equation
	 * @param aOperation the reference operation
	 * @see mkz.cc.arithmetic.equation.LinearArithmeticEquation#addOperation(mkz.cc.core.equation.definition.IEquation, mkz.cc.core.equation.Operation)
	 */
	@Override
	public void addOperation(IEquation<Double> aEquation, Operation aOperation)
	{
		super.addOperation(aEquation, aOperation);
		if(aEquation instanceof IParamEquation) 
		{
			mParams.add((IParamEquation<Double>)aEquation);
			IO.SysOutV("Found param equation. params size now: "+mParams.size());
		}
	}
	
}
