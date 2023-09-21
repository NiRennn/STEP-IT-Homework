


class Calculator
{
    // private double FirstValue;
    // private double SecondValue;
    
    
    
    // public Calculator(double firstValue, double secondValue)
    // {
    // FirstValue = firstValue;
    // SecondValue = secondValue;
    // }


    public delegate double MathOperations(double a, double b);
    
    
    public double Add(double a, double b)
    {
        return a + b;
    }

    public double Subtract(double a, double b)
    {
        return a - b;
    }

    public double Multiply(double a, double b)
    {
        return a * b;
    }

    public double Divide(double a, double b)
    {
        if (b == 0)
        {
            Console.WriteLine("Error! Division by zero!");

        }
        
        return a / b;
    }


    public double Calculate(MathOperations operation, double a, double b)
    {
        return operation(a, b);
    }
    
}




class Program
{

    static void Main(string[] args)
    {
        Calculator calc = new Calculator();

        Calculator.MathOperations addOperation = calc.Add;
        Calculator.MathOperations subtractOperation = calc.Subtract;
        Calculator.MathOperations multiplyOperation = calc.Multiply;
        Calculator.MathOperations divideOperation = calc.Divide;


        double resultAdd = calc.Calculate(addOperation, 10, 5);
        double resultSubtract = calc.Calculate(subtractOperation, 10, 5);
        double resultMultiply = calc.Calculate(multiplyOperation, 10, 5);
        double resultDivide = calc.Calculate(divideOperation, 10, 5);


        Console.WriteLine($"a + b = {resultAdd}");
        Console.WriteLine($"a - b = {resultSubtract}");
        Console.WriteLine($"a * b = {resultMultiply}");
        Console.WriteLine($"a / b = {resultDivide}");

    }
}