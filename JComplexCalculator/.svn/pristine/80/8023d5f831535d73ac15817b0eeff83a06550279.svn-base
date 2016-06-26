/**
 * File: JComplexCalculator::ArithmeticEquationFactory.java
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
package mkz.cc.arithmetic;

import java.util.HashMap;

import mkz.cc.arithmetic.function.ArithmeticFunctions;
import mkz.cc.arithmetic.function.BasicFunctionsImpl;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.cc.core.equation.function.ParamEquation;
import mkz.cc.util.IO;
import mkz.cc.util.Pair;

/**
 * A factory for creating basic Equation objects.
 */
public class ArithmeticEquationFactory
{
	
	/** The functions. */
	private static ArithmeticFunctions functions = ArithmeticFunctions.getInstance();
	
	/** The Constant BASIC_OPS_TABLE. */
	private static final HashMap<Operation,IFunction<Double>> BASIC_OPS_TABLE= _createBasicOpsTable();
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aValue the reference value
	 * @return the constant
	 */
	public static Constant<Double> createConstant(double aValue)
	{
		return new Constant<Double>(aValue);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aOp the reference op
	 * @return the equation
	 */
	public static Equation<Double> createBasicEquation(Operation aOp)
	{
		Equation<Double> rVal=null;
		
		IFunction<Double> lFunction=BASIC_OPS_TABLE.get(aOp);
		
		// means that the operation is valid
		if(lFunction!=null)
		{
			rVal = new Equation<Double>(aOp.toString(),lFunction);
		}
		else
		{
			IO.SysOutE("Trying to make an equation using an invalid Operation, OP is "+aOp);
		}
		
		return rVal;
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createInversion()
	{
		return new Equation<Double>(Equation.DisplayNames.INV,BasicFunctionsImpl.INV);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aValue the reference value
	 * @return the equation
	 */
	public static Equation<Double> createInversion(IEquation<Double> aValue)
	{
		return new Equation<Double>(Equation.DisplayNames.INV,BasicFunctionsImpl.INV).addParam(aValue);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createAddition()
	{
		return new Equation<Double>(Equation.DisplayNames.ADD,BasicFunctionsImpl.ADD);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aV1 the reference v1
	 * @param aV2 the reference v2
	 * @return the equation
	 */
	public static Equation<Double> createAddition(IEquation<Double> aV1,IEquation<Double> aV2)
	{
		return new Equation<Double>(Equation.DisplayNames.ADD,BasicFunctionsImpl.ADD).addParam(aV1).addParam(aV2);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createSubtraction()
	{
		return new Equation<Double>(Equation.DisplayNames.SUB,BasicFunctionsImpl.SUB);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aV1 the reference v1
	 * @param aV2 the reference v2
	 * @return the equation
	 */
	public static Equation<Double> createSubtraction(IEquation<Double> aV1,IEquation<Double> aV2)
	{
		return new Equation<Double>(Equation.DisplayNames.SUB,BasicFunctionsImpl.SUB).addParam(aV1).addParam(aV2);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createMultiplication()
	{
		return new Equation<Double>(Equation.DisplayNames.MPL,BasicFunctionsImpl.MPL);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aV1 the reference v1
	 * @param aV2 the reference v2
	 * @return the equation
	 */
	public static Equation<Double> createMultiplication(IEquation<Double> aV1,IEquation<Double> aV2)
	{
		return new Equation<Double>(Equation.DisplayNames.MPL,BasicFunctionsImpl.MPL).addParam(aV1).addParam(aV2);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createDivision()
	{
		return new Equation<Double>(Equation.DisplayNames.DIV,BasicFunctionsImpl.DIV);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aV1 the reference v1
	 * @param aV2 the reference v2
	 * @return the equation
	 */
	public static Equation<Double> createDivision(IEquation<Double> aV1,IEquation<Double> aV2)
	{
		return new Equation<Double>(Equation.DisplayNames.DIV,BasicFunctionsImpl.DIV).addParam(aV1).addParam(aV2);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @return the equation
	 */
	public static Equation<Double> createExponential()
	{
		return new Equation<Double>(Equation.DisplayNames.EXP,BasicFunctionsImpl.EXP);
	}
	
	/**
	 * Creates a new Equation object.
	 *
	 * @param aV1 the reference v1
	 * @param aV2 the reference v2
	 * @return the equation
	 */
	public static Equation<Double> createExponential(IEquation<Double> aV1,IEquation<Double> aV2)
	{
		return new Equation<Double>(Equation.DisplayNames.EXP,BasicFunctionsImpl.EXP).addParam(aV1).addParam(aV2);
	}
	
	
	/**
	 * Creates a new Equation object. Equation of a function (e.g. x+y).
	 *
	 * @param aCallName the reference call name
	 * @return the equation
	 */
	public static Equation<Double> createFuncionEquation(String aCallName)
	{
		Pair<String, IFunction<Double>> lFcn=functions.getFuncion(aCallName);
		return lFcn != null ? new Equation<Double>(lFcn.getObject1(), lFcn.getObject2()) : null;
	}

	/**
	 * Creates a new Equation object. Parametrizable equation of a function.
	 *
	 * @param aCallName the reference call name
	 * @return the equation
	 */
	public static Equation <Double>createParamFuncionEquation(String aCallName)
	{
		Pair<String, IFunction<Double>> lFcn=functions.getFuncion(aCallName);
		if(lFcn==null)IO.SysOutE("Function with call name "+aCallName+" has not been found in arithmetic functions pool.");
		return lFcn != null ? new ParamEquation<Double>(lFcn.getObject1(), lFcn.getObject2()) : null;
	}

	/**
	 * [restricted] create basic ops table. Maps operations with corresponding interfaces.
	 *
	 * @return the hash map
	 */
	private static HashMap<Operation,IFunction<Double>> _createBasicOpsTable()
	{
		HashMap<Operation,IFunction<Double>> rVal = new HashMap<Operation,IFunction<Double>>();
		rVal.put(Operation.ADD, BasicFunctionsImpl.ADD);
		rVal.put(Operation.SUB, BasicFunctionsImpl.SUB);
		rVal.put(Operation.MPL, BasicFunctionsImpl.MPL);
		rVal.put(Operation.DIV, BasicFunctionsImpl.DIV);
		rVal.put(Operation.EXP, BasicFunctionsImpl.EXP);
		return rVal;
	}
	
	
}
