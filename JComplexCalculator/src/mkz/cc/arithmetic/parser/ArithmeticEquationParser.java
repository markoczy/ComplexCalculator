/**
 * File: JComplexCalculator::ArithmeticEquationParser.java
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
package mkz.cc.arithmetic.parser;

import java.util.ArrayList;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.arithmetic.equation.LinearArithmeticEquation;
import mkz.cc.core.CCalcCommon;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.parser.ParserCursor;
import mkz.cc.core.parser.ParserTools;
import mkz.cc.util.IO;

/**
 * The Class EquationParser.
 */
public class ArithmeticEquationParser
{
	/** The member cursor. */
	protected ParserCursor mCursor = new ParserCursor();
	
	/**
	 * Parses the equation string.
	 *
	 * @param equation the equation
	 * @return the double
	 * @throws CCalcException the c calc exception
	 */
	// Parses double value from equation
	public Double parse(String equation) throws CCalcException
	{
		// deinit first..
		mCursor.setPosition(0);
		
		
		IEquation<Double> eq = _parseEquation(equation, mCursor);
		Double rVal = eq.getValue();

		return rVal;
	}

	/**
	 * [restricted] parse equation.
	 *
	 * @param equation the equation
	 * @param aCursor the reference cursor
	 * @return the i equation
	 */
	protected IEquation<Double> _parseEquation(String equation, ParserCursor aCursor) throws ParserException
	{
		LinearArithmeticEquation rVal = _getNewEquation();

		IEquation<Double> lNumber = null;

		boolean hasNum = false;
		boolean hasOp = false;

		boolean inverseNum = false;

		char chr = equation.charAt(aCursor.getPosition());

		while (aCursor.getPosition() < equation.length())
		{
			chr = equation.charAt(aCursor.getPosition());
			IO.SysOutV("it = " + aCursor + ", char = " + chr);

			Operation lOperation = Operation.UNDEF;

			if (CCalcCommon.isDecimal(chr))
			{
				IO.SysOutV("Found decimal: " + chr);
				lNumber = new Constant<Double>(ParserTools.parseNumber(equation, aCursor));
			}
			else if (CCalcCommon.isParOpen(chr))
			{
				String sub = ParserTools.getEquationSubstring(equation, aCursor);
				IO.SysOutV("Found subEquation " + sub);

				ParserCursor subCursor = new ParserCursor(); // dummy
				lNumber = _parseEquation(sub, subCursor);
			}
			else if (CCalcCommon.isAlpha(chr))
			{
				IO.SysOutV("Found alpha " + chr);
				lNumber=_parseFunctionCall(equation, aCursor);
			}
			else if (CCalcCommon.isOperator(chr))
			{
				lOperation = _parseOperator(equation, aCursor);
			}
			else
			{
				aCursor.next();;
			}

			hasNum = (lNumber != null);
			hasOp = (lOperation != Operation.UNDEF);

			IO.SysOutV("hasOp = " + hasOp + " hasNum = " + hasNum);

			if (hasNum)
			{
				boolean doAdd = false;

				// Has Number and Operator
				if (hasOp)
				{
					doAdd = true;
				}
				// Default Operator "CONST" if finished
				else if (aCursor.getPosition() >= equation.length())
				{
					lOperation = Operation.CONST;
					
					doAdd = true;
				}
				// Default Operator "MPL" if undefined
				else
				{
					chr = equation.charAt(aCursor.getPosition());

					// Subequation e.g. 4(2+3)
					//                   ^
					doAdd |= CCalcCommon.isParOpen(chr);

					// Function e.g. 4x
					//                ^
					doAdd |= CCalcCommon.isAlpha(chr);

					// Decimal e.g. (2+3)4
					//                   ^
					doAdd |= CCalcCommon.isDecimal(chr);

					if (doAdd)
					{
						IO.SysOutV("Adding auto "+Operation.MPL+" char is: " + chr);
						lOperation = Operation.MPL;
					}
				}

				if (doAdd)
				{
					if (inverseNum) lNumber = ArithmeticEquationFactory.createInversion(lNumber);

					IO.SysOutV("Adding Operation " + lOperation);
					rVal.addOperation(lNumber, lOperation);
					lOperation = Operation.UNDEF;
					lNumber = null;
					//
					hasNum = false;
					hasOp = false;
					inverseNum = false;
				}

			}
			// Inverse negative
			else
			{
				if (lOperation == Operation.SUB)
				{
					IO.SysOutV("Setting inversenum = true");
					inverseNum = true;
				}

			}

		}

		if (hasNum)
		{
			if (inverseNum) lNumber = ArithmeticEquationFactory.createInversion(lNumber);

			IO.SysOutV("Adding Operation (end) " + Equation.DisplayNames.INV);
			rVal.addOperation(lNumber, Operation.CONST);
		}

		IO.SysOutV("Returning equation, it = " + aCursor);
		return rVal;
	}

	/**
	 * [restricted] parse operator.
	 *
	 * @param equation the equation
	 * @param aCursor the reference cursor
	 * @return the operation
	 */
	protected Operation _parseOperator(String equation, ParserCursor aCursor)
	{
		char chr = aCursor.getPosition() < equation.length() ? equation.charAt(aCursor.getPosition()) : '\0';
		aCursor.next();;

		IO.SysOutD("OperatorString = " + chr);

		switch (chr)
		{
			case '+':
				return Operation.ADD;
			case '-':
				return Operation.SUB;
			case '/':
				return Operation.DIV;
			case '*':
				return Operation.MPL;
			case '^':
				return Operation.EXP;
			default:
				return Operation.UNDEF;
		}

	}

	/**
	 * _parse function call.
	 *
	 * @param equation the equation
	 * @param aCursor the reference cursor
	 * @return the i equation
	 */
	protected IEquation<Double> _parseFunctionCall(String equation, ParserCursor aCursor) throws ParserException
	{
		String fcnName = ParserTools.parseIdentifier(equation, aCursor,false);
		
		Equation<Double> lFcn = ArithmeticEquationFactory.createFuncionEquation(fcnName);
		
		if(lFcn!=null)
		{
			IO.SysOutV("Found function, name is "+fcnName);
			ArrayList<String> lParamStrs = ParserTools.getParamSubstrings(equation, aCursor);
			for(String iParamStr:lParamStrs) lFcn.addParam(_parseEquation(iParamStr,new ParserCursor()));
		}
		else throw new ParserException("Called a function that was not found in library, name is: "+fcnName);
		
		return lFcn;
	}

	/**
	 * [restricted] get new equation. Can be used to override datatype.
	 *
	 * @return the linear equation
	 */
	protected LinearArithmeticEquation _getNewEquation()
	{
		return new LinearArithmeticEquation();
	}

}