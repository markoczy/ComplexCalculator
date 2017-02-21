/**
 * File: JComplexCalculator::ParamEquation.java
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
package mkz.cc.core.equation.function;

import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.core.equation.definition.IParamEquation;

/**
 * The Class ParamEquation.
 *
 * @param <T> the generic type
 */
public class ParamEquation<T> extends Equation<T> implements IParamEquation<T>
{
//	private IParametrizable<T> dummy=(s,e)->{};
	
	/**
	 * Instantiates a new param equation.
	 *
	 * @param aDisplayName the reference display name
	 * @param aFunction the reference function
	 */
	public ParamEquation(String aDisplayName, IFunction<T> aFunction)
	{
		super(aDisplayName, aFunction);
	}

	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.function.IParametrizable#setParam(java.lang.String, mkz.cc.core.equation.IEquation)
	 */
	@Override
	public void setParam(String aName, IEquation<T> aValue)
	{
		for(IEquation<T> iEq:_getParams())
		{
			if(iEq instanceof IParamEquation) ((IParamEquation<T>) iEq).setParam(aName, aValue);
		}
	}

}
