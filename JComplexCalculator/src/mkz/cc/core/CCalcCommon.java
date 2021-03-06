/**
 * File: JComplexCalculator::CCalcCommon.java
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
package mkz.cc.core;

/**
 * The Class CCalcCommon. All common static methods related to the complex calc.
 */
public class CCalcCommon 
{
	/** The Constant DECIMALS. */
	static final char[] DECIMALS = {'0','1','2','3','4','5','6','7','8','9','0','.'};
	
	/** The Constant OPS. */
	static final char[] OPS = {'+','-','*','/','^','&','|'}; // TODO outsource..
	
	/** The Constant ALPHAS. */
	static final char[] ALPHAS = {	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
									'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_'};
	
	/**
	 * Checks if is par open.
	 *
	 * @param chr the chr
	 * @return true, if is par open
	 */
	public static boolean isParOpen(char chr)
	{
		return chr == '(';
	}

	/**
	 * Checks if is par close.
	 *
	 * @param chr the chr
	 * @return true, if is par close
	 */
	public static boolean isParClose(char chr)
	{
		return chr == ')';
	}
	
	/**
	 * Checks if is decimal.
	 *
	 * @param chr the chr
	 * @return true, if is decimal
	 */
	public static boolean isDecimal(char chr)
	{
		for(char c : DECIMALS)
		{
			if(c==chr)
			{
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Checks if is alpha.
	 *
	 * @param chr the chr
	 * @return true, if is alpha
	 */
	public static boolean isAlpha(char chr)
	{
		for(char c : ALPHAS)
		{
			if(c==chr)
			{
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Checks if is operator.
	 *
	 * @param chr the chr
	 * @return true, if is operator
	 */
	public static boolean isOperator(char chr)
	{
		for(char c : OPS)
		{
			if(c==chr)
			{
				return true;
			}
		}
		return false;
	}

	/**
	 * Parses the paranthesis.
	 *
	 * @param chr the chr
	 * @return the int
	 */
	public static int parseParanthesis(char chr)
	{
		if (isParOpen(chr))
		{
			return 1;
		}
		else if (isParClose(chr))
		{
			return -1;
		}
	
		return 0;
	}
	
	/**
	 * Checks if is fcn def op.
	 *
	 * @param chr1 the chr1
	 * @param chr2 the chr2
	 * @return true, if is fcn def op
	 */
	public static boolean isFcnDefOp(char chr1, char chr2)
	{
		if (chr1 == ':')
		{
			return chr2 == '=';
		}

		return false;
	}
	//

	/**
	 * Checks if is fcn def eq.
	 *
	 * @param eq the eq
	 * @return true, if is fcn def eq
	 */
	public static boolean isFcnDefEq(String eq)
	{
		if (eq.length() == 0) return false;

		for (int i = 0; i < eq.length() - 1; i++)
		{
			if (eq.charAt(i) == ':')
			{
				if (eq.charAt(i + 1) == '=') return true;
			}

		}

		return false;

	}
	
}
