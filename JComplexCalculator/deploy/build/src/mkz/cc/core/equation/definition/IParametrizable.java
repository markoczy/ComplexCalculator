/**
 * File: JComplexCalculator::IParametrizable.java
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

/**
 * The Interface IParametrizable. A parametrizable (e.g. Variable or equation containing variable)
 * is an item that can holds one or several placeholders for generic {@link mkz.cc.core.equation.definition.IEquation equations}, 
 * the placeholders can be filled with equation elements by {@link mkz.cc.core.equation.definition.IParametrizable#setParam setParam}.
 *
 * @param <T> the generic type
 */
public interface IParametrizable<T>
{
	
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
