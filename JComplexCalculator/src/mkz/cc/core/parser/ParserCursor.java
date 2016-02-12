/**
 * File: JComplexCalculator::ParserCursor.java
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
package mkz.cc.core.parser;

/**
 * The Class ParserCursor.
 */
public class ParserCursor
{
	
	/** The member position. */
	private Integer mPosition;

	/**
	 * Instantiates a new parser cursor.
	 */
	public ParserCursor()
	{
		mPosition = 0;
	}

	/**
	 * Instantiates a new parser cursor.
	 *
	 * @param aCursor the reference cursor
	 */
	public ParserCursor(ParserCursor aCursor)
	{
		mPosition = aCursor.getPosition();
	}
	
	public ParserCursor(int aPosition)
	{
		mPosition = aPosition;
	}

	/**
	 * Previous.
	 */
	public void previous()
	{
		mPosition--;
	}

	/**
	 * Next.
	 */
	public void next()
	{
		mPosition++;
	}

	/**
	 * Gets the position.
	 *
	 * @return the position
	 */
	public Integer getPosition()
	{
		return mPosition;
	}

	/**
	 * Sets the position.
	 *
	 * @param aIterator the new position
	 */
	public void setPosition(Integer aIterator)
	{
		mPosition = aIterator;
	}

	/**
	 * Returns if the cursor exceeds the current String.
	 *
	 * @param aEquation the reference equation
	 * @return true, if successful
	 */
	public boolean exceeds(String aEquation)
	{
		return mPosition >= aEquation.length();
	}

	/**
	 * Gets the current char from equation.
	 *
	 * @param aEquation the reference equation
	 * @return the char
	 */
	public char get(String aEquation)
	{
		return !exceeds(aEquation) ? aEquation.charAt(mPosition) : '\0';
	}

	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	public String toString()
	{
		return "" + mPosition;
	}
}
