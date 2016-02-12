/**
 * File: JComplexCalculator::Operation.java
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

/**
 * The Class Operation.
 */
public class Operation implements Comparable<Operation>
{
	
	/** The Constant FCN. */
	public static final Operation FCN = new Operation(Equation.DisplayNames.FCN,0);
	
	/** The Constant EXP. */
	public static final Operation EXP = new Operation(Equation.DisplayNames.EXP,2);

	/** The Constant DIV. */
	public static final Operation DIV = new Operation(Equation.DisplayNames.DIV,100);
	
	/** The Constant MPL. */
	public static final Operation MPL = new Operation(Equation.DisplayNames.MPL,101);
	
	/** The Constant SUB. */
	public static final Operation SUB = new Operation(Equation.DisplayNames.SUB,102);
	
	/** The Constant ADD. */
	public static final Operation ADD = new Operation(Equation.DisplayNames.ADD,103);

	/** The Constant CONST. */
	public static final Operation CONST = new Operation(Equation.DisplayNames.CONST,1000);
	
	/** The Constant UNDEF. */
	public static final Operation UNDEF = new Operation(Equation.DisplayNames.UNDEF,1001);
	
	///
	/// Implementation
	///
	
	/** The member name. */
	private String mName;
	
	/** The member priority. */
	private Integer mPriority;
	
	/**
	 * Instantiates a new operation.
	 *
	 * @param aName the reference name
	 * @param aPriority the reference priority
	 */
	private Operation(String aName,int aPriority)
	{
		mName=aName;
		mPriority=aPriority;
	}

	/* (non-Javadoc)
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(Operation aOperation)
	{
		return mPriority.compareTo(aOperation.mPriority);
	}
	
	/* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString()
	{
		return mName;
	}
	
}
