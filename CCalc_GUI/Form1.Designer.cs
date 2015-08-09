namespace CCalc_GUI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pnlGfx = new System.Windows.Forms.Panel();
            this.tbxX0 = new System.Windows.Forms.TextBox();
            this.tbxX1 = new System.Windows.Forms.TextBox();
            this.tbxY1 = new System.Windows.Forms.TextBox();
            this.tbxY0 = new System.Windows.Forms.TextBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.rtbConsole = new System.Windows.Forms.RichTextBox();
            this.tbxFunction = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnGenerate = new System.Windows.Forms.Button();
            this.btnSetFcn = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlGfx
            // 
            this.pnlGfx.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pnlGfx.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.pnlGfx.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlGfx.Location = new System.Drawing.Point(63, 20);
            this.pnlGfx.Name = "pnlGfx";
            this.pnlGfx.Size = new System.Drawing.Size(498, 298);
            this.pnlGfx.TabIndex = 0;
            // 
            // tbxX0
            // 
            this.tbxX0.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbxX0.Location = new System.Drawing.Point(63, 324);
            this.tbxX0.Name = "tbxX0";
            this.tbxX0.Size = new System.Drawing.Size(42, 20);
            this.tbxX0.TabIndex = 1;
            this.tbxX0.Text = "-10";
            this.tbxX0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbxX1
            // 
            this.tbxX1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.tbxX1.Location = new System.Drawing.Point(519, 324);
            this.tbxX1.Name = "tbxX1";
            this.tbxX1.Size = new System.Drawing.Size(42, 20);
            this.tbxX1.TabIndex = 2;
            this.tbxX1.Text = "10";
            this.tbxX1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbxY1
            // 
            this.tbxY1.Location = new System.Drawing.Point(15, 20);
            this.tbxY1.Name = "tbxY1";
            this.tbxY1.Size = new System.Drawing.Size(42, 20);
            this.tbxY1.TabIndex = 3;
            this.tbxY1.Text = "10";
            this.tbxY1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tbxY0
            // 
            this.tbxY0.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.tbxY0.Location = new System.Drawing.Point(15, 298);
            this.tbxY0.Name = "tbxY0";
            this.tbxY0.Size = new System.Drawing.Size(42, 20);
            this.tbxY0.TabIndex = 4;
            this.tbxY0.Text = "-10";
            this.tbxY0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // panel2
            // 
            this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.label3);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.pnlGfx);
            this.panel2.Controls.Add(this.tbxY0);
            this.panel2.Controls.Add(this.tbxX0);
            this.panel2.Controls.Add(this.tbxY1);
            this.panel2.Controls.Add(this.tbxX1);
            this.panel2.Location = new System.Drawing.Point(93, 12);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(581, 364);
            this.panel2.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(293, 327);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(14, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "X";
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(28, 167);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(14, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Y";
            // 
            // rtbConsole
            // 
            this.rtbConsole.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.rtbConsole.Location = new System.Drawing.Point(12, 433);
            this.rtbConsole.Name = "rtbConsole";
            this.rtbConsole.Size = new System.Drawing.Size(662, 96);
            this.rtbConsole.TabIndex = 6;
            this.rtbConsole.Text = "";
            // 
            // tbxFunction
            // 
            this.tbxFunction.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbxFunction.Font = new System.Drawing.Font("Lucida Console", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbxFunction.Location = new System.Drawing.Point(180, 394);
            this.tbxFunction.Name = "tbxFunction";
            this.tbxFunction.Size = new System.Drawing.Size(475, 23);
            this.tbxFunction.TabIndex = 7;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Lucida Console", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(106, 397);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(68, 16);
            this.label1.TabIndex = 8;
            this.label1.Text = "f(x):=";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // btnGenerate
            // 
            this.btnGenerate.Location = new System.Drawing.Point(12, 12);
            this.btnGenerate.Name = "btnGenerate";
            this.btnGenerate.Size = new System.Drawing.Size(75, 23);
            this.btnGenerate.TabIndex = 9;
            this.btnGenerate.Text = "Generate";
            this.btnGenerate.UseVisualStyleBackColor = true;
            this.btnGenerate.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnSetFcn
            // 
            this.btnSetFcn.Location = new System.Drawing.Point(12, 42);
            this.btnSetFcn.Name = "btnSetFcn";
            this.btnSetFcn.Size = new System.Drawing.Size(75, 23);
            this.btnSetFcn.TabIndex = 10;
            this.btnSetFcn.Text = "Set Function";
            this.btnSetFcn.UseVisualStyleBackColor = true;
            this.btnSetFcn.Click += new System.EventHandler(this.btnSetFcn_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(12, 72);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 11;
            this.button3.Text = "*Dummy2*";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(686, 541);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.btnSetFcn);
            this.Controls.Add(this.btnGenerate);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbxFunction);
            this.Controls.Add(this.rtbConsole);
            this.Controls.Add(this.panel2);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "CCalc GUI";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel pnlGfx;
        private System.Windows.Forms.TextBox tbxX0;
        private System.Windows.Forms.TextBox tbxX1;
        private System.Windows.Forms.TextBox tbxY1;
        private System.Windows.Forms.TextBox tbxY0;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.RichTextBox rtbConsole;
        private System.Windows.Forms.TextBox tbxFunction;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnGenerate;
        private System.Windows.Forms.Button btnSetFcn;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
    }
}

