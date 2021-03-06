/**
 * File: JComplexCalculator::LogicalDefinitionParser.java
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
package mkz.cc.logical.parser;

import java.util.ArrayList;
import java.util.Arrays;

import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.equation.function.Variable;
import mkz.cc.core.parser.ParserCursor;
import mkz.cc.core.parser.ParserTools;
import mkz.cc.logical.LogicalEquationFactory;
import mkz.cc.logical.equation.LinearLogicalEquation;
import mkz.cc.logical.equation.ParamLinearLogicalEquation;
import mkz.util.io.IO;

/**
 * The Class LogicalDefinitionParser.
 */
public class LogicalDefinitionParser extends LogicalEquationParser
{
	/** The member cursor. */
	ParserCursor mCursor=null;
	
	ArrayList<String> mParamNames=new ArrayList<String>();
	
	/**
	 * Parses the equation. Returns verity table as 2D boolean array.
	 * Example use: '(a,b,c)->a&!b|c'
	 *
	 * @param aEquation the reference equation
	 * @return the boolean[][]
	 * @throws ParserException 
	 */
	public ArrayList<ArrayList<Boolean>> parseDefinition(String aEquation) throws ParserException
	{
		mParamNames=parseVariableNames(aEquation);
		
		int lPos=aEquation.indexOf("->");
		if(lPos==-1)
		{
			IO.dbOutE("Definition sign '->' not found, exiting..");
			return null;
		}
		
		mCursor=new ParserCursor(lPos+2);
		IEquation<Boolean> lParsedParamEq=_parseEquation(aEquation, mCursor);
		
		if(!(lParsedParamEq instanceof ParamLinearLogicalEquation))
		{
			IO.dbOutE("Implementation fault, Equation is not a Parametrizable Logical equation, type: "+ lParsedParamEq.getClass().getCanonicalName());
			return null;
		}
		
		ParamLinearLogicalEquation lParamEq = (ParamLinearLogicalEquation)lParsedParamEq;
		Equation<Boolean> lFunctionEq= LogicalEquationFactory.createDefinitionEquation(aEquation, mParamNames, lParamEq);
		
		
		ArrayList<ArrayList<Boolean>> lTable = _getInputTable(mParamNames.size());
		
		for(ArrayList<Boolean> iRow:lTable)
		{
			ArrayList<IEquation<Boolean>> lParams=new ArrayList<IEquation<Boolean>>();
			for(Boolean iVal:iRow)
			{
				lParams.add(new Constant<Boolean>(iVal));
			}
			lFunctionEq.setParams(lParams);
			
			iRow.add(lFunctionEq.getValue());
		}
		
		
//		lEq.getValue();
//		try
//		{
//			IO.SysOutV("TestVal: "+lEq.getValue());
//		}
//		catch (CCalcException e)
//		{
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		
		for(ArrayList<Boolean> iRow:lTable)
		{
			StringBuilder sb = new StringBuilder();
			for(Boolean iVal:iRow) sb.append(""+iVal+"\t");
			
			IO.dbOutV("Row: "+sb.toString());
		}
		

		
		return lTable;
	}
	
	
	/**
	 * Parses the variable names. e.g.: '(a,b)->a&b' returns {a,b} 
	 *
	 * @return the array list
	 */
	public static ArrayList<String> parseVariableNames(String aEquation)
	{
		ParserCursor lCursor = new ParserCursor();
		
		// it's allowed to define params with or without '()'
		//
		if(lCursor.get(aEquation)=='(')
		{
			IO.dbOutV("Skipped first par open");
			lCursor.next();
		}
		
		String lParamStr = new String();
		
		boolean lExit=false;
		while(!lExit)
		{
			lParamStr+=lCursor.get(aEquation);
			lCursor.next();
			
			if(!lCursor.exceeds(aEquation))
			{
				lExit|=lCursor.get(aEquation)==')';
				lExit|=lCursor.get(aEquation)=='-';
			}
			else lExit=true;
		}
		
		if(lParamStr.length()!=0)
		{
			return new ArrayList<String>(Arrays.asList(lParamStr.split(",")));
		}
		
		return null;
	}
	
	@Override
	protected IEquation<Boolean> _getInversion(IEquation<Boolean> aEquation)
	{
		return LogicalEquationFactory.createParamInversion(aEquation);
	}
	
	@Override
	protected LinearLogicalEquation _getNewEquation()
	{
		return new ParamLinearLogicalEquation();
	}
	
	@Override
	protected IEquation<Boolean> _parseAlphabetic(String equation, ParserCursor aCursor) throws ParserException
	{
		String lName = ParserTools.parseIdentifier(equation, aCursor,false);
		
		for(String iParam:mParamNames)if(iParam.equals(lName))
		{
			IO.dbOutV("Found param '"+lName+"'");
			return new Variable<Boolean>(lName);
		}
		
		return super._parseAlphabetic(equation, aCursor);
	}
	
	
	public ArrayList<ArrayList<Boolean>> _getInputTable(int aVarCount)
	{
		int lPossibilities = 1;
		for(int i=0;i<aVarCount;i++) lPossibilities*=2;
		IO.dbOutV("Possibilities = "+lPossibilities);
		
		ArrayList<ArrayList<Boolean>> rVal = new ArrayList<ArrayList<Boolean>>();
		
		int[] lMods = new int[aVarCount];
		
		for(int i = 0;i<aVarCount;i++)
		{
			int lVal=1;
			for(int j=0;j<(aVarCount-i-1);j++) lVal*=2;
			
			lMods[i]=lVal;
			IO.dbOutV("lMods["+i+"]="+lMods[i]);
		}

		// init as '000000..'
		ArrayList<Boolean> lRow = new ArrayList<Boolean>();
		for(int i=0;i<aVarCount;i++) lRow.add(false);
		
		rVal.add(lRow);
		
		for(int i = 1; i<lPossibilities;i++)
		{
			lRow = new ArrayList<Boolean>(lRow); // -> and fixed
			
			for(int iMod=0;iMod<lMods.length;iMod++)
			{
				if(i%lMods[iMod]==0) lRow.set(iMod, !lRow.get(iMod));
			}
			
			rVal.add(lRow);
		}
		
		for(ArrayList<Boolean> iRow:rVal)
		{
			StringBuilder sb = new StringBuilder();
			for(Boolean iVal:iRow) sb.append(""+iVal+"\t");
			
			IO.dbOutV("Row: "+sb.toString());
		}
		
		
		return rVal;
	}
	
}
