/**
 * File: JComplexCalculator::IFunction.java
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

import java.util.ArrayList;

import mkz.cc.core.debug.CCalcException;

/**
 * The Interface IFunction. The core element to define the functionality of an equation.
 *
 * @see mkz.cc.core.equation.Equation#Equation Equation(String, IFunction)
 * 
 * @param <T> the generic type
 */
@FunctionalInterface
public interface IFunction<T>
{
	
	/**
	 * Gets the value.
	 *
	 * @param aEqArr the reference equation array
	 * @return the value
	 * @throws CCalcException the complex calculator exception
	 */
	public T getValue(ArrayList<IEquation<T>> aEqArr) throws CCalcException;
}
