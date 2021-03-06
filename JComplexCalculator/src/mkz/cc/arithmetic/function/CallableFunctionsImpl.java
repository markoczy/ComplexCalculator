/**
 * File: JComplexCalculator::CallableFunctionsImpl.java
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
package mkz.cc.arithmetic.function;

import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.core.debug.equation.InvalidParamCountException;
import mkz.cc.core.equation.definition.IFunction;

/**
 * The Class DefaultFunctions.
 */
public class CallableFunctionsImpl
{
	//
	// Chain
	//

	/** The Constant SUM. */
	public static final IFunction<Double> SUM = BasicFunctionsImpl.ADD;

	//
	// Exponential
	//

	/** The Constant EXP. */
	public static final IFunction<Double> EXP = BasicFunctionsImpl.EXP;
	
	/** The Constant LOG. */
	public static final IFunction<Double> LOG = (aArr) ->
	{
		// mode 1: log(x)
		//
		if (aArr.size() == 1) return Math.log(aArr.get(0).getValue());

		// mode 2: log(x,base)
		//
		else if (aArr.size() == 2)
		{
			double val = aArr.get(0).getValue();
			double base = aArr.get(1).getValue();
			return Math.log(val) / Math.log(base);
		}
		else throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.LOG, aArr.size());
	};

	//
	// Trigonometry
	//

	/** The Constant SIN. */
	public static final IFunction<Double> SIN = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.SIN, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.sin(rVal);
	};

	/** The Constant COS. */
	public static final IFunction<Double> COS = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.COS, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.cos(rVal);
	};

	/** The Constant TAN. */
	public static final IFunction<Double> TAN = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.TAN, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.tan(rVal);
	};

	/** The Constant COT. */
	public static final IFunction<Double> COT = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.COT, aArr.size());
		double rVal = aArr.get(0).getValue();
		return 1 / Math.tan(rVal);
	};

	/** The Constant ASIN. */
	public static final IFunction<Double> ASIN = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ASIN, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.asin(rVal);
	};

	/** The Constant ACOS. */
	public static final IFunction<Double> ACOS = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ACOS, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.acos(rVal);
	};

	/** The Constant ATAN. */
	public static final IFunction<Double> ATAN = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ATAN, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.atan(rVal);
	};

	/** The Constant ACOT. */
	public static final IFunction<Double> ACOT = (aArr) ->
	{
		if (aArr.size() != 1) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ACOT, aArr.size());
		double rVal = aArr.get(0).getValue();
		return Math.atan(1 / rVal);
	};
	
	/** The Constant PI. */
	public static final IFunction<Double> PI = (aArr) ->
	{
		if (aArr!=null) if (aArr.size() != 0) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ACOT, aArr.size());
		return Math.PI;
	};
}
