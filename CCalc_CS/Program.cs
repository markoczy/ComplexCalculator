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
            
            //CEqParser parser;
            CCalc cc=new CCalc();

            int argc=args.Length;

	        if (argc == 1)
	        {
		        if (!cc.validate(args[0]))
		        {
			        Console.WriteLine("Error: Equation not valid");
			        return;
		        }
		
		        double d = cc.parse(args[0]);
                //std::cout.precision(15);

                string str = d.ToString();

                Clipboard.SetText("Test");
                Console.WriteLine(str);
                //std::cout<< finalVal << std::endl;
	        }
	        else
	        {
		        Console.WriteLine("Error: Argument count not matching: "+argc);
	        }



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
    }
}
