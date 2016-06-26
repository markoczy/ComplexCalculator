package mkz.cc.test.logical;

import mkz.cc.logical.parser.LogicalEquationParser;
import mkz.util.io.IO;

public class TestParser
{

	public static void main(String[] args)
	{
		try
		{
			LogicalEquationParser lParser = new LogicalEquationParser();
			System.out.println("1&!(0|1) = "+lParser.parse("1&!(0|1)"));
			System.out.println("1&1 = "+lParser.parse("1&1"));
			System.out.println("12&0 = "+lParser.parse("12&0"));
			System.out.println("true|false = "+lParser.parse("true|false"));
			System.out.println("true&false = "+lParser.parse("true&false"));
		}
		catch (Exception lE)
		{
			IO.dbOutE(lE);
		}
		
	}

}
