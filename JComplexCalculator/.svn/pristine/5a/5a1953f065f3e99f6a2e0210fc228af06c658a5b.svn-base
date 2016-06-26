package mkz.cc.test.ui;

import java.util.ArrayList;

import mkz.cc.arithmetic.ArithmeticEquationFactory;
import mkz.cc.arithmetic.parser.ArithmeticFunctionParser;
import mkz.cc.core.debug.parser.ParserException;
import mkz.cc.ui.ArithmeticPlotter;
import mkz.cc.ui.PlotterCommandLineDisp;
import mkz.util.io.IO;

public class TestPlotter
{

	public static void main(String[] args)
	{
		ArithmeticPlotter lPlotter = new ArithmeticPlotter(20,20);
		
		ArithmeticFunctionParser lParser=new ArithmeticFunctionParser();
		
		try
		{
			lParser.parseFunction("f(x):=x");
			ArrayList<Integer> lParams=lPlotter.plot(ArithmeticEquationFactory.createFuncionEquation("f"), -10, 10, -10, 10);
			
			for(Integer iParam:lParams)
			{
				System.out.println("Value: "+iParam);
			}
			
			System.out.println("----------------------------------------------------------------------------------");
			System.out.println();
			PlotterCommandLineDisp.plot("sin", -3.14, 3.14, -1.1, 1.1);
			System.out.println();
			System.out.println("----------------------------------------------------------------------------------");
			System.out.println();
			PlotterCommandLineDisp.plot("f", -10, 0, -10, 0);
			System.out.println();
			System.out.println("----------------------------------------------------------------------------------");
		}
		catch (ParserException e)
		{
			IO.dbOutE(e);
		}
	}

}
