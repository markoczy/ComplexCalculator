/**
 * File: JComplexCalculator::BasicFunctionsImpl.java
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
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.definition.IFunction;
import mkz.util.io.IO;

/**
 * The Class BasicFunctions. Holds the implementation of all basic functions (such as "+","-" etc.).
 */
public class BasicFunctionsImpl
{
	/** The Constant ADD. */
	public static final IFunction<Double> ADD=(aArr)->
	{
		IO.dbOutV("Solving addition.");
		
		if(aArr.size()<2)throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.ADD,aArr.size());
		Double rVal=0.0;
		
		// eg. 1 + 2 + 3 = 6
		for(IEquation<Double> iEq:aArr) rVal+=iEq.getValue();
		return rVal;
	};

	/** The Constant SUB. */
	public static final IFunction<Double> SUB=(aArr)->
	{
		IO.dbOutV("Solving subtraction.");
		
		if(aArr.size()<2)throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.SUB,aArr.size());
		double rVal=aArr.get(0).getValue();
		for(int i = 1;i<aArr.size();i++) rVal-=aArr.get(i).getValue();
		return rVal;
	};
	
	/** The Constant MPL. */
	public static final IFunction<Double> MPL=(aArr)->
	{
		IO.dbOutV("Solving multiplication.");
		
		if(aArr.size()<2) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.MPL,aArr.size());
		double rVal=aArr.get(0).getValue();
		for(int i = 1;i<aArr.size();i++) rVal*=aArr.get(i).getValue();
		return rVal;
	};
	
	/** The Constant DIV. */
	public static final IFunction<Double> DIV=(aArr)->
	{
		IO.dbOutV("Solving division.");
		
		if(aArr.size()<2) throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.DIV,aArr.size());
		double rVal=aArr.get(0).getValue();
		for(int i = 1;i<aArr.size();i++) rVal/=aArr.get(i).getValue();
		return rVal;
	};
	
	/** The Constant EXP. */
	public static final IFunction<Double> EXP=(aArr)->
	{
		IO.dbOutV("Solving exponential.");
		
		if(aArr.size()!=2)throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.EXP,aArr.size());
		double rVal=aArr.get(0).getValue();
		
		// eg. 2 ^ 3 ^ 2 = 64
		for(int i = 1;i<aArr.size();i++) rVal=Math.pow(rVal, aArr.get(i).getValue());
		return rVal;
	};
	
	/** The Constant INV. */
	public static final IFunction<Double> INV=(aArr)->
	{
		IO.dbOutV("Solving inversion.");
		
		if(aArr.size()!=1)throw new InvalidParamCountException(ConstantsArithmetic.DisplayNames.INV,aArr.size());
		double rVal=aArr.get(0).getValue();
		return -rVal;
	};
}
