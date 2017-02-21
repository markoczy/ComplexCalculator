package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import org.junit.Test;

import mkz.cc.arithmetic.parser.ArithmeticEquationParser;
import mkz.cc.core.debug.CCalcException;
import mkz.util.io.IO;

public class TestEquationParser
{

	@Test
	public void test()
	{
		ArithmeticEquationParser lParser = new ArithmeticEquationParser();
		
		try
		{
			// single value
			//
			Double lVal=lParser.parse("5");
			IO.dbOutD("5 = "+lVal);
			assertEquals(lVal, new Double(5));
			
			// simple addition
			//
			lVal=lParser.parse("5+1");
			IO.dbOutD("5+1 = "+lVal);
			assertEquals(lVal, new Double(6));
			
			// exponential
			//
			lVal=lParser.parse("5^2");
			IO.dbOutD("5^2 = "+lVal);
			assertEquals(lVal, new Double(25));
			// as function
			assertEquals(lVal, lParser.parse("exp(5,2)"));
			
			// 2 layer
			//
			lVal=lParser.parse("5*(1+5)");
			IO.dbOutD("5*(1+5) = "+lVal);
			assertEquals(lVal, new Double(30));
			// automultiply
			assertEquals(lVal, lParser.parse("5(1+5)"));
			assertEquals(lVal, lParser.parse("(1+5)5"));
			
			// more automuliply
			//
			lVal=lParser.parse("2exp(2,2)");
			IO.dbOutD("2exp(2,2) = "+lVal);
			assertEquals(lVal, new Double(8));
			assertEquals(lVal, lParser.parse("exp(2,2)2"));

			// 2 layer function call
			//
			lVal=lParser.parse("sum(exp(5,2),2,3,4)");
			IO.dbOutD("sum(exp(5,2),2,3,4) = "+lVal);
			assertEquals(lVal, new Double(34));
			
		}
		catch (CCalcException e)
		{
			IO.dbOutE(e);
			fail("CCalc Exception");
		}
	
	}

}
