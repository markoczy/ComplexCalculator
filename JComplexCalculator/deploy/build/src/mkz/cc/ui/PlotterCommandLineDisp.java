package mkz.cc.ui;

import java.util.ArrayList;

import mkz.cc.arithmetic.ArithmeticEquationFactory;

public class PlotterCommandLineDisp
{
	private static final String LINE = "----------------------------------------------------------------------------------";
	private static final int GRID_WIDTH = LINE.length();
	private static final int GRID_HEIGHT = 20;
	
	
	public static ArrayList<String> plot(String aFunctionName,double xMin,double xMax,double yMin,double yMax)
	{
		ArithmeticPlotter lPlotter = new ArithmeticPlotter(GRID_WIDTH, GRID_HEIGHT);
		ArrayList<String> rVal = new ArrayList<String>();
		
		for(int i=0;i<GRID_HEIGHT;i++)
		{
			rVal.add(_getLine());
		}
		
		Integer lXZero = lPlotter.getXZero(xMin, xMax);
		Integer lYZero = lPlotter.getYZero(yMin, yMax);
		
		if(lXZero!=null)
		{
			for(int iLine=0;iLine<rVal.size();iLine++)
			{
				char[] lChrs=rVal.get(iLine).toCharArray();
				if(lXZero<=lChrs.length)lChrs[lXZero] = '|';
				rVal.set(iLine, new String(lChrs));
			}
		}
		
		if(lYZero!=null)
		{
			char[] lLine = LINE.toCharArray();
			if(lXZero!=null)lLine[lXZero]='+';
			
			rVal.set(GRID_HEIGHT-lYZero-1,new String(lLine));
		}
		
		ArrayList<Integer> lParams=lPlotter.plot(ArithmeticEquationFactory.createFuncionEquation(aFunctionName), xMin, xMax, yMin, yMax);
		for(int iParam=0;iParam<lParams.size();iParam++)
		{
			if(lParams.get(iParam)!=null)
			{
				char[] lChrs=rVal.get(GRID_HEIGHT-lParams.get(iParam)-1).toCharArray();
				lChrs[iParam]='+';
				rVal.set(GRID_HEIGHT-lParams.get(iParam)-1, new String(lChrs));
			} 
		}
		
		return rVal;
	}
	
	private static String _getLine()
	{
		StringBuilder rVal=new StringBuilder();
		
		for(int i=0;i<GRID_WIDTH;i++) rVal.append(" ");
		
		return rVal.toString();
	}
}
