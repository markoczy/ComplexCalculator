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

import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.arithmetic.equation.ParamLinearArithmeticEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.core.equation.function.ParamFunction;
import mkz.util.generic.Pair;
import mkz.util.io.IO;

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
	
	public boolean deleteFunction(String aCallName)
	{
		return mFunctions.remove(aCallName)!=null;
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
			aFunctions.put(ConstantsArithmetic.CallNames.PI, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.PI, CallableFunctionsImpl.PI));
			aFunctions.put(ConstantsArithmetic.CallNames.ADD, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.SUM, CallableFunctionsImpl.SUM));
			aFunctions.put(ConstantsArithmetic.CallNames.SUM, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.SUM, CallableFunctionsImpl.SUM));
			aFunctions.put(ConstantsArithmetic.CallNames.EXP, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.EXP, CallableFunctionsImpl.EXP));
			aFunctions.put(ConstantsArithmetic.CallNames.LOG, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.LOG, CallableFunctionsImpl.LOG));
			aFunctions.put(ConstantsArithmetic.CallNames.SIN, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.SIN, CallableFunctionsImpl.SIN));
			aFunctions.put(ConstantsArithmetic.CallNames.COS, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.COS, CallableFunctionsImpl.COS));
			aFunctions.put(ConstantsArithmetic.CallNames.TAN, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.TAN, CallableFunctionsImpl.TAN));
			aFunctions.put(ConstantsArithmetic.CallNames.COT, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.COT, CallableFunctionsImpl.COT));
			aFunctions.put(ConstantsArithmetic.CallNames.ASIN, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.ASIN, CallableFunctionsImpl.ASIN));
			aFunctions.put(ConstantsArithmetic.CallNames.ACOS, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.ACOS, CallableFunctionsImpl.ACOS));
			aFunctions.put(ConstantsArithmetic.CallNames.ATAN, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.ATAN, CallableFunctionsImpl.ATAN));
			aFunctions.put(ConstantsArithmetic.CallNames.ACOT, new Pair<String, IFunction<Double>>(ConstantsArithmetic.DisplayNames.ACOT, CallableFunctionsImpl.ACOT));
			IO.dbOutD("Default functions loaded.");
			return true;
		}
		catch (Exception e)
		{
			IO.dbOutE(e);
			return false;
		}
	}

//	/**
//	 * The Class CallNames.
//	 */
//	private static class CallNames
//	{
//		/** The Constant PI. */
//		public static final String PI = "pi";
//		
//		/** The Constant SUM. */
//		public static final String ADD = "add";
//		
//		/** The Constant SUM. */
//		public static final String SUM = "sum";
//		
//		/** The Constant EXP. */
//		public static final String EXP = "exp";
//		
//		/** The Constant LOG. */
//		public static final String LOG = "log";
//
//		/** The Constant SIN. */
//		public static final String SIN = "sin";
//		
//		/** The Constant COS. */
//		public static final String COS = "cos";
//		
//		/** The Constant TAN. */
//		public static final String TAN = "tan";
//		
//		/** The Constant COT. */
//		public static final String COT = "cot";
//
//		/** The Constant ASIN. */
//		public static final String ASIN = "asin";
//		
//		/** The Constant ACOS. */
//		public static final String ACOS = "acos";
//		
//		/** The Constant ATAN. */
//		public static final String ATAN = "atan";
//		
//		/** The Constant ACOT. */
//		public static final String ACOT = "acot";
//	}

}
