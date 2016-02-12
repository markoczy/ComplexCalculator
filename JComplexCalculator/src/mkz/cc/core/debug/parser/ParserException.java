/**
 * File: JComplexCalculator::ParserException.java
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
package mkz.cc.core.debug.parser;

import mkz.cc.core.debug.CCalcException;

/**
 * The Class ParserException. Exceptions related to parsing.
 */
public class ParserException extends CCalcException
{

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Instantiates a new parser exception.
	 */
	public ParserException()
	{
		super();
	}
	
	/**
	 * Instantiates a new parser exception.
	 *
	 * @param aMessage the reference message
	 */
	public ParserException(String aMessage)
	{
		super(aMessage);
	}
}
