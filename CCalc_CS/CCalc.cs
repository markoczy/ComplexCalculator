using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CCalc_CS
{
    class CCalc
    {

        #region Locals
        private const string CC_VERSION = "0.6.1";
        //
        IntPtr cc;
        #endregion

        #region ConDes
        //
        public CCalc() 
        {
            cc = DLL.ccalc_create();
        }
        //
        ~CCalc()
        {
            DLL.ccalc_destroy(cc);
        }
        //
        #endregion

        public string getApiVersion()
        {
            return CC_VERSION;
        }

        public string getDllVersion() 
        {
            // Get Length
            int strLen = DLL.ccalc_getVersion();

            // Get String
            StringBuilder sb = new StringBuilder(strLen);
            DLL.ccalc_getVersion(sb);

            return sb.ToString();
        
        }


        public bool matchDllVersion() 
        {
            string dllVer = this.getDllVersion();

            return dllVer.Equals(CC_VERSION);

        }

        #region Use
        public bool validate(string stmt) 
        {
            //return DLL.ccalc_validate(cc,stmt);
            return true;
        }

        public int parse(string stmt, out double val)
        {
            val = 0;
            return DLL.ccalc_parse(cc, stmt, ref val);
        }
        #endregion


        public string getReturnString(int retCode) 
        {
            // Get Length
            int strLen = DLL.ccalc_getReturnString(retCode);

            // Get String
            StringBuilder sb = new StringBuilder(strLen);
            DLL.ccalc_getReturnString(retCode,sb);

            return sb.ToString();
        }

        public bool isSuccess(int retCode)
        {
            return DLL.ccalc_isSuccess(retCode);
        }

        #region DLL
        private class DLL
        {
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int ccalc_getVersion(StringBuilder aVersion = null);

            #region De / -Init
            //-//-//
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr ccalc_create();
            //
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void ccalc_destroy(IntPtr cc);
            //-//-//
            #endregion

            #region Validate / Parse
            //-//-//
            //[DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            //public static extern bool ccalc_validate(IntPtr cc, string stmt);
            //
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int ccalc_parse(IntPtr cc, string stmt, ref double aVal);
            //-//-//
            #endregion

            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int ccalc_getReturnString(int retCode, StringBuilder retStr = null);

            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool ccalc_isSuccess(int retCode);
            

        }
        #endregion

        




    }

    #region RetCodes
    public enum CC_RET
    {
        ///////////////////////////////////////////////////
        //// Happy Cases: 0 <= x < 100
        ///////////////////////////////////////////////////
        //
        OK_GENERAL = 0,
        //
        OK_PARSED_EQUATION = 1,
        //
        OK_CREATED_FUNCTION = 2,

        ///////////////////////////////////////////////////
        //// Software Errors
        ///////////////////////////////////////////////////
        //
        NOK_BAD_INIT = 110,
        //
        NOK_VAR_UNSET = 111,
        //
        NOK_PARAMCOUNT_LOW = 112,
        //
        NOK_PARAMCOUNT_HIGH = 113,
        //
        NOK_FCNREF_UNSET = 114,



        ///////////////////////////////////////////////////
        //// Parsing Errors: 1000 <= x < 2000
        ///////////////////////////////////////////////////
        //
        //
        /////////////////////////////////
        // General: 1100 <= x < 1200 
        /////////////////////////////////
        //
        NOK_BAD_CHAR = 1000,
        //
        NOK_CLOSED_PARANTHESIS = 1001,
        //
        NOK_OPENED_PARANTHESIS = 1002,
        //
        /////////////////////////////////
        // Equation: 1100 <= x < 1200 
        /////////////////////////////////
        //
        NOK_EQ_FCNNAME_NOTFOUND = 1100,
        //
        NOK_EQ_FCNPARAMCOUNT_LOW = 1101,
        //
        NOK_EQ_FCNPARAMCOUNT_HIGH = 1102,
        //
        /////////////////////////////////
        // Function: 1200 <= x < 1300 
        /////////////////////////////////
        //
        NOK_FCN_NAME_EXISTS = 1200,
        //
        NOK_FCN_PARAMCOUNT_LOW = 1201,
        //
        NOK_FCN_PARAMCOUNT_HIGH = 1202,




    };
    #endregion
}
