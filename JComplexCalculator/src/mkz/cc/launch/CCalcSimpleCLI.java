/**
 * File: JComplexCalculator::CCalcSimpleCLI.java
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
package mkz.cc.launch;

import java.util.ArrayList;
import java.util.Scanner;

import mkz.cc.arithmetic.parser.ArithmeticEquationParser;
import mkz.cc.arithmetic.parser.ArithmeticFunctionParser;
import mkz.cc.core.debug.CCalcException;
import mkz.cc.ui.PlotterCommandLineDisp;
import mkz.cc.util.IO;

/**
 * The Class CCalcSimpleCLI.
 */
public class CCalcSimpleCLI
{

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args)
	{
		if(args.length>0)
		{
			if(args[0].startsWith("/"))
			{
				_parseArgument(args[0]);
				_initCLI();
			}
			else
			{
				String lCall = new String();
				
				for(String iArg:args)
				{
					lCall+=iArg;
				}
				lCall.replaceAll(" ", "");
				
				try
				{
					System.out.println("Output: "+new ArithmeticEquationParser().parse(lCall));
				}
				catch (CCalcException e)
				{
					IO.SysOutE(e);
				}
			}
		}
		else
		{
			_initCLI();
		}
	}
	
	/**
	 * [restricted] init command line interface.
	 */
	private static void _initCLI()
	{
		try
		{
			Scanner lScanner = new Scanner(System.in);
			ArithmeticEquationParser lEqParser = new ArithmeticEquationParser();
			ArithmeticFunctionParser lFcnParser = new ArithmeticFunctionParser();
			
			System.out.println();
			System.out.println("----------------------------------------------------------------------------------");
		    System.out.println("JComplexCalculator V0.81 (Simple test CLI)  Copyright (C) 2016  Aleistar Markoczy");
		    System.out.println("----------------------------------------------------------------------------------");
			System.out.println("This program comes with ABSOLUTELY NO WARRANTY; for details type '/show w'.");
			System.out.println("This is free software, and you are welcome to redistribute it");
			System.out.println("under certain conditions; type '/show c' for details.");
			System.out.println("----------------------------------------------------------------------------------");
		    System.out.println("Source code available at: https://github.com/markoczy/ComplexCalculator");
		    System.out.println("----------------------------------------------------------------------------------");
			System.out.println();
			System.out.println("NB: Type '/show h' or '/h' to get a list of available commands.");
			System.out.println();
			
			System.out.print("Input : ");
			String lInput = lScanner.nextLine();
			
			while(!lInput.toLowerCase().equals("/exit"))
			{
				try
				{
					if(lInput.startsWith("/")) _parseCommand(lInput);
					else if(lInput.contains(":="))
					{
						System.out.println(lFcnParser.parseFunction(lInput) ? ">>>>> : Succesfully added function." : ">>>>> : Error while adding function.");
						System.out.println();
					}
					else
					{
						double lVal=lEqParser.parse(lInput);
						System.out.println("Output: "+lVal);
						System.out.println();
					}
				}	
				catch (Exception e)
				{
					IO.SysOutE(e);
					System.out.println(">>>>> : An error occured ('/debug on' for more info)");
					System.out.println();
				}	
				
				System.out.print("Input : ");
				lInput=lScanner.nextLine();
			}
			
			lScanner.close();
		}
		catch (Exception lE)
		{
			IO.SysOutE(lE);
		}
		
	}
	
	private static void _parseCommand(String aCommand)
	{
		if(aCommand.toLowerCase().startsWith("/plot"))
		{
			_parsePlotCommand(aCommand);
			return;
		}
		
		if(aCommand.toLowerCase().startsWith("/debug"))
		{
			_parseDebugCommand(aCommand);
			return;
		}
		
		switch(aCommand.toLowerCase())
		{
			case "/h":
			case "/?":
			case "/help":
			case "/show h":
			case "/show help":
				_showHelp();
				break;
			
			case "/show w":
			case "/show warranty":
			case "/warranty":
				_showWarranty();
				break;
			case "/show c":
			case "/show conditions":
			case "/conditions":
				_showConditions();
				break;
			default:
				System.out.println(">>>>> : Command not found.");
				System.out.println();
				break;
		}
	}
	
	private static void _parseArgument(String aCommand)
	{
		switch(aCommand.toLowerCase())
		{
			case "/w":
			case "/warn":
			case "/warning":
				IO.setLogLevel(2);
				break;
			case "/d":
			case "/debug":
				IO.setLogLevel(3);
				break;
			case "/v":
			case "/verbose":
				IO.setLogLevel(4);
				break;
		}
	}
	
	private static void _parseDebugCommand(String aCommand)
	{
		//
		// Example: /plot f -10 10 -10 10
		//
		
		try
		{
			
			String[] lArgs=aCommand.split(" ");
			if(lArgs.length==2)
			{
				switch(lArgs[1].toLowerCase())
				{
					case "off":
					case "none":
					case "0":
						IO.setLogLevel(0);
						System.out.println(">>>>> : All outputs are deactivated.");
						System.out.println();
						break;
					case "error":
					case "err":
					case "e":
					case "1":
						IO.setLogLevel(1);
						System.out.println(">>>>> : Error logs are activated.");
						System.out.println();
						break;
					case "warning":
					case "warn":
					case "w":
					case "2":
						IO.setLogLevel(2);
						System.out.println(">>>>> : Warning logs are activated.");
						System.out.println();
						break;
					case "debug":
					case "d":
					case "on":
					case "3":
						IO.setLogLevel(3);
						System.out.println(">>>>> : Debug logs are activated.");
						System.out.println();
						break;
					case "verbose":
					case "all":
					case "v":
					case "4":
						IO.setLogLevel(4);
						System.out.println(">>>>> : Verbose logs are activated.");
						System.out.println();
						break;
				}
			}
		}
		catch (Exception e)
		{
			IO.SysOutE(e);
		}
		
	}
	
	
	private static void _parsePlotCommand(String aCommand)
	{
		//
		// Example: /plot f -10 10 -10 10
		//
		
		try
		{
			
			String[] lArgs=aCommand.split(" ");
			String lFcn=null;
			
			ArrayList<String> lPlot = null;
			Double lXmin=0.0,lXmax=0.0,lYmin=0.0,lYmax=0.0;
			
			switch(lArgs.length)
			{
				case 2:
					// show help
					if(lArgs[1].equals("h") || lArgs[1].equals("?"))
					{ 
						_showPlotterHelp();
						return;
					}
					lFcn=lArgs[1];
					lXmax=10.0;
					lXmin=-10.0;
					lYmax=10.0;
					lYmin=-10.0;
					lPlot=PlotterCommandLineDisp.plot(lFcn, lXmin, lXmax, lYmin, lYmax);
					break;
				case 3:
					lFcn=lArgs[1];
					lXmax=Double.parseDouble(lArgs[2]);
					lXmin=-lXmax;
					lYmax=lXmax;
					lYmin=lXmin;
					lPlot=PlotterCommandLineDisp.plot(lFcn, lXmin, lXmax, lYmin, lYmax);
					break;
				case 4:
					lFcn=lArgs[1];
					lXmin=Double.parseDouble(lArgs[2]);
					lXmax=Double.parseDouble(lArgs[3]);
					lYmax=lXmax;
					lYmin=lXmin;
					lPlot=PlotterCommandLineDisp.plot(lFcn, lXmin, lXmax, lYmin, lYmax);
					break;
				case 6:
					lFcn=lArgs[1];
					lXmin=Double.parseDouble(lArgs[2]);
					lXmax=Double.parseDouble(lArgs[3]);
					lYmin=Double.parseDouble(lArgs[4]);
					lYmax=Double.parseDouble(lArgs[5]);
					lPlot=PlotterCommandLineDisp.plot(lFcn, lXmin, lXmax, lYmin, lYmax);
					break;
			}
			
			
			if(lPlot!=null)
			{

				System.out.println();
				System.out.println("----------------------------------------------------------------------------------");
				System.out.println("Plot('"+lFcn+"',"+lXmin+","+lXmax+","+lYmin+","+lYmax+")");
				System.out.println("----------------------------------------------------------------------------------");
				System.out.println();
				
				for(String iLine:lPlot)System.out.println(iLine);
				
				System.out.println();
				System.out.println("----------------------------------------------------------------------------------");
				System.out.println();
				
			}

			
			
		}
		catch (Exception e)
		{
			IO.SysOutE(e);
		}
		
		
	}

	private static void _showWarranty()
	{
		System.out.println();
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("15. Disclaimer of Warranty.");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW.");
		System.out.println("EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES");
		System.out.println("PROVIDE THE PROGRAM �AS IS� WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR");
		System.out.println("IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY ");
		System.out.println("AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND ");
		System.out.println("PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ");
		System.out.println("ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.");
		System.out.println();
	}

	private static void _showConditions()
	{
		System.out.println();
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("2. Basic Permissions.");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("All rights granted under this License are granted for the term of copyright on");
		System.out.println("the Program, and are irrevocable provided the stated conditions are met. This");
		System.out.println("License explicitly affirms your unlimited permission to run the unmodified");
		System.out.println("Program. The output from running a covered work is covered by this License only if");
		System.out.println("the output, given its content, constitutes a covered work. This License ");
		System.out.println("acknowledges your rights of fair use or other equivalent, as provided by ");
		System.out.println("copyright law.");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("You may make, run and propagate covered works that you do not convey, without");
		System.out.println("conditions so long as your license otherwise remains in force. You may convey");
		System.out.println("covered works to others for the sole purpose of having them make modifications");
		System.out.println("exclusively for you, or provide you with facilities for running those works,");
		System.out.println("provided that you comply with the terms of this License in conveying all material");
		System.out.println("for which you do not control copyright. Those thus making or running the covered");
		System.out.println("works for you must do so exclusively on your behalf, under your direction and");
		System.out.println("control, on terms that prohibit them from making any copies of your copyrighted");
		System.out.println("material outside their relationship with you.");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("Conveying under any other circumstances is permitted solely under the conditions");
		System.out.println("stated below. Sublicensing is not allowed; section 10 makes it unnecessary.");
		System.out.println();
	}
	
	private static void _showHelp()
	{
		System.out.println();
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("JComplexCalculator :: Usage");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("1. Simple calulations");
		System.out.println();
		System.out.println("    Type the expression to calculate, e.g.: '1+2*sin(4)'");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("2. Function definitions");
		System.out.println();
		System.out.println("    Definitions are made with ':=', e.g.: 'f(x):=5x'");
		System.out.println("    Once defined they can be called as usual, e.g.: 'f(2)' (-> returns 10)");
		System.out.println();
		System.out.println("    NB: it is also possible to store variables, e.g.: 'a:=5'");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("3. Basic Commands");
		System.out.println();
		System.out.println("    '/debug [on|off]'                        en-/disables debug mode");
		System.out.println("    '/show h'                                show help (this text)");
		System.out.println("    '/show w'                                show warranty text");
		System.out.println("    '/show c'                                show conditions");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("4. Plotter");
		System.out.println();
		System.out.println("    Type '/plot h' to get additional info about plotter commands");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println();
		
	}
	
	private static void _showPlotterHelp()
	{
		System.out.println();
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("JComplexCalculator :: Plotter commands");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("1. Definition");
		System.out.println();
		System.out.println("    '/plot <function>'                       plot function with name <function>");
		System.out.println("                                             (function must use 1 param)");
		System.out.println();
		System.out.println("    '/plot <function> <max>'                 plot function with name <function>");
		System.out.println("                                             <max> defines grid extremas");
		System.out.println();
		System.out.println("    '/plot <function> <min> <max>'           plot function with name <function>");
		System.out.println("                                             <min> defines grid min");
		System.out.println("                                             <max> defines grid max");
		System.out.println();
		System.out.println("    '/plot <function> <xmin> <xmax> ..       plot function with name <function>");
		System.out.println("                      <ymin> <ymax>'         <xmin> defines grid xmin");
		System.out.println("                                             <xmax> defines grid xmax");
		System.out.println("                                             <ymin> defines grid ymin");
		System.out.println("                                             <ymax> defines grid ymax");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println("2. Example usage");
		System.out.println();
		System.out.println("    Using the built-in function 'sin' we can type our plot command as follows:");
		System.out.println();
		System.out.println("    CMD: '/plot sin -3.14 3.14 -1.1 1.1' --> Try it out!");
		System.out.println("----------------------------------------------------------------------------------");
		System.out.println();
	}
	
}
