/**
 * File: JComplexCalculator::LinearOperation.java
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
package mkz.cc.core.equation.linear;

import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;

/**
 * The Class LinearOperation. Holds an equation and an Operation.
 *
 * @param <T> the generic type
 */
public class LinearOperation<T>
{
	
	/** The member operation. */
	private Operation mOperation = null;
	
	/** The member equation. */
	private IEquation<T> mEquation = null;
	
	/**
	 * Instantiates a new linear operation.
	 *
	 * @param aEquation the reference equation
	 * @param aOperation the reference operation
	 */
	public LinearOperation(IEquation<T> aEquation,Operation aOperation)
	{
		mEquation=aEquation;
		mOperation=aOperation;
	}

	/**
	 * Gets the operation.
	 *
	 * @return the operation
	 */
	public Operation getOperation()
	{
		return mOperation;
	}

	/**
	 * Sets the operation.
	 *
	 * @param aOperation the new operation
	 */
	public void setOperation(Operation aOperation)
	{
		mOperation = aOperation;
	}

	/**
	 * Gets the equation.
	 *
	 * @return the equation
	 */
	public IEquation<T> getEquation()
	{
		return mEquation;
	}


	/**
	 * Sets the equation.
	 *
	 * @param aEquation the new equation
	 */
	public void setEquation(Equation<T> aEquation)
	{
		mEquation = aEquation;
	}
	
}
