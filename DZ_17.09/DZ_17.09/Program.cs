

#region Task1
interface ICalc
{
    
    int Less(int valueToCompare);
    int Greater(int valueToCompare);
    
}

class Array : ICalc
{
    private int[] array;
    
    public Array(int[] arr)
    {
        array = arr;
    }
    
    public int Less(int valueToCompare)
    {
        int count = 0;
        foreach (int item in array)
        {
            if (valueToCompare < item)
                count++;
        }
        return count;
        
    }

    public int Greater(int valueToCompare)
    {
        int count = 0;
        foreach (int item in array)
        {
            if (valueToCompare > item)
                count++;
        }
        return count;
    }
    
    
}




class Program
{
    static void Main(string [] args)
    {
        
    int[] array = new int[10]{23, 44, 3, 6, 1, 34, 9, 10, 19,33};
    Array NewArray = new Array(array);


    Console.WriteLine("Enter value to compare: ");
    int valueToCompare = Int32.Parse(Console.ReadLine());
        
        int lessCount = NewArray.Less(valueToCompare);
        int greaterCount = NewArray.Greater(valueToCompare);

        Console.WriteLine($"Count of numbers less than entered: {lessCount}");
        Console.WriteLine($"Count of numbers greater than entered: {greaterCount}");
        
        
    }
}
#endregion Task1

#region Task2

interface IOutput2
{
    void ShowEven();
    void ShowOdd();
}

class Array : IOutput2
{
    private int[] array;

    public Array(int[] arr)
    {
        array = arr;
    }

    public void ShowEven()
    {
        Console.WriteLine("Even number: ");
        foreach (var item in array)
        {
            if (item % 2 == 0)
                Console.WriteLine(item);
        }
    }

    public void ShowOdd()
    {
        Console.WriteLine("Odd numbers: ");
        foreach (var item in array)
        {
            if (item % 2 != 0)
                Console.WriteLine(item);
        }
    }
    
}


class Program
{
    static void Main(string[] args)
    {
        
     int[] array = new int[10]{23, 44, 3, 6, 1, 34, 9, 10, 19,33};
     Array NewArray = new Array(array);
     
     NewArray.ShowEven();
     NewArray.ShowOdd();
     
    }
}






#endregion Task2

#region Task3

interface ICalc2
{

    int CountDistinct();
    int EqualToValue(int valueToCompare);

}

class Array : ICalc2
{
    private int[] array;

    public Array(int[] arr)
    {
        array = arr;
    }


    public int CountDistinct()
    {
        HashSet<int> uniqueNumbers = new HashSet<int>(array);
        return uniqueNumbers.Count;
    }

    public int EqualToValue(int valueToCompare)
    {
        int count = 0;
        foreach (var item in array)
        {
            if (item == valueToCompare)
                count++;
        }
        return count;
    }
}




class Program
{
    static void Main(string[] args)
    {
        
      int[] array = new int[10]{23, 44, 3, 44, 1, 34, 9, 10, 23, 33};
      Array NewArray = new Array(array);

      Console.WriteLine("Enter number to compare: ");
      int valueToCompare = Int32.Parse(Console.ReadLine());

      int distinctCount = NewArray.CountDistinct();
      int equalCount = NewArray.EqualToValue(valueToCompare);
      
      Console.WriteLine($"Number of unique values: {distinctCount}");
      Console.WriteLine($"Count of numbers equal to entered value: {equalCount}");


    }
}




#endregion Task3

