/**
 * File: JComplexCalculator::Constant.java
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
package mkz.cc.core.equation;

import mkz.cc.core.equation.definition.IEquation;

/**
 * The Class Constant. The bottom (leaf-) node in every equation, simply holds a constant double value.
 *
 * @param <T> the generic type
 */
public class Constant<T> implements IEquation<T>
{
	/** The member value. */
	T mValue;
	
	/**
	 * Instantiates a new constant.
	 *
	 * @param aValue the reference value
	 */
	public Constant(T aValue)
	{
		mValue=aValue;
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.core.equation.Equation#getValue()
	 */
	public T getValue()
	{
		return mValue;
	}

	/**
	 * Sets the value.
	 *
	 * @param aValue the new value
	 */
	public void setValue(T aValue)
	{
		mValue=aValue;
	}

}
