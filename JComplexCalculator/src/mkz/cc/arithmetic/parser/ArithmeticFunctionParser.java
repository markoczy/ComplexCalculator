/**
 * File: JComplexCalculator::ArithmeticFunctionParser.java
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
package mkz.cc.arithmetic.parser;

import java.util.ArrayList;
import java.util.Arrays;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.arithmetic.equation.LinearArithmeticEquation;
import mkz.cc.arithmetic.equation.ParamLinearArithmeticEquation;
import mkz.cc.arithmetic.function.ArithmeticFunctions;
import mkz.cc.core.CCalcCommon;
import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.function.Variable;
import mkz.cc.core.parser.ParserCursor;
import mkz.cc.core.parser.ParserTools;
import mkz.util.io.IO;

/**
 * The Class ArithmeticFunctionParser.
 */
public final class ArithmeticFunctionParser extends ArithmeticEquationParser
{
	
	/** The functions. */
	private static ArithmeticFunctions functions = ArithmeticFunctions.getInstance();
	
	/** The member param names. */
	private ArrayList<String> mParamNames;
	
	/**
	 * Parses the function.
	 *
	 * @param aEquation the reference equation
	 * @return true, if successful
	 * @throws ParserException the parser exception
	 */
	public boolean parseFunction(String aEquation) throws ParserException
	{
		//
		// e.g. f(x):=2*x
		//
		//
		
		mCursor = new ParserCursor();
		
		String lName=ParserTools.parseIdentifier(aEquation, mCursor, false);
		
		if(functions.getFuncion(lName)!=null) 
		{
			IO.dbOutE("Cannot add function: Name is not unique");
			return false;
		}
		
		mParamNames = _parseParamNames(aEquation, mCursor);
		for(String iParam:mParamNames) IO.dbOutV("Found param: "+iParam);
		
		IO.dbOutD("Current char = "+mCursor.get(aEquation));
		
		if(!_parseFcnDefOf(aEquation,mCursor))
		{
			IO.dbOutE("Function definition operator not found.");
			return false;
		}
		
		IEquation<Double> lNewFunction=_parseEquation(aEquation, mCursor);
		
		if(lNewFunction instanceof ParamLinearArithmeticEquation)
		{
			ParamLinearArithmeticEquation lEquation=(ParamLinearArithmeticEquation)lNewFunction;
//			IO.SysOutD("Added "+mTopLevelParams.size()+" logical param(s)");
			functions.addFunction(lName, lName, mParamNames, aEquation, lEquation);
			return true;
		}
		else
		{
			IO.dbOutE("Implementation fault: Parsed an invalid function type, type is: "+lNewFunction.getClass().getCanonicalName());
			return false;
		}
	}
	
	/**
	 * _parse fcn def of.
	 *
	 * @param aEquation the reference equation
	 * @param aCursor the reference cursor
	 * @return true, if successful
	 */
	private boolean _parseFcnDefOf(String aEquation, ParserCursor aCursor)
	{
		if(aCursor.get(aEquation)==':')
		{
			aCursor.next();
			if(aCursor.get(aEquation)=='=')
			{
				aCursor.next();
				return true;
			}
		}
		
		return false;
	}
	
	
	/**
	 * _parse param names.
	 *
	 * @param equation the equation
	 * @param aCursor the reference cursor
	 * @return the array list
	 */
	private ArrayList<String> _parseParamNames(String equation, ParserCursor aCursor)
	{
		ArrayList<String> rVal = new ArrayList<String>();
		if (!CCalcCommon.isParOpen(aCursor.get(equation))) return rVal;
		aCursor.next();

		String lParams = new String();
		while (!aCursor.exceeds(equation) && !CCalcCommon.isParClose(aCursor.get(equation)))
		{
			lParams += aCursor.get(equation);
			aCursor.next();
		}

		rVal = (lParams.split(",")).length > 0 ? new ArrayList<String>(Arrays.asList(lParams.split(","))) : rVal;
		
		// skip last closing paranthesis
		aCursor.next();
		
		return rVal;
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.core.arithmetic.parser.ArithmeticEquationParser#_parseFunctionCall(java.lang.String, mkz.cc.core.parser.ParserCursor)
	 */
	@Override
	protected IEquation<Double> _parseFunctionCall(String equation, ParserCursor aCursor) throws ParserException
	{
		IO.dbOutV("init, current char: "+aCursor.get(equation));
		String lName = ParserTools.parseIdentifier(equation, aCursor, false);
		
//		for(String iParam:mParamNames)IO.SysOutV("Param = "+iParam);
		
		// if is a function param, return a new variable
		if(mParamNames.contains(lName))
		{
			IO.dbOutV("Name '"+lName+"' is a param");
			Variable<Double> lVar = new Variable<Double>(lName);
//			mTopLevelParams.add(lVar);
			return lVar;
		}
		
		Equation<Double> lFcn = ArithmeticEquationFactory.createParamFuncionEquation(lName);
		if(lFcn!=null)
		{
			IO.dbOutV("Found function, name is "+lName);
			ArrayList<String> lParamStrs = ParserTools.getParamSubstrings(equation, aCursor);
			for(String iParamStr:lParamStrs) lFcn.addParam(_parseEquation(iParamStr,new ParserCursor()));
		}
		else throw new ParserException("Called a function that was not found in library, name is "+lName);
		
		return lFcn;
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.arithmetic.parser.ArithmeticEquationParser#_getNewEquation()
	 */
	@Override
	protected LinearArithmeticEquation _getNewEquation()
	{
		IO.dbOutV("provided param equation");
		return new ParamLinearArithmeticEquation();
	}
	
	/* (non-Javadoc)
	 * @see mkz.cc.arithmetic.parser.ArithmeticEquationParser#_getInversion(mkz.cc.core.equation.definition.IEquation)
	 */
	@Override
	protected IEquation<Double> _getInversion(IEquation<Double> aEquation)
	{
		IO.dbOutV("Provided parametrizable inversion");
		return ArithmeticEquationFactory.createParamInversion(aEquation);
	}
	
}
