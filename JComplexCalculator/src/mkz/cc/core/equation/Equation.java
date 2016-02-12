/**
 * File: JComplexCalculator::Equation.java
 * 
 * Copyright (C) 2016  Aleistar Mark�czy
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

import java.util.ArrayList;

import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.util.IO;

/**
 * The Class Equation. Holds a function implementation and an array of call
 * parameters. Implements the IEquation interface that provides the equation's
 * value (solution) if all params are set accordingly.
 *
 * @param <T> the generic type
 */
public class Equation<T> implements IEquation<T>
{

	/** The member display name. */
	protected String mDisplayName;

	/** The member function. */
	protected IFunction<T> mFunction;

	/** The member equations. */
	protected ArrayList<IEquation<T>> mParams;

	/**
	 * Instantiates a new a equation.
	 *
	 * @param aDisplayName the reference display name
	 * @param aFunction the reference function
	 */
	public Equation(String aDisplayName, IFunction<T> aFunction)
	{
		mFunction = aFunction;
		mDisplayName = aDisplayName;
	}

	/**
	 * Sets the params.
	 *
	 * @param aParams the new params
	 */
	public void setParams(ArrayList<IEquation<T>> aParams)
	{
		mParams = aParams;
	}

	/**
	 * Adds the param.
	 *
	 * @param aParam the reference param
	 * @return the equation
	 */
	public Equation<T> addParam(IEquation<T> aParam)
	{
		_getParams().add(aParam);
		return this;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see mkz.cc.core.equation.IEquation#getValue()
	 */
	public T getValue()
	{
		try
		{
			return mFunction.getValue(_getParams());
		}
		catch (Exception e)
		{
			IO.SysOutE(e);
			return null;
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString()
	{
		return mDisplayName;
	}

	/**
	 * [restricted] get params. failsafe for NPE..
	 *
	 * @return the array list
	 */
	protected ArrayList<IEquation<T>> _getParams()
	{
		return mParams == null ? mParams = new ArrayList<IEquation<T>>() : mParams;
	}

	/**
	 * The Class DisplayNames.
	 */
	public static class DisplayNames
	{

		/** The Constant UNDEF. null equivalent */
		public static final String UNDEF = "<<UNDEFINED>>";

		//
		// unary
		//

		/** The Constant CONST. */
		public static final String CONST = "Constant";

		/** The Constant INV. */
		public static final String INV = "Inversed";

		//
		// binary, basic
		//

		/** The Constant ADD. */
		public static final String ADD = "Addition";

		/** The Constant SUB. */
		public static final String SUB = "Subtraction";

		/** The Constant MPL. */
		public static final String MPL = "Multiplication";

		/** The Constant DIV. */
		public static final String DIV = "Division";

		//
		// function
		//

		/** The Constant FCN. */
		public static final String FCN = "Undefined function";

		/** The Constant SUM. */
		public static final String SUM = "Sum(i=0 -> n)";

		/** The Constant EXP. */
		public static final String EXP = "Exponential";

		/** The Constant LOG. */
		public static final String LOG = "Logarithm";

		/** The Constant SIN. */
		public static final String SIN = "Sinus";

		/** The Constant COS. */
		public static final String COS = "Cosinus";

		/** The Constant TAN. */
		public static final String TAN = "Tangens";

		/** The Constant COT. */
		public static final String COT = "Cotangens";

		/** The Constant ASIN. */
		public static final String ASIN = "Arcus sinus";

		/** The Constant ACOS. */
		public static final String ACOS = "Arcus cosinus";

		/** The Constant ATAN. */
		public static final String ATAN = "Arcus tangens";

		/** The Constant ACOT. */
		public static final String ACOT = "Arcus cotangens";

		/** The Constant LINEAR. */
		public static final String LINEAR = "Linear Function";
		
		/** The Constant PI. */
		public static final String PI = "Constant 'pi'";
	}

}
