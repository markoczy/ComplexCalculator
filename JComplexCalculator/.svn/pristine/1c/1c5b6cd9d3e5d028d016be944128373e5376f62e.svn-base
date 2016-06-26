package mkz.cc.test.arithmetic;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Test;

import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.core.parser.ParserCursor;
import mkz.cc.core.parser.ParserTools;
import mkz.util.io.IO;

@SuppressWarnings(value = { "all" })
public class TestParserTools
{

	@Test
	public void test()
	{
		
		try
		{
			// 1. Parse sub equations (inside "()")
			
			String sub=ParserTools.getEquationSubstring("(22+(22-1)*4+(32/4))", new ParserCursor());
			IO.dbOutD("Substring is: "+sub);
			assertEquals(sub,"22+(22-1)*4+(32/4)");
			
			// 2. Parse function calls
			
			String lEq = "func(exp(2-1,3),6,sin(22+4))+32";
			ParserCursor lPc = new ParserCursor();
			
			String lFcnName=ParserTools.parseIdentifier(lEq, lPc, false);
			IO.dbOutD("Function name is "+lFcnName);
			assertEquals(lFcnName,"func");

			ArrayList<String> lParams = ParserTools.getParamSubstrings(lEq, lPc);
			IO.dbOutD("Param 1: "+lParams.get(0));
			assertEquals(lParams.get(0),"exp(2-1,3)");
			
			IO.dbOutD("Param 2: "+lParams.get(1));
			assertEquals(lParams.get(1),"6");

			IO.dbOutD("Param 3: "+lParams.get(2));
			assertEquals(lParams.get(2),"sin(22+4)");
			
			IO.dbOutD("Current char = "+lPc.get(lEq));
			assertEquals('+',lPc.get(lEq));
			
		}
		catch (ParserException e)
		{
			IO.dbOutE(e);
			fail("Parser exception");
		}

	}

}
