using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CCalc_CS
{
    class Program
    {
        static void Main(string[] args)
        {
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
		
		        double finalVal = cc.parse(args[0]);
                //std::cout.precision(15);

                Console.WriteLine(finalVal.ToString());
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
