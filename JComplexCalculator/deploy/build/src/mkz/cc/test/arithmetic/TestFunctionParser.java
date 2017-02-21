package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import org.junit.Test;

import mkz.cc.arithmetic.parser.ArithmeticEquationParser;
import mkz.cc.arithmetic.parser.ArithmeticFunctionParser;
import mkz.cc.core.debug.CCalcException;
import mkz.util.io.IO;

@SuppressWarnings(value = { "all" })
public class TestFunctionParser
{

	@Test
	public void test()
	{
		IO.Options.log_level=4;
		
		ArithmeticFunctionParser lFcnParser = new ArithmeticFunctionParser();
		ArithmeticEquationParser lEqParser = new ArithmeticEquationParser();
		
		try
		{
			System.out.println("---------------------------------------------------------------------");
			lFcnParser.parseFunction("f(c):=22*c");
			Double v1 = lEqParser.parse("f(3)");
			IO.dbOutD("f(3)= "+v1);
			assertEquals(new Double(66),v1);
			
			System.out.println("---------------------------------------------------------------------");
			Double v2 = lEqParser.parse("f(1+2)");
			IO.dbOutD("f(1+2)= "+v2);
			assertEquals(new Double(66),v2);
			
			// 2*22^2
			System.out.println("---------------------------------------------------------------------");
			Double v3 = lEqParser.parse("f(f(2))");
			IO.dbOutD("f(f(2))= "+v3);
			assertEquals(new Double(968),v3);
			
			
			System.out.println("---------------------------------------------------------------------");
			IO.dbOutD("parsing: newexp(base,val):=exp(base,val)");
			lFcnParser.parseFunction("newexp(base,val):=exp(base,val)");
			IO.dbOutD("parsing: newexp(2,3)");
			Double v4 = lEqParser.parse("newexp(2,3)");
			IO.dbOutD("newexp(2,3)= "+v4);
			assertEquals(new Double(8),v4);
			
			// XXX could do more...
		}
		catch (CCalcException e)
		{
			IO.dbOutE(e);
			fail("CCalcException");
		}
	}

}
