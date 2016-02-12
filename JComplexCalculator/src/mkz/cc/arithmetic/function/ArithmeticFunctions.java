/**
 * File: JComplexCalculator::ArithmeticFunctions.java
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

import java.util.ArrayList;
import java.util.HashMap;

import mkz.cc.arithmetic.equation.ParamLinearArithmeticEquation;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.core.equation.function.ParamFunction;
import mkz.cc.util.IO;
import mkz.cc.util.Pair;

/**
 * The Class FunctionPool.
 */
public class ArithmeticFunctions
{
	/** The instance. */
	private static ArithmeticFunctions instance = new ArithmeticFunctions();

	/** The member functions. */
	private HashMap<String, Pair<String, IFunction<Double>>> mFunctions = new HashMap<String, Pair<String, IFunction<Double>>>();

	/** The member function constructors. */
	// The function definition statements (e.g. {"f","f(x):=2x"})
	private HashMap<String, String> mFunctionConstructors = new HashMap<String, String>();

	/**
	 * Instantiates a new function pool.
	 */
	private ArithmeticFunctions()
	{
		_initDefaultFunctions(mFunctions);
	}

	/**
	 * Gets the single instance of FunctionPool.
	 *
	 * @return single instance of FunctionPool
	 */
	public static ArithmeticFunctions getInstance()
	{
		return instance;
	}

	/**
	 * Gets the funcion.
	 *
	 * @param aCallName the reference call name
	 * @return the funcion
	 */
	public Pair<String, IFunction<Double>> getFuncion(String aCallName)
	{
		Pair<String, IFunction<Double>> lFcn = mFunctions.get(aCallName);
		return lFcn;
	}

	/**
	 * Adds the function.
	 *
	 * @param aCallName the reference call name
	 * @param aDisplayName the reference display name
	 * @param aParamNames the reference param names
	 * @param aCreateStatement the reference create statement
	 * @param aFunction the reference function
	 * @return true, if successful
	 */
	public boolean addFunction(String aCallName, String aDisplayName, ArrayList<String> aParamNames, String aCreateStatement, ParamLinearArithmeticEquation aFunction)
	{
		if (!mFunctions.containsKey(aCallName))
		{
			ParamFunction<Double> lFunction = new ParamFunction<Double>(aDisplayName, aParamNames, aFunction);
			mFunctions.put(aCallName, new Pair<String, IFunction<Double>>(aDisplayName, lFunction));
			mFunctionConstructors.put(aCallName, aCreateStatement);
			return true;
		}

		return false;

	}

	/**
	 * [restricted] init default functions.
	 *
	 * @param aFunctions the reference functions
	 * @return true, if successful
	 */
	private static boolean _initDefaultFunctions(HashMap<String, Pair<String, IFunction<Double>>> aFunctions)
	{
		try
		{
			aFunctions.put(CallNames.PI, new Pair<String, IFunction<Double>>(Equation.DisplayNames.PI, CallableFunctionsImpl.PI));
			aFunctions.put(CallNames.ADD, new Pair<String, IFunction<Double>>(Equation.DisplayNames.SUM, CallableFunctionsImpl.SUM));
			aFunctions.put(CallNames.SUM, new Pair<String, IFunction<Double>>(Equation.DisplayNames.SUM, CallableFunctionsImpl.SUM));
			aFunctions.put(CallNames.EXP, new Pair<String, IFunction<Double>>(Equation.DisplayNames.EXP, CallableFunctionsImpl.EXP));
			aFunctions.put(CallNames.LOG, new Pair<String, IFunction<Double>>(Equation.DisplayNames.LOG, CallableFunctionsImpl.LOG));
			aFunctions.put(CallNames.SIN, new Pair<String, IFunction<Double>>(Equation.DisplayNames.SIN, CallableFunctionsImpl.SIN));
			aFunctions.put(CallNames.COS, new Pair<String, IFunction<Double>>(Equation.DisplayNames.COS, CallableFunctionsImpl.COS));
			aFunctions.put(CallNames.TAN, new Pair<String, IFunction<Double>>(Equation.DisplayNames.TAN, CallableFunctionsImpl.TAN));
			aFunctions.put(CallNames.COT, new Pair<String, IFunction<Double>>(Equation.DisplayNames.COT, CallableFunctionsImpl.COT));
			aFunctions.put(CallNames.ASIN, new Pair<String, IFunction<Double>>(Equation.DisplayNames.ASIN, CallableFunctionsImpl.ASIN));
			aFunctions.put(CallNames.ACOS, new Pair<String, IFunction<Double>>(Equation.DisplayNames.ACOS, CallableFunctionsImpl.ACOS));
			aFunctions.put(CallNames.ATAN, new Pair<String, IFunction<Double>>(Equation.DisplayNames.ATAN, CallableFunctionsImpl.ATAN));
			aFunctions.put(CallNames.ACOT, new Pair<String, IFunction<Double>>(Equation.DisplayNames.ACOT, CallableFunctionsImpl.ACOT));
			IO.SysOutD("Default functions loaded.");
			return true;
		}
		catch (Exception e)
		{
			IO.SysOutE(e);
			return false;
		}
	}

	/**
	 * The Class CallNames.
	 */
	private static class CallNames
	{
		/** The Constant PI. */
		public static final String PI = "pi";
		
		/** The Constant SUM. */
		public static final String ADD = "add";
		
		/** The Constant SUM. */
		public static final String SUM = "sum";
		
		/** The Constant EXP. */
		public static final String EXP = "exp";
		
		/** The Constant LOG. */
		public static final String LOG = "log";

		/** The Constant SIN. */
		public static final String SIN = "sin";
		
		/** The Constant COS. */
		public static final String COS = "cos";
		
		/** The Constant TAN. */
		public static final String TAN = "tan";
		
		/** The Constant COT. */
		public static final String COT = "cot";

		/** The Constant ASIN. */
		public static final String ASIN = "asin";
		
		/** The Constant ACOS. */
		public static final String ACOS = "acos";
		
		/** The Constant ATAN. */
		public static final String ATAN = "atan";
		
		/** The Constant ACOT. */
		public static final String ACOT = "acot";
	}

}
