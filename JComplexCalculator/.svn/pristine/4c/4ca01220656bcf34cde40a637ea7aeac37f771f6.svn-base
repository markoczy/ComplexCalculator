/**
 * File: JComplexCalculator::LogicalTruthTableDisp.java
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
package mkz.cc.ui;

import java.util.ArrayList;

import mkz.util.io.IO;

/**
 * The Class LogicalTruthTableDisp.
 */
public class LogicalTruthTableDisp
{
	
	/** The Constant RESULT_STRING. */
	private static final String RESULT_STRING="R";

	/**
	 * Gets the lines.
	 *
	 * @param aGrid the reference grid
	 * @param aParamNames the reference param names
	 * @return the lines
	 */
	public static ArrayList<String> getLines(ArrayList<ArrayList<Boolean>> aGrid, ArrayList<String> aParamNames)
	{
		ArrayList<String> rVal = new ArrayList<String>();
		rVal.addAll(_getHeaderRows(aParamNames));
		rVal.addAll(_getBodyRows(aParamNames,aGrid));
		rVal.add(rVal.get(0));
		return rVal;
	}
	
	
	/**
	 * [restricted] get header rows.
	 *
	 * @param aParamNames the reference param names
	 * @return the array list
	 */
	protected static ArrayList<String> _getHeaderRows(ArrayList<String> aParamNames)
	{
		if(aParamNames==null)
		{
			IO.dbOutE("Cannot create Header, no params found.");
			return null;
		}
		
		StringBuilder lRow1=new StringBuilder();
		StringBuilder lRow2=new StringBuilder();
		
		lRow1.append("+");
		lRow2.append("|");
		
		for(String iParamName:aParamNames)
		{
			lRow1.append('-');
			for(int i=0;i<iParamName.length();i++)
			{ 
				lRow1.append('-');
			}
			// ' ' & '|' 
			lRow1.append('-');
			lRow1.append('-');
			
			
			lRow2.append(' ');
			lRow2.append(iParamName);
			lRow2.append(' ');
			lRow2.append('|');
			
		}
		
		lRow1.append('-');
		for(int i=0;i<RESULT_STRING.length();i++)
		{ 
			lRow1.append('-');
		}
		lRow1.append('-');
		
		lRow2.append(' ');
		lRow2.append(RESULT_STRING);
		lRow2.append(' ');
		lRow2.append('|');
		lRow1.append("+");
		
		ArrayList<String> rVal = new ArrayList<String>();
		
		rVal.add(lRow1.toString());
		rVal.add(lRow2.toString());
		rVal.add(lRow1.toString());
		
		return rVal;
	}
	
	/**
	 * [restricted] get body rows.
	 *
	 * @param aParamNames the reference param names
	 * @param aParams the reference params
	 * @return the array list
	 */
	protected static ArrayList<String> _getBodyRows(ArrayList<String> aParamNames,ArrayList<ArrayList<Boolean>> aParams)
	{
		ArrayList<Integer> lOffsetsLeft = new ArrayList<Integer>();
		ArrayList<Integer> lOffsetsRight = new ArrayList<Integer>();
		
		for(String iParamName:aParamNames)
		{
			lOffsetsRight.add((int)(iParamName.length()/2));
			lOffsetsLeft.add(iParamName.length()-(int)(iParamName.length()/2)-1);
		}
		lOffsetsRight.add((int)(RESULT_STRING.length()/2));
		lOffsetsLeft.add(RESULT_STRING.length()-(int)(RESULT_STRING.length()/2)-1);
		
		ArrayList<String> rVal = new ArrayList<String>();
		
		for(int iRow=0;iRow<aParams.size();iRow++)
		{
			StringBuilder lRowStr = new StringBuilder();
			lRowStr.append('|');
			for(int iCol=0;iCol<aParams.get(iRow).size();iCol++)
			{
				lRowStr.append(' ');
				for(int iOffL=0;iOffL<lOffsetsLeft.get(iCol);iOffL++)lRowStr.append(' ');
				
				lRowStr.append(""+(aParams.get(iRow).get(iCol)==true?1:0));
				
				for(int iOffR=0;iOffR<lOffsetsRight.get(iCol);iOffR++)lRowStr.append(' ');
				
				lRowStr.append(' ');
				lRowStr.append('|');
			}
			
			rVal.add(lRowStr.toString());
		}
		
		
		return rVal;
	}
}
