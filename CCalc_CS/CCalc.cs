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
        private const string LOCAL_VERSION = "0.1.0";
        private const int VERSION_STRLEN = 10;
        private const int ERROR_STRLEN = 128;
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

        #region Use
        public bool validate(string stmt) 
        {
            return DLL.ccalc_validate(cc,stmt);
        }

        public double parse(string stmt)
        {
            return DLL.ccalc_parse(cc, stmt);
        }
        #endregion

        #region DLL
        private class DLL
        {

            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern string ccalc_getVersion(StringBuilder aVersion);

            #region De / -Init
            //-//-//
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern IntPtr ccalc_create();
            //
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void ccalc_destroy(IntPtr cc);
            //-//-//
            #endregion

            #region Open / Close DB
            //-//-//
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern bool ccalc_validate(IntPtr cc, string stmt);
            //
            [DllImport("lib\\ccalc.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern double ccalc_parse(IntPtr cc, string stmt);
            //-//-//
            #endregion


        }

        #endregion

    }
}
