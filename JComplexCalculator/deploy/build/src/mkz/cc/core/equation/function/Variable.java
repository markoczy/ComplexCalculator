/**
 * File: JComplexCalculator::Variable.java
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

import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IParamEquation;

/**
 * The Class Variable. A Parametrizable constant.
 *
 * @param <T> the generic type
 */
public class Variable<T> implements IParamEquation<T>
{
	
	/** The member name. */
	private String mName = null;

	/** The member value. */
	private IEquation<T> mValue = null;

	/**
	 * Instantiates a new variable.
	 *
	 * @param aName the reference name
	 */
	public Variable(String aName)
	{
		mName = aName;
	}

	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.function.IParametrizable#setParam(java.lang.String, mkz.cc.core.equation.IEquation)
	 */
	@Override
	public void setParam(String aName, IEquation<T> aValue)
	{
		if (mName != null && mName.equals(aName))
		{
			mValue = aValue;
		}
	}

	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.IEquation#getValue()
	 */
	@Override
	public T getValue() throws CCalcException // TODO exception
	{
		return mValue != null ? mValue.getValue() : null;
	}

}
