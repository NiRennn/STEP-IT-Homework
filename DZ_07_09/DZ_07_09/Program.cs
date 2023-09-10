using System;


#region Task1

static void DecimalToBinary()
{
    Console.WriteLine("Enter number to convert from decimal to binary: ");
    // int number = Int32.Parse(Console.ReadLine());
    if (!int.TryParse(Console.ReadLine(), out int decimalNumber))
    {
        Console.WriteLine("Invalid input");
        return;
    }

    string binaryNumber = Convert.ToString(decimalNumber);
    Console.WriteLine(binaryNumber);

}


void BinaryToDecimal()
{
    Console.WriteLine("Enter number to convert from binary to decimal: ");
    string binaryNumber = Console.ReadLine();


    if (!BinaryValid(binaryNumber))
    {
        Console.WriteLine("Invalid input");
        return;
    }

    int decimalNumber = Convert.ToInt32(binaryNumber);
    Console.WriteLine(decimalNumber);
}

static bool BinaryValid(string binaryString)
{
    foreach (char ch in binaryString)
    {
        if (ch != '0' && ch != '1')
        {
            return false;
        }
    }

    return true;
}



Console.WriteLine("Welcome to Calculator!" +
                  "Enter your choice:" +
                  "1.From decimal to binary" +
                  "2.From binary to decimal");
int choice = Int32.Parse(Console.ReadLine());

switch (choice)
{
    case 1:
    {
        DecimalToBinary();
        break;
    }
    case 2:
    {
        BinaryToDecimal();
        break;
    }
}



#endregion


#region Task2


string[] words = new string[] { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

Console.WriteLine("Enter number from zero to nine by words: ");
string choice = Console.ReadLine();

for (int i = 0; i < words.Length; i++)
{
    if (words[i] == choice)
    {
        Console.WriteLine(i);
        break;
    }
}
    

#endregion


#region Task3

class ForeignPasport
{
    public string number { get;  set; }
    public string name { get;  set;  }
    public string surname { get;  set; }
    public DateTime date { get;  set; }



    
    public ForeignPasport(string Number, string Name, string Surname, DateTime Date)
    {
        if (!ValidNumber(Number))
        {
            throw new ArgumentException("Invalid number");
        }
        if (!ValidName(Name))
        {
            throw new ArgumentException("Invalid name");
        }

        if (!ValidSurname(Surname))
        {
            throw new ArgumentException("Invalid surname");
        }

        if (!ValidDate(Date))
        {
            throw new AggregateException("Invalid date");
        }

    }


    public string GetNumber()
    {
        return number;
    }
    
    public string GetName()
    {
        return name;
    }
    
    public string GetSurname()
    {
        return surname;
    }
    
    public DateTime GetDate()
    {
        return date;
    }

    

    private bool ValidNumber(string Number)
    {
        return !string.IsNullOrEmpty(Number) && Number.All(char.IsDigit);
    }
    private bool ValidName(string Name)
    {
        return !string.IsNullOrEmpty(Name) && Name.All(char.IsLetter);
    }
    private bool ValidSurname(string Surname)
    {
        return !string.IsNullOrEmpty(Surname) && Surname.All(char.IsLetter);
    }
    private bool ValidDate(DateTime Date)
    {
        return Date <= DateTime.Today;
    }
    
}

class Program
{


    static void Main(string[] argh)
    {

        ForeignPasport pasport = new ForeignPasport("12435454","Igor","Kostolomov",new DateTime(2024, 05, 06));
        

        Console.WriteLine(pasport.GetNumber());
        Console.WriteLine(pasport.GetName());
        Console.WriteLine(pasport.GetSurname());
        Console.WriteLine(pasport.GetDate());



    }
}




#endregion


#region Task4

Console.WriteLine("Enter a logical expression: ");
string expression = Console.ReadLine();

try
{
    bool result = ExpressionResult(expression);
    Console.WriteLine(result);
}
catch (FormatException)
{
    Console.WriteLine("Error : Invalid input format.");
}
catch (InvalidOperationException)
{
    Console.WriteLine("Error : Invalid logical expression.");
}

static bool ExpressionResult(string expression)
{
    string[] operators = { "<", ">", "<=", ">=", "==", "!=" };
    string[] spaces = expression.Split(' ');

    if (spaces.Length != 3)
    {
        throw new InvalidOperationException();
    }

    int firstNumber, secondNumber;
    string oper = spaces[1];

    firstNumber = int.Parse(spaces[0]);
    secondNumber = int.Parse(spaces[2]);
    
    switch (oper)
    {
        case "<":
            return firstNumber < secondNumber;
        case ">":
            return firstNumber > secondNumber;
        case "<=":
            return firstNumber <= secondNumber;
        case ">=":
            return firstNumber >= secondNumber;
        case "==":
            return firstNumber == secondNumber;
        case "!=":
            return firstNumber != secondNumber;
        default:
            throw new InvalidOperationException();
    }
}


#endregion




    