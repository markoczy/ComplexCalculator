using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;

namespace CCalc_CS
{
    class Program
    {


        [STAThreadAttribute]
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.GetCultureInfo("en-US");


            initCLI();

            ////CEqParser parser;
            //CCalc cc=new CCalc();

            //if (cc.matchDllVersion())
            //{
            //    Console.WriteLine("Version match, Version is " + cc.getApiVersion());
            //}
            //else
            //{
            //    Console.WriteLine("Warning: No version match, CS_API is V" + cc.getApiVersion()+",  DLL is V"+cc.getDllVersion());
            //}

            //int argc=args.Length;

            //if (argc == 1)
            //{
            //    if (!cc.validate(args[0]))
            //    {
            //        Console.WriteLine("Error: Equation not valid");
            //        return;
            //    }
		
            //    //double d = cc.parse(args[0]);
            //    double d = 0;
            //    int rVal = cc.parse(args[0],out d);
            //    //std::cout.precision(15);

            //    string str = d.ToString();
            //    Clipboard.SetText("Test");
            //    Console.WriteLine("Value = "+str);

            //    string ret = cc.getReturnString(rVal);
            //    Console.WriteLine("Retcode = "+ret);
            //    //std::cout<< finalVal << std::endl;
            //}
            //else
            //{
            //    Console.WriteLine("Error: Argument count not matching: "+argc);
            //}



            //string stmt="2+4";
            //Console.WriteLine("Parsing: "+stmt);

            //if (cc.validate(stmt))
            //{
            //    Console.WriteLine("Statement valid");
            //}
            //else
            //{
            //    Console.WriteLine("Statement not valid");
            //}

            //double val = cc.parse(stmt);
            //Console.WriteLine("Value is: "+val);

            //Console.WriteLine("\nPress <ENTER> to exit...");
            //Console.ReadLine();
            
        }


        private static void initCLI()
        {
            CCalc cc = new CCalc();

            Console.WriteLine("+----------------------------------------------------------+");
	        Console.WriteLine("|  ComplexCalculator V"+cc.getApiVersion()+" (CS test CLI)   Author: A.M.   |");
	        Console.WriteLine("|                                                          |");
	        Console.WriteLine("|  Source: https://github.com/markoczy/ComplexCalculator   |");
	        Console.WriteLine("+----------------------------------------------------------+");
	        Console.WriteLine();


	        string input = "";
            while (!input.ToUpper().Equals("/EXIT"))
            {
                Console.Write("Input : ");
                input = Console.ReadLine();
                
                if (!string.IsNullOrEmpty(input) && !(input[0] == '/'))
                {
                    double val = 0;
                    int rVal = 0;
                    rVal = cc.parse(input, out val);

                    if (rVal == (int)CC_RET.OK_CREATED_FUNCTION)
                    {
                        Console.WriteLine(">>>>> : Succesfully added function\n");
                    }
                    else if (rVal == (int)CC_RET.OK_PARSED_EQUATION)
                    {
                        Console.WriteLine("Output: " + val + "\n");
                    }
                    else
                    {
                        string errStr = cc.getReturnString(rVal);

                        Console.WriteLine(">>>>> : Error while parsing: " + errStr + "\n");
                    }

                }

            }

	        Console.WriteLine("Exit called, press <ENTER> to quit.");

        }

    }
}
