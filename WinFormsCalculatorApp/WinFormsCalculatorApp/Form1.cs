namespace WinFormsCalculatorApp
{
    public partial class Form1 : Form
    {
        public string oper;
        public string firstNumber;
        public bool tag;

        public Form1()
        {
            InitializeComponent();
        }

        private void buttonZero_Click(object sender, EventArgs e)
        {
            if (tag)
            {
                tag = false;
                textBox1.Text = "0";
            }
            Button tmp = (Button)sender;

            if (textBox1.Text == "0")
            {
                textBox1.Text = tmp.Text;
            }
            else
            {
                textBox1.Text = textBox1.Text + tmp.Text;
            }
        }

        private void buttonC_Click(object sender, EventArgs e)
        {
            textBox1.Text = "0";
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            Button tmp = (Button)sender;
            oper = tmp.Text;
            firstNumber = textBox1.Text;
            tag = true;


        }

        private void buttonEqual_Click(object sender, EventArgs e)
        {
            double first, second, result = 0;

            first = Convert.ToDouble(firstNumber);
            second = Convert.ToDouble(textBox1.Text);

            if (oper == "+")
            {
                result = first + second;
            }
            if (oper == "-")
            {
                result = first - second;
            }
            if (oper == "X")
            {
                result = first * second;
            }
            if (oper == "/")
            {
                result = first / second;
            }

            oper = "=";
            tag = true;


            textBox1.Text = result.ToString();
        }

        private void buttonPlusMinus_Click(object sender, EventArgs e)
        {
            double firstNumber, result;
            firstNumber = Convert.ToDouble(textBox1.Text);
            result = -firstNumber;
            textBox1.Text = result.ToString();

        }
    }
}