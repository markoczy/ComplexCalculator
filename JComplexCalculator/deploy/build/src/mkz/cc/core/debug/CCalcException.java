/**
 * File: JComplexCalculator::CCalcException.java
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
package mkz.cc.core.debug;

/**
 * The Class CCalcException. All Exceptions related to the Complex Calculator are 
 * subtypes of this class.
 */
public class CCalcException extends Exception
{
	
	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Instantiates a new c calc exception.
	 */
	public CCalcException()
	{
		super();
	}
	
	/**
	 * Instantiates a new c calc exception.
	 *
	 * @param aMessage the reference message
	 */
	public CCalcException(String aMessage)
	{
		super(aMessage);
	}
}
