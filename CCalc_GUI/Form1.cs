using CCalc_GUI.GFX;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CCalc_GUI
{
    public partial class Form1 : Form
    {
        private CC_Renderer mGfx;

        public Form1()
        {

            InitializeComponent();

            // Init CCalc Renderer
            mGfx = new CC_Renderer();
            mGfx.Init(ref pnlGfx);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                double lX0 = double.Parse(tbxX0.Text);
                double lX1 = double.Parse(tbxX1.Text);
                double lY0 = double.Parse(tbxY0.Text);
                double lY1 = double.Parse(tbxY1.Text);

                mGfx.Render(lX0, lX1, lY0, lY1);
            }
            catch (Exception ex)
            {
                rtbConsole.AppendText("Exception while generating: " + ex.Message+"\n");
            }

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void btnSetFcn_Click(object sender, EventArgs e)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("f(x):=");
            sb.Append(tbxFunction.Text);

            string expression = sb.ToString();
            Console.WriteLine("Expression = "+expression);
            
            string ret=mGfx.SetFunction(expression);
            rtbConsole.AppendText("Add Function returns: " + ret+"\n");

        }
    }
}
