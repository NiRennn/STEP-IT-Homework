namespace WinFormsCalculatorApp
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            panel1 = new Panel();
            buttonZero = new Button();
            buttonPlusMinus = new Button();
            buttonZapyataya = new Button();
            buttonEqual = new Button();
            panel2 = new Panel();
            buttonThree = new Button();
            buttonPlus = new Button();
            buttoTwo = new Button();
            buttonOne = new Button();
            panel3 = new Panel();
            buttonFive = new Button();
            buttonFour = new Button();
            buttonSix = new Button();
            buttonMinus = new Button();
            panel4 = new Panel();
            buttonEight = new Button();
            buttonSeven = new Button();
            buttonNine = new Button();
            buttonMultyply = new Button();
            panel5 = new Panel();
            buttonCE = new Button();
            buttonPercent = new Button();
            buttonC = new Button();
            buttonDivide = new Button();
            textBox1 = new TextBox();
            panel1.SuspendLayout();
            panel2.SuspendLayout();
            panel3.SuspendLayout();
            panel4.SuspendLayout();
            panel5.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.Controls.Add(buttonZero);
            panel1.Controls.Add(buttonPlusMinus);
            panel1.Controls.Add(buttonZapyataya);
            panel1.Controls.Add(buttonEqual);
            panel1.Dock = DockStyle.Bottom;
            panel1.Location = new Point(0, 385);
            panel1.Name = "panel1";
            panel1.Size = new Size(288, 65);
            panel1.TabIndex = 0;
            // 
            // buttonZero
            // 
            buttonZero.BackColor = SystemColors.ControlDark;
            buttonZero.Dock = DockStyle.Left;
            buttonZero.FlatStyle = FlatStyle.Flat;
            buttonZero.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonZero.Location = new Point(72, 0);
            buttonZero.Name = "buttonZero";
            buttonZero.Size = new Size(72, 65);
            buttonZero.TabIndex = 3;
            buttonZero.Text = "0";
            buttonZero.UseVisualStyleBackColor = false;
            buttonZero.Click += buttonZero_Click;
            // 
            // buttonPlusMinus
            // 
            buttonPlusMinus.BackColor = SystemColors.ControlDark;
            buttonPlusMinus.Dock = DockStyle.Left;
            buttonPlusMinus.FlatStyle = FlatStyle.Flat;
            buttonPlusMinus.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonPlusMinus.Location = new Point(0, 0);
            buttonPlusMinus.Name = "buttonPlusMinus";
            buttonPlusMinus.Size = new Size(72, 65);
            buttonPlusMinus.TabIndex = 2;
            buttonPlusMinus.Text = "+/-";
            buttonPlusMinus.UseVisualStyleBackColor = false;
            buttonPlusMinus.Click += buttonPlusMinus_Click;
            // 
            // buttonZapyataya
            // 
            buttonZapyataya.BackColor = SystemColors.ControlDark;
            buttonZapyataya.Dock = DockStyle.Right;
            buttonZapyataya.FlatStyle = FlatStyle.Flat;
            buttonZapyataya.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonZapyataya.Location = new Point(144, 0);
            buttonZapyataya.Name = "buttonZapyataya";
            buttonZapyataya.Size = new Size(72, 65);
            buttonZapyataya.TabIndex = 1;
            buttonZapyataya.Text = ",";
            buttonZapyataya.UseVisualStyleBackColor = false;
            // 
            // buttonEqual
            // 
            buttonEqual.BackColor = SystemColors.ScrollBar;
            buttonEqual.Dock = DockStyle.Right;
            buttonEqual.FlatStyle = FlatStyle.Flat;
            buttonEqual.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonEqual.Location = new Point(216, 0);
            buttonEqual.Name = "buttonEqual";
            buttonEqual.Size = new Size(72, 65);
            buttonEqual.TabIndex = 0;
            buttonEqual.Text = "=";
            buttonEqual.UseVisualStyleBackColor = false;
            buttonEqual.Click += buttonEqual_Click;
            // 
            // panel2
            // 
            panel2.Controls.Add(buttonThree);
            panel2.Controls.Add(buttonPlus);
            panel2.Controls.Add(buttoTwo);
            panel2.Controls.Add(buttonOne);
            panel2.Dock = DockStyle.Bottom;
            panel2.Location = new Point(0, 320);
            panel2.Name = "panel2";
            panel2.Size = new Size(288, 65);
            panel2.TabIndex = 1;
            // 
            // buttonThree
            // 
            buttonThree.BackColor = SystemColors.ControlDark;
            buttonThree.Dock = DockStyle.Right;
            buttonThree.FlatStyle = FlatStyle.Flat;
            buttonThree.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonThree.Location = new Point(144, 0);
            buttonThree.Name = "buttonThree";
            buttonThree.Size = new Size(72, 65);
            buttonThree.TabIndex = 3;
            buttonThree.Text = "3";
            buttonThree.UseVisualStyleBackColor = false;
            buttonThree.Click += buttonZero_Click;
            // 
            // buttonPlus
            // 
            buttonPlus.BackColor = SystemColors.ScrollBar;
            buttonPlus.Dock = DockStyle.Right;
            buttonPlus.FlatStyle = FlatStyle.Flat;
            buttonPlus.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonPlus.Location = new Point(216, 0);
            buttonPlus.Name = "buttonPlus";
            buttonPlus.Size = new Size(72, 65);
            buttonPlus.TabIndex = 2;
            buttonPlus.Text = "+";
            buttonPlus.UseVisualStyleBackColor = false;
            buttonPlus.Click += buttonPlus_Click;
            // 
            // buttoTwo
            // 
            buttoTwo.BackColor = SystemColors.ControlDark;
            buttoTwo.Dock = DockStyle.Left;
            buttoTwo.FlatStyle = FlatStyle.Flat;
            buttoTwo.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttoTwo.Location = new Point(72, 0);
            buttoTwo.Name = "buttoTwo";
            buttoTwo.Size = new Size(72, 65);
            buttoTwo.TabIndex = 1;
            buttoTwo.Text = "2";
            buttoTwo.UseVisualStyleBackColor = false;
            buttoTwo.Click += buttonZero_Click;
            // 
            // buttonOne
            // 
            buttonOne.BackColor = SystemColors.ControlDark;
            buttonOne.Dock = DockStyle.Left;
            buttonOne.FlatStyle = FlatStyle.Flat;
            buttonOne.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonOne.Location = new Point(0, 0);
            buttonOne.Name = "buttonOne";
            buttonOne.Size = new Size(72, 65);
            buttonOne.TabIndex = 0;
            buttonOne.Text = "1";
            buttonOne.UseVisualStyleBackColor = false;
            buttonOne.Click += buttonZero_Click;
            // 
            // panel3
            // 
            panel3.Controls.Add(buttonFive);
            panel3.Controls.Add(buttonFour);
            panel3.Controls.Add(buttonSix);
            panel3.Controls.Add(buttonMinus);
            panel3.Dock = DockStyle.Bottom;
            panel3.Location = new Point(0, 255);
            panel3.Name = "panel3";
            panel3.Size = new Size(288, 65);
            panel3.TabIndex = 2;
            // 
            // buttonFive
            // 
            buttonFive.BackColor = SystemColors.ControlDark;
            buttonFive.Dock = DockStyle.Left;
            buttonFive.FlatStyle = FlatStyle.Flat;
            buttonFive.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonFive.Location = new Point(72, 0);
            buttonFive.Name = "buttonFive";
            buttonFive.Size = new Size(72, 65);
            buttonFive.TabIndex = 3;
            buttonFive.Text = "5";
            buttonFive.UseVisualStyleBackColor = false;
            buttonFive.Click += buttonZero_Click;
            // 
            // buttonFour
            // 
            buttonFour.BackColor = SystemColors.ControlDark;
            buttonFour.Dock = DockStyle.Left;
            buttonFour.FlatStyle = FlatStyle.Flat;
            buttonFour.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonFour.Location = new Point(0, 0);
            buttonFour.Name = "buttonFour";
            buttonFour.Size = new Size(72, 65);
            buttonFour.TabIndex = 2;
            buttonFour.Text = "4";
            buttonFour.UseVisualStyleBackColor = false;
            buttonFour.Click += buttonZero_Click;
            // 
            // buttonSix
            // 
            buttonSix.BackColor = SystemColors.ControlDark;
            buttonSix.Dock = DockStyle.Right;
            buttonSix.FlatStyle = FlatStyle.Flat;
            buttonSix.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonSix.Location = new Point(144, 0);
            buttonSix.Name = "buttonSix";
            buttonSix.Size = new Size(72, 65);
            buttonSix.TabIndex = 1;
            buttonSix.Text = "6";
            buttonSix.UseVisualStyleBackColor = false;
            buttonSix.Click += buttonZero_Click;
            // 
            // buttonMinus
            // 
            buttonMinus.BackColor = SystemColors.ScrollBar;
            buttonMinus.Dock = DockStyle.Right;
            buttonMinus.FlatStyle = FlatStyle.Flat;
            buttonMinus.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonMinus.Location = new Point(216, 0);
            buttonMinus.Name = "buttonMinus";
            buttonMinus.Size = new Size(72, 65);
            buttonMinus.TabIndex = 0;
            buttonMinus.Text = "-";
            buttonMinus.UseVisualStyleBackColor = false;
            buttonMinus.Click += buttonPlus_Click;
            // 
            // panel4
            // 
            panel4.Controls.Add(buttonEight);
            panel4.Controls.Add(buttonSeven);
            panel4.Controls.Add(buttonNine);
            panel4.Controls.Add(buttonMultyply);
            panel4.Dock = DockStyle.Bottom;
            panel4.Location = new Point(0, 190);
            panel4.Name = "panel4";
            panel4.Size = new Size(288, 65);
            panel4.TabIndex = 3;
            // 
            // buttonEight
            // 
            buttonEight.BackColor = SystemColors.ControlDark;
            buttonEight.Dock = DockStyle.Left;
            buttonEight.FlatStyle = FlatStyle.Flat;
            buttonEight.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonEight.Location = new Point(72, 0);
            buttonEight.Name = "buttonEight";
            buttonEight.Size = new Size(72, 65);
            buttonEight.TabIndex = 3;
            buttonEight.Text = "8";
            buttonEight.UseVisualStyleBackColor = false;
            buttonEight.Click += buttonZero_Click;
            // 
            // buttonSeven
            // 
            buttonSeven.BackColor = SystemColors.ControlDark;
            buttonSeven.Dock = DockStyle.Left;
            buttonSeven.FlatStyle = FlatStyle.Flat;
            buttonSeven.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonSeven.Location = new Point(0, 0);
            buttonSeven.Name = "buttonSeven";
            buttonSeven.Size = new Size(72, 65);
            buttonSeven.TabIndex = 2;
            buttonSeven.Text = "7";
            buttonSeven.UseVisualStyleBackColor = false;
            buttonSeven.Click += buttonZero_Click;
            // 
            // buttonNine
            // 
            buttonNine.BackColor = SystemColors.ControlDark;
            buttonNine.Dock = DockStyle.Right;
            buttonNine.FlatStyle = FlatStyle.Flat;
            buttonNine.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonNine.Location = new Point(144, 0);
            buttonNine.Name = "buttonNine";
            buttonNine.Size = new Size(72, 65);
            buttonNine.TabIndex = 1;
            buttonNine.Text = "9";
            buttonNine.UseVisualStyleBackColor = false;
            buttonNine.Click += buttonZero_Click;
            // 
            // buttonMultyply
            // 
            buttonMultyply.BackColor = SystemColors.ScrollBar;
            buttonMultyply.Dock = DockStyle.Right;
            buttonMultyply.FlatStyle = FlatStyle.Flat;
            buttonMultyply.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonMultyply.Location = new Point(216, 0);
            buttonMultyply.Name = "buttonMultyply";
            buttonMultyply.Size = new Size(72, 65);
            buttonMultyply.TabIndex = 0;
            buttonMultyply.Text = "X";
            buttonMultyply.UseVisualStyleBackColor = false;
            buttonMultyply.Click += buttonPlus_Click;
            // 
            // panel5
            // 
            panel5.Controls.Add(buttonCE);
            panel5.Controls.Add(buttonPercent);
            panel5.Controls.Add(buttonC);
            panel5.Controls.Add(buttonDivide);
            panel5.Dock = DockStyle.Bottom;
            panel5.Location = new Point(0, 125);
            panel5.Name = "panel5";
            panel5.Size = new Size(288, 65);
            panel5.TabIndex = 4;
            // 
            // buttonCE
            // 
            buttonCE.BackColor = SystemColors.ScrollBar;
            buttonCE.Dock = DockStyle.Left;
            buttonCE.FlatStyle = FlatStyle.Flat;
            buttonCE.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonCE.Location = new Point(72, 0);
            buttonCE.Name = "buttonCE";
            buttonCE.Size = new Size(72, 65);
            buttonCE.TabIndex = 3;
            buttonCE.Text = "CE";
            buttonCE.UseVisualStyleBackColor = false;
            buttonCE.Click += buttonC_Click;
            // 
            // buttonPercent
            // 
            buttonPercent.BackColor = SystemColors.ScrollBar;
            buttonPercent.Dock = DockStyle.Left;
            buttonPercent.FlatStyle = FlatStyle.Flat;
            buttonPercent.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonPercent.Location = new Point(0, 0);
            buttonPercent.Name = "buttonPercent";
            buttonPercent.Size = new Size(72, 65);
            buttonPercent.TabIndex = 2;
            buttonPercent.Text = "%";
            buttonPercent.UseVisualStyleBackColor = false;
            // 
            // buttonC
            // 
            buttonC.BackColor = SystemColors.ScrollBar;
            buttonC.Dock = DockStyle.Right;
            buttonC.FlatStyle = FlatStyle.Flat;
            buttonC.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonC.Location = new Point(144, 0);
            buttonC.Name = "buttonC";
            buttonC.Size = new Size(72, 65);
            buttonC.TabIndex = 1;
            buttonC.Text = "C";
            buttonC.UseVisualStyleBackColor = false;
            buttonC.Click += buttonC_Click;
            // 
            // buttonDivide
            // 
            buttonDivide.BackColor = SystemColors.ScrollBar;
            buttonDivide.Dock = DockStyle.Right;
            buttonDivide.FlatStyle = FlatStyle.Flat;
            buttonDivide.Font = new Font("Calibri", 18F, FontStyle.Bold, GraphicsUnit.Point);
            buttonDivide.Location = new Point(216, 0);
            buttonDivide.Name = "buttonDivide";
            buttonDivide.Size = new Size(72, 65);
            buttonDivide.TabIndex = 0;
            buttonDivide.Text = "/";
            buttonDivide.UseVisualStyleBackColor = false;
            buttonDivide.Click += buttonPlus_Click;
            // 
            // textBox1
            // 
            textBox1.BackColor = SystemColors.ControlDarkDark;
            textBox1.Font = new Font("Calibri", 39.75F, FontStyle.Bold, GraphicsUnit.Point);
            textBox1.Location = new Point(0, 12);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(288, 72);
            textBox1.TabIndex = 5;
            textBox1.Text = "0";
            textBox1.TextAlign = HorizontalAlignment.Right;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ControlDarkDark;
            ClientSize = new Size(288, 450);
            Controls.Add(textBox1);
            Controls.Add(panel5);
            Controls.Add(panel4);
            Controls.Add(panel3);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Name = "Form1";
            Text = "Form1";
            panel1.ResumeLayout(false);
            panel2.ResumeLayout(false);
            panel3.ResumeLayout(false);
            panel4.ResumeLayout(false);
            panel5.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Panel panel1;
        private Panel panel2;
        private Panel panel3;
        private Panel panel4;
        private Button buttonZero;
        private Button buttonPlusMinus;
        private Button buttonZapyataya;
        private Button buttonEqual;
        private Button buttonThree;
        private Button buttonPlus;
        private Button buttoTwo;
        private Button buttonOne;
        private Button buttonFive;
        private Button buttonFour;
        private Button buttonSix;
        private Button buttonMinus;
        private Panel panel5;
        private Button buttonEight;
        private Button buttonSeven;
        private Button buttonNine;
        private Button buttonMultyply;
        private Button buttonCE;
        private Button buttonPercent;
        private Button buttonC;
        private Button buttonDivide;
        private TextBox textBox1;
    }
}