using CCalc_CS;
using CCalc_GUI.Utility;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CCalc_GUI.GFX
{
    class CC_Renderer
    {
        // Not Reset
        private Panel mPanel;
        private Graphics mGfx;

        
        // Test __
        CCalc mCC ;//= new CCalc();
        bool hasFunction = false;
        // __ Test


        // Reset on every Render
        double mX0,mX1,mY0,mY1;

        public void Init(ref Panel aPanel)
        {
            mPanel = aPanel;
            mGfx = mPanel.CreateGraphics();
            mCC = new CCalc();
        }

        public String SetFunction(string function)
        {
            double dmy;
            mCC.deleteFunction("f");
            int rVal=mCC.parse(function,out dmy);
            
            if(mCC.isSuccess(rVal))hasFunction = true;

            double val;
            mCC.parse("f(2)",out val);

            //Console.WriteLine("f(2) = "+val);
            return mCC.getReturnString(rVal);
        }

        public void Render(double xMin,double xMax, double yMin, double yMax) 
        {
            mGfx.Clear(Color.White);

            // Set the bounds for rendering
            mX0 = xMin; mX1 = xMax; mY0 = yMin; mY1 = yMax;

            drawGrid();

            if (hasFunction) 
            {
                drawFunction();
            }

            //Console.WriteLine("Rendering...");
            //Console.WriteLine("Width = "+mPanel.Width);
            //Pen myPen = new Pen(System.Drawing.Color.Red, 5);

            //Rectangle myRectangle = new Rectangle(20, 20, 250, 200);

            //mGfx.DrawRectangle(myPen, myRectangle);
        }

        private void drawGrid() 
        {
            Pen lPen = new Pen(Color.Black, 1);

            int v;

            // Draw Line X=0
            if (valToPx_X(0, out v))
            {
                Point p1=new Point(v,0);
                Point p2=new Point(v,mPanel.Height);

                mGfx.DrawLine(lPen, p1, p2);
            }

            // Draw Line Y=0
            if (valToPx_Y(0, out v))
            {
                int w = mPanel.Width;
                
                Point p1 = new Point(0, v);
                //Console.WriteLine("Width = " + mPanel.Width);
                Point p2 = new Point(w, v);

                //Console.WriteLine("p1 = [" + p1.X + "," + p1.Y + "]");
                //Console.WriteLine("p2 = [" + p2.X + "," + p2.Y + "]");
                
                mGfx.DrawLine(lPen, p1, p2);
            }
            
        }

        private void drawFunction()
        {
            Brush lBrush = new SolidBrush(Color.Red);
            Pen lPen = new Pen(Color.Red);

            //int lastY = 0;
            //bool connect = false;

            for (int xPx = 0; xPx < mPanel.Width; xPx++)
            {
                double x = 0;
                double y = 0;
                pxToVal_X(xPx, out x);

                StringBuilder sb = new StringBuilder();
                sb.Append("f(");
                sb.Append(x);
                sb.Append(")");

                string stmt = sb.ToString();

                //Console.WriteLine("stmt equals " + stmt);
                int ret=mCC.parse(stmt, out y);

                //Console.WriteLine("value returns: "+mCC.getReturnString(ret));

                //Console.WriteLine("y equals "+y);

                int yPx=0;

                if (valToPx_Y(y, out yPx)) 
                {
                    try
                    {
                        //mGfx.FillRectangle(lBrush, xPx, yPx, 1, 1);

                        //// Verify if connector needed
                        //connect &= lastY - yPx > 1 || yPx - lastY > 1;

                        //if (connect)
                        //{
                        //    mGfx.DrawLine(lPen, new Point(xPx - 1, lastY), new Point(xPx, yPx - 1));
                        //}


                        //lastY = yPx;
                        //connect = true;
                    }
                    catch 
                    {
                        //connect = false;
                    }
                }



            }


        }

        private bool valToPx_X(double x, out int px)
        {
            px = 0;

            if (x < mX0 || x > mX1) 
            {
                //Console.WriteLine("valToPx_X returns false");
                return false;
            }

            double scale = mPanel.Width / (mX1 - mX0);
            px = NumberTools.d2i((x - mX0) * scale);
            return true;
        }

        private bool valToPx_Y(double y, out int px)
        {
            px = 0;

            if (y < mY0 || y > mY1)
            {
                //Console.WriteLine("valToPx_Y returns false");
                return false;
            }

            double scale = mPanel.Height / (mY1 - mY0);
            px = mPanel.Height-NumberTools.d2i((y - mY0) * scale);
            return true;
        }

        private bool pxToVal_X(int px, out double val)
        {
            val = mX0;

            double scale = (mX1 - mX0) / (double)mPanel.Width;

            //Console.WriteLine("px = " + px);
            //Console.WriteLine("scale = " + scale);

            val += scale * (double)px;
            
            return true;
        }

    }
}
