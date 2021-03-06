package mkz.cc.launch;

import java.util.ArrayList;

import mkz.cc.ui.PlotterCommandLineDisp;

public class CCalcPlotterTrip
{
    private static final String ANSI_CLS = "\u001b[2J";
    private static final String ANSI_HOME = "\u001b[H";
	
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub

		double lXMin=-3.14;
		double lXMax=3.14;
		
		double lYMin=-1.1;
		double lYMax=1.1;
		
		boolean lTurn = false;
		int lStep=10;
		
		
		for(int i=0;i<1000;i++)
		{
			// Clear console
			System.out.print(ANSI_CLS + ANSI_HOME);
		    System.out.flush();
			
		    if(i%lStep==0)lTurn=!lTurn;
		    
		    if(lTurn)
		    {
		    	lYMin-=0.1;
		    	lYMax+=0.1;
		    }
		    else
		    {
		    	lYMin+=0.1;
		    	lYMax-=0.1;
		    }
		    
//		    lYMin=-1.1-(((double)(-5+(i%10)))/10);
//		    lYMax=1.1+(((double)(-5+(i%10)))/10);
//		    
			ArrayList<String> lPlot=PlotterCommandLineDisp.plot("sin", lXMin, lXMax, lYMin, lYMax);
			
			lXMin+=0.4;
			lXMax+=0.4;
			
			System.out.println();
			System.out.println("----------------------------------------------------------------------------------");
			System.out.println("Plot('sin',"+lXMin+","+lXMax+","+lYMin+","+lYMax);
			System.out.println("----------------------------------------------------------------------------------");
			System.out.println();
			
			for(String iLine:lPlot)System.out.println(iLine);
			
			System.out.println();
			System.out.println("----------------------------------------------------------------------------------");
			System.out.println();
			
			try
			{
				Thread.sleep(50);
			}
			catch (InterruptedException e)
			{
				e.printStackTrace();
			}
		}
		
	}

}
