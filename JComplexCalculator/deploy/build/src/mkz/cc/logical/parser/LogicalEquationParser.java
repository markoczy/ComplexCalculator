package mkz.cc.logical.parser;

import mkz.cc.arithmetic.ConstantsArithmetic;
import mkz.cc.core.CCalcCommon;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Operation;
import mkz.cc.core.equation.definition.IEquation;
import mkz.cc.core.parser.ParserCursor;
import mkz.cc.core.parser.ParserTools;
import mkz.cc.logical.ConstantsLogical;
import mkz.cc.logical.LogicalEquationFactory;
import mkz.cc.logical.LogicalOperation;
import mkz.cc.logical.equation.LinearLogicalEquation;
import mkz.util.io.IO;

public class LogicalEquationParser
{
	/** The member cursor. */
	protected ParserCursor mCursor = new ParserCursor();
	
	private static final char[] OPERATION_CHARS=new char[]{'&','|','*','+'};

	public boolean parse(String aEquation) throws CCalcException
	{
		mCursor = new ParserCursor();
		IEquation<Boolean> eq = _parseEquation(aEquation, mCursor);
		Boolean rVal = eq.getValue();

		return rVal;
	}
	
	protected IEquation<Boolean> _parseEquation(String aEquation, ParserCursor aCursor) throws ParserException
	{
		LinearLogicalEquation rVal = _getNewEquation();
		IEquation<Boolean> lNumber = null;
		
		boolean hasNum = false;
		boolean hasOp = false;

		boolean inverseNum = false;

		while (!aCursor.exceeds(aEquation))
		{
			char chr = aCursor.get(aEquation);
			IO.dbOutV("it = " + aCursor + ", char = " + chr);
			
			Operation lOperation = ConstantsLogical.Operations.UNDEF;
			
			if (CCalcCommon.isDecimal(chr))
			{
				IO.dbOutV("Found decimal: " + chr);
				lNumber = new Constant<Boolean>(ParserTools.parseNumber(aEquation, aCursor)!=0);
			}
			else if (CCalcCommon.isParOpen(chr))
			{
				String sub = ParserTools.getEquationSubstring(aEquation, aCursor);
				IO.dbOutV("Found subEquation " + sub);

				ParserCursor subCursor = new ParserCursor(); // dummy
				lNumber = _parseEquation(sub, subCursor);
			}
			else if (CCalcCommon.isAlpha(chr))
			{
				IO.dbOutV("Found alpha " + chr);
				lNumber=_parseAlphabetic(aEquation, aCursor);
			}
			else if (_isOperator(chr))
			{
				lOperation = _parseOperator(aEquation, aCursor);
			}
			else if(chr=='!' || chr=='-')
			{
				inverseNum=true;
				aCursor.next();;
			}
			else
			{
				aCursor.next();
			}
			
			hasNum = (lNumber != null);
			hasOp = (lOperation != ConstantsLogical.Operations.UNDEF);

			IO.dbOutV("hasOp = " + hasOp + " hasNum = " + hasNum);

			if (hasNum)
			{
				boolean doAdd = false;

				// Has Number and Operator
				if (hasOp)
				{
					doAdd = true;
				}

				if (doAdd)
				{
					if (inverseNum) lNumber = _getInversion(lNumber);

					IO.dbOutV("Adding Operation " + lOperation);
					rVal.addOperation(lNumber, lOperation);
					lOperation = ConstantsArithmetic.Operations.UNDEF;
					lNumber = null;
					//
					hasNum = false;
					hasOp = false;
					inverseNum = false;
				}

			}
			
		}

		if (hasNum)
		{
			if (inverseNum) lNumber = _getInversion(lNumber);

			IO.dbOutV("Adding Operation (end) " + ConstantsArithmetic.Operations.CONST);
			rVal.addOperation(lNumber, ConstantsArithmetic.Operations.CONST);
		}

		IO.dbOutV("Returning equation, it = " + aCursor);
		return rVal;
	}
	
	protected boolean _isOperator(char aChar)
	{
		for(char iOp:OPERATION_CHARS)
		{
			if(iOp==aChar) return true;
		}
		
		return false;
	}
	
	protected LogicalOperation _parseOperator(String equation, ParserCursor aCursor)
	{
		char chr = aCursor.getPosition() < equation.length() ? equation.charAt(aCursor.getPosition()) : '\0';
		aCursor.next();

		IO.dbOutD("OperatorString = " + chr);

		switch (chr)
		{
			case '&':
			case '*':
				return ConstantsLogical.Operations.AND;
			case '|':
			case '+':
				return ConstantsLogical.Operations.OR;
			default:
				return ConstantsLogical.Operations.UNDEF;
		}

	}
	
	protected IEquation<Boolean> _getInversion(IEquation<Boolean> aEquation)
	{
		return LogicalEquationFactory.createInversion(aEquation);
	}
	
	protected LinearLogicalEquation _getNewEquation()
	{
		return new LinearLogicalEquation();
	}
	
	protected IEquation<Boolean> _parseAlphabetic(String equation, ParserCursor aCursor) throws ParserException
	{
		String lName = ParserTools.parseIdentifier(equation, aCursor,false);
		
		if(lName.toLowerCase().equals("false") || lName.toLowerCase().equals("f"))return new Constant<Boolean>(false);
		if(lName.toLowerCase().equals("true") || lName.toLowerCase().equals("t"))return new Constant<Boolean>(true);
		
		IO.dbOutE("Could not t/f value, string is: "+lName);
		return null;
	}
}
