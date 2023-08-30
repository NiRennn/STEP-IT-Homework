#region FirstHW


#region Task1

Console.WriteLine("Enter your number between 1 and 100:");
int number = Int32.Parse(Console.ReadLine());

if (number % 3 == 0 && number % 5 == 0)
{
    Console.WriteLine("FizzBuzz");
}

else if (number % 3 == 0)
{
    Console.WriteLine("Fizz");
}

else if (number % 5 == 0)
{
    Console.WriteLine("Buzz");
}
else
{
    Console.WriteLine(number);
}

#endregion Task1

#region Task2

Console.WriteLine("Enter number: ");
int number = int.Parse(Console.ReadLine());

Console.WriteLine("Enter count of percents: ");
int percent = int.Parse(Console.ReadLine());


Console.WriteLine($"{percent} percents of {number} will be: {number / 100 * percent}");


#endregion Task2

#region Task3

Console.WriteLine("Enter first number: ");
int num1 = int.Parse(Console.ReadLine());

Console.WriteLine("Enter second number: ");
int num2 = int.Parse(Console.ReadLine());

Console.WriteLine("Enter third number: ");
int num3 = int.Parse(Console.ReadLine());

Console.WriteLine("Enter fourth number: ");
int num4 = int.Parse(Console.ReadLine());

int res = num1 * 1000 + num2 * 100 + num3 * 10 + num4;

Console.WriteLine(res);

#endregion Task3

#region Task4

int number = 0, divisor = 100000, firstIndex = 0, secondIndex = 0;
int[] numbers = new int[6];

bool checkoutNumber = false;

while (!checkoutNumber || number < 100000 || number > 999999)
{
    Console.Write("Enter number: ");
    checkoutNumber = Int32.TryParse(Console.ReadLine(), out number);
}

for (int i = 0; i < 6; i++)
{
    numbers[i] = number / divisor; 
    number %= divisor; 
    divisor /= 10; 
}

checkoutNumber = false;

while (!checkoutNumber || firstIndex <= 0 || firstIndex > 6)
{
    Console.Write("Enter index first number for exchange: ");
    checkoutNumber = Int32.TryParse(Console.ReadLine(), out firstIndex);
}

checkoutNumber = false;

while (!checkoutNumber || secondIndex <= 0 || secondIndex > 6)
{
    Console.Write("Enter index second number for exchange: ");
    checkoutNumber = Int32.TryParse(Console.ReadLine(), out secondIndex);
}

int temp = numbers[firstIndex - 1];
numbers[firstIndex - 1] = numbers[secondIndex - 1];
numbers[secondIndex - 1] = temp;

int result = 0;

for (int i = 0; i < 6; i++)
{
    result += numbers[i];
    result *= 10;
}
result /= 10;

Console.WriteLine("Result: " + result);




#endregion Task4

#region Task5

using System.Globalization;

DateOnly date = new DateOnly();

Console.WriteLine("Enter date(DD.MM.YYYY): ");
date = DateOnly.Parse(Console.ReadLine());

Console.WriteLine(date);
Console.WriteLine(date.DayOfWeek);

if (date.Month == 12 || date.Month == 1 || date.Month == 2)
{
    Console.WriteLine("Winter");
}
else if (date.Month == 3 || date.Month == 4 || date.Month == 5)
{
    Console.WriteLine("Spring");
}
else if (date.Month == 6 || date.Month == 7 || date.Month == 8)
{
    Console.WriteLine("Spring");
}
else if (date.Month == 9 || date.Month == 10 || date.Month == 11)
{
    Console.WriteLine("Spring");
}


#endregion Task5

#region Task6


    Console.WriteLine("Enter how you wanna swap:" +
                      "1. Celsius to Fahrenheit" +
                      "2. Fahrenheit to Celsius");

   int number = Int32.Parse(Console.ReadLine());

    
Console.WriteLine("Enter temperature: ");
double temperature = double.Parse(Console.ReadLine());

if (number == 1)
{
    Console.WriteLine((temperature * 9 / 5) + 32);
}
else if (number == 2)
{
    Console.WriteLine((temperature - 32) * 5/9);
}



#endregion Task6

#region Task7

Console.WriteLine("Enter start of diapason: ");
int start = Int32.Parse(Console.ReadLine());

Console.WriteLine("Enter end of diapason: ");
int end = Int32.Parse(Console.ReadLine());

if (start > end)
{
    int tmp = 0;
    tmp = start;
    start = end;
    end = tmp;

}

for (int i = start; i < end; i++)
{
    if (i % 2 == 0)
    {
        Console.WriteLine(i);
    }
}


#endregion Task7



#endregion FirstHW