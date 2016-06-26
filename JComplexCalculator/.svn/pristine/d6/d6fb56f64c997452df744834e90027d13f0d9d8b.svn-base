package mkz.cc.ui;

import java.util.ArrayList;
import mkz.cc.core.equation.Constant;
import mkz.cc.core.equation.Equation;
import mkz.cc.core.equation.definition.IEquation;

public class ArithmeticPlotter
{
	private int mWidth=0;
	private int mHeight=0;
	
	public ArithmeticPlotter(int aWidth,int aHeight)
	{
		mWidth=aWidth;
		mHeight=aHeight;
	}
	
	public ArrayList<Integer> plot(Equation<Double> aEquation,double xMin,double xMax,double yMin,double yMax)
	{
		ArrayList<Integer> rVal = new ArrayList<Integer>();
		
		for(int i=0;i<mWidth;i++)
		{
			ArrayList<IEquation<Double>>lParams=new ArrayList<IEquation<Double>>();
			lParams.add(new Constant<Double>(_xToDouble(i,xMin,xMax)));
			aEquation.setParams(lParams);
			rVal.add(_yToInt(aEquation.getValue(),yMin,yMax));
		}
		
		return rVal;
	}
	
	public Integer getXZero(double xMin,double xMax)
	{
		if(0<xMin||0>xMax) return null;
		
		return _xToInt(0.0,xMin,xMax);
	}
	
	public Integer getYZero(double yMin,double yMax)
	{
		if(0<yMin||0>yMax) return null;
		
		return _yToInt(0.0,yMin,yMax);
	}
	
	private Double _xToDouble(int aX,double xMin, double xMax)
	{
		double lStep = (xMax-xMin)/(mWidth-1);
		return xMin+(lStep*aX);
	}
	
	private Integer _yToInt(Double aY,double yMin, double yMax)
	{
		if(aY==null) return null;
		if(aY<yMin || aY>yMax) return null;

		return (int)Math.round((aY-yMin)*((double)(mHeight-1)/(yMax-yMin)));
	}
	
	private Integer _xToInt(Double aY,double xMin, double xMax)
	{
		if(aY==null) return null;
		if(aY<xMin || aY>xMax) return null;

		return (int)Math.round((aY-xMin)*((double)(mWidth-1)/(xMax-xMin)));
	}
	
}
