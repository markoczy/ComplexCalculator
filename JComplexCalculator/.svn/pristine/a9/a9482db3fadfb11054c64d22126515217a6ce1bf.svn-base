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
public abstract class Operation implements Comparable<Operation>
{
	// TODO Subclasses of operation: Operation.Arithmetic etc
	
//	/////// Arithmetic
//	
//	/** The Constant FCN. */
//	public static final Operation FCN = new Operation(ConstantsArithmetic.DisplayNames.FCN,0);
//	
//	/** The Constant EXP. */
//	public static final Operation EXP = new Operation(ConstantsArithmetic.DisplayNames.EXP,2);
//
//	/** The Constant DIV. */
//	public static final Operation DIV = new Operation(ConstantsArithmetic.DisplayNames.DIV,100);
//	
//	/** The Constant MPL. */
//	public static final Operation MPL = new Operation(ConstantsArithmetic.DisplayNames.MPL,101);
//	
//	/** The Constant SUB. */
//	public static final Operation SUB = new Operation(ConstantsArithmetic.DisplayNames.SUB,102);
//	
//	/** The Constant ADD. */
//	public static final Operation ADD = new Operation(ConstantsArithmetic.DisplayNames.ADD,103);
//
//	/** The Constant CONST. */
//	public static final Operation CONST = new Operation(ConstantsArithmetic.DisplayNames.CONST,1000);
//	
//	/** The Constant UNDEF. */
//	public static final Operation UNDEF = new Operation(ConstantsArithmetic.DisplayNames.UNDEF,1001);
//	
//	/////// Logical
//	
//	/** The Constant AND. */
//	public static final Operation AND = new Operation(Equation.DisplayNames.AND,2);
//	
//	/** The Constant OR. */
//	public static final Operation OR = new Operation(Equation.DisplayNames.OR,3);
	
	// TODO more..
	
	
	///
	/// Implementation
	///
	
	/** The member name. */
	private String mName;
	
	/** The member position, also used as unique identifier of an operation. */
	private Integer mPosition;
	
	/**
	 * Instantiates a new operation.
	 *
	 * @param aName the reference name
	 * @param aPosition the reference position
	 */
	protected Operation(String aName,int aPosition)
	{
		mName=aName;
		mPosition=aPosition;
	}

	/* (non-Javadoc)
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	@Override
	public int compareTo(Operation aOperation)
	{
		return mPosition.compareTo(aOperation.mPosition);
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
