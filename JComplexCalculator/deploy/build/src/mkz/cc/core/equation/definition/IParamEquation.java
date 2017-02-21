/**
 * File: JComplexCalculator::IParamEquation.java
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
package mkz.cc.core.equation.definition;

import mkz.cc.core.debug.CCalcException;

/**
 * The Interface IParamEquation. Simply the combination of IEquation 
 * and IParametrizable
 * 
 * @see mkz.cc.core.equation.definition.IEquation IEquation
 * @see mkz.cc.core.equation.definition.IParametrizable IParametrizable
 *
 * @param <T> the generic type
 */
public interface IParamEquation<T> extends IEquation<T>, IParametrizable<T>
{
	/**
	 * Gets the value.
	 *
	 * @return the value
	 * @throws CCalcException the c calc exception
	 */
	public T getValue() throws CCalcException;
	
	/**
	 * Sets all params of the Parametrizable element by name.
	 *
	 * @see mkz.cc.core.equation.definition.IEquation IEquation
	 *
	 * @param aName the reference name
	 * @param aValue the reference value
	 */
	public void setParam(String aName, IEquation<T> aValue);
	
}
