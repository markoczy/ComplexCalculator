package mkz.cc.core.parser;

import java.util.ArrayList;

import mkz.cc.core.CCalcCommon;
import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.util.IO;

public class ParserTools
{

	public static String parseIdentifier(String aEquation, ParserCursor aCursor, boolean allowNumbers) throws ParserException
	{
		//
		// e.g "x","y","f1","f.g" etc.
		//

		String rVal = "";

		boolean lExit=false;
		while (!lExit)
		{
			char chr = aCursor.get(aEquation);
			rVal += chr;
			
			aCursor.next();
			if(!aCursor.exceeds(aEquation)) lExit=!(CCalcCommon.isAlpha(aCursor.get(aEquation)) || (allowNumbers && CCalcCommon.isDecimal(aCursor.get(aEquation))));
			else lExit = true;
		}
		
		//
		if(rVal.equals("")) throw new ParserException("Identifier could not be parsed, it was empty.");
		
		IO.SysOutD("Parsed Identifier: " + rVal);
		return rVal;
	}
	
	public static double parseNumber(String equation, ParserCursor aCursor) throws ParserException
	{
		//
		// e.g. "1","1.232",".23" -> NYI,TBD
		//
		
		String num = new String();

		while (!aCursor.exceeds(equation) && CCalcCommon.isDecimal(aCursor.get(equation)))
		{
			char chr = aCursor.get(equation);
			num += chr;
			// charCount++;
			aCursor.next();

		}

		IO.SysOutD("NumberString = " + num);
		
		double rVal = 0;
		
		try
		{
			rVal=Double.parseDouble(num);
		}
		catch (NumberFormatException  lE)
		{
			throw new ParserException("String '"+num+"' could not be parsed to a double value.");
		}
		
		return rVal;
	}
	
	public static String getParamSubstring(String aEquation, ParserCursor aCursor) throws ParserException
	{
		//-//-//-//-//-//-//-//-//-//-//-//
		// Example: f((1+4/2)+1,4)
		//            |^      ^|
		//-//-//-//-//-//-//-//-//-//-//-//
		// ^^ = return value
		// || = parser cursor
		//-//-//-//-//-//-//-//-//-//-//-//

		// Params
		int parCount = 0;
		String rVal = "";
		
		// Loop
		boolean lExit = false;
		while (!lExit)
		{
			// update paranthesis and add char
			char chr = aCursor.get(aEquation);
			parCount += CCalcCommon.parseParanthesis(chr);
			
			if(parCount>=0)rVal += chr;
			
			// update cursor and exit conditions
			aCursor.next();
			if(!aCursor.exceeds(aEquation)) lExit= (parCount==0 && 
					(aCursor.get(aEquation)==',' || CCalcCommon.isParClose(aCursor.get(aEquation))));
			else lExit=true;
		}

		if(parCount>0) throw new ParserException("The param substring was not closed, string is: "+rVal);
		IO.SysOutD("Param Substring = " + rVal);
		
		return rVal;
	}
	
	public static String getEquationSubstring(String aEquation, ParserCursor aCursor) throws ParserException
	{
		//-//-//-//-//-//-//-//-//-//-//-//
		// Example: 22+(24-(5/3.43)+12)
		//             |^            ^ |
		//-//-//-//-//-//-//-//-//-//-//-//
		// ^^ = return value
		// || = parser cursor
		//-//-//-//-//-//-//-//-//-//-//-//

		// failsafe
		if(!CCalcCommon.isParOpen(aCursor.get(aEquation))) throw new ParserException("First char is not an open paranthesis (as required) char is: "+aCursor.get(aEquation));
		aCursor.next();
		
		// Params
		int parCount = 1;
		String rVal = "";
		
		// Loop
		boolean lExit = false;
		while (!lExit)
		{
			// update paranthesis and add char
			char chr = aEquation.charAt(aCursor.getPosition());
			parCount += CCalcCommon.parseParanthesis(chr);
			if(parCount!=0) rVal += chr;
			
			// update cursor and exit conditions
			aCursor.next();
			if(!aCursor.exceeds(aEquation)) lExit=parCount<=0;
			else lExit=true;
		}
		aCursor.previous(); // XXX maybe a better way..

		// failsafe
		if(parCount!=0) throw new ParserException("The equation string was not closed, string is: "+rVal);
		if(!CCalcCommon.isParClose(aCursor.get(aEquation))) throw new ParserException("The last char of the equation string was not a closed paranthesis (as required), string is: "+rVal);
		
		IO.SysOutD("Equation substring is "+rVal);
		
		return rVal;
	}
	
//	public static String getEquationSubstring(String aEquation, ParserCursor aCursor)
//	{
//		return getEquationSubstring(aEquation, aCursor,null);
//	}
	
	
	public static ArrayList<String> getParamSubstrings(String aEquation, ParserCursor aCursor) throws ParserException
	{
		ArrayList<String> rVal= new ArrayList<String>();
		
		// has no params
		if(!CCalcCommon.isParOpen(aCursor.get(aEquation))) return rVal;
		
		aCursor.next();
		while(!aCursor.exceeds(aEquation) && !CCalcCommon.isParClose(aCursor.get(aEquation)))
		{
			rVal.add(getParamSubstring(aEquation, aCursor));
			if(aCursor.get(aEquation)==',') aCursor.next(); // XXX not really checking for ","
		}
		
		if(!CCalcCommon.isParClose(aCursor.get(aEquation))) throw new ParserException("The last char of the equation string was not a closed paranthesis (as required), char is "+aCursor.get(aEquation));
		aCursor.next();
		
		return rVal;
	}
}