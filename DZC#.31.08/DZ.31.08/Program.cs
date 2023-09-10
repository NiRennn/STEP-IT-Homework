

#region Task1

void SquareDrawing(char symbol, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            Console.Write(symbol);
        }

        Console.WriteLine();
    }
}

Console.WriteLine("Enter symbol: ");
char symbol = char.Parse(Console.ReadLine());

Console.WriteLine("Enter length of square: ");
int length = int.Parse(Console.ReadLine());

SquareDrawing(symbol,length);

#endregion Task1

#region Task2

static bool PalindromeCheck(int number)
{
    string numberStr = number.ToString();
    int left = 0;
    int right = numberStr.Length - 1;

    while (left < right)
    {
        if (numberStr[left] != numberStr[right])
            return false;
        
        
        left++;
        right--;
    }

    return true;
}

Console.WriteLine("Enter a number to check for a palindrome: ");
int number = int.Parse(Console.ReadLine());

Console.WriteLine(PalindromeCheck(number));


#endregion Task2

#region Task3

void Filter(int[] array, int[] filterArray)
{
    array = array.Where(item => !filterArray.Contains(item)).ToArray();

    for (int i = 0; i < array.Length; i++)
    {
        Console.Write(array[i] + " ");
    }
}



int[] array = { 12, 44, 39, 42, 15, 60, -7, 8, 99, 100 };

for (int i = 0; i < array.Length; i++)
{
    Console.Write(array[i] + " ");
}

Console.WriteLine("\n");
Console.WriteLine("Enter filtation array length: ");
int length = Int32.Parse(Console.ReadLine());

int[] filterArray = new int[length];

Console.WriteLine("Enter numbers to filtration: ");
for (int i = 0; i < filterArray.Length; i++)
{
    filterArray[i] = Int32.Parse(Console.ReadLine());
}


Filter(array, filterArray);



#endregion Task3

#region Task4


public class WebSite
{
    private string SiteName { get ; set; }
    private string SitePath { get ; set; }
    private string SiteDescription { get ; set; }
    private string SiteIP { get ; set; }

    public void CreateWebSite()
    {
        Console.WriteLine("Enter web site name: ");
        SiteName = Console.ReadLine();
        Console.WriteLine("Enter site path: ");
        SitePath = Console.ReadLine();
        Console.WriteLine("Enter site description:");
        SiteDescription = Console.ReadLine();
        Console.WriteLine("Enter site IP: ");
        SiteIP = Console.ReadLine();
    }

    public void DisplayInformation()
    {
        Console.WriteLine("Web site Name: " + SiteName);
        Console.WriteLine("Web site path: " + SitePath);
        Console.WriteLine("Web site Description: " + SiteDescription);
        Console.WriteLine("Web site IP: " + SiteIP);
    }
    
    
    public string getName()
    {
        return SiteName;
    }
    public void setName()
    {
        SiteName = SiteName;
    }

    public string getPath()
    {
        return SitePath;
    }
    public void setPath()
    {
        SitePath = SitePath;
    }

    public string getDescription()
    {
        return SiteDescription;
    }
    public void setDescription()
    {
        SiteDescription = SiteDescription;
    }

    public string getIP()
    {
        return SiteIP;
    }

    public void setIP()
    {
        SiteIP = SiteIP;
    }


}

class Program
{
    static void Main(string[] args)
    {
        WebSite TestWebSite = new WebSite();
        TestWebSite.CreateWebSite();
        
        TestWebSite.DisplayInformation();
        
        
    }
}







#endregion Task4

#region Task5

public class Journal
{
    private string JournalName { get; set; }
    private string JournalFoundation { get; set; }
    private string JournalDescription { get; set; }
    private string JournalTelephone { get; set; }
    private string JournalEmail { get; set; }

    public void CreateJournal()
    {
        Console.WriteLine("Enter Journal Name: ");
        JournalName = Console.ReadLine();
        Console.WriteLine("Enter Journal Foundation: ");
        JournalFoundation = Console.ReadLine();
        Console.WriteLine("Enter Journal Description: ");
        JournalDescription = Console.ReadLine();
        Console.WriteLine("Enter Journal Telephone: ");
        JournalTelephone = Console.ReadLine();
        Console.WriteLine("Enter Journal Email: ");
        JournalEmail = Console.ReadLine();
    }

    public void DisplayInformation()
    {
        Console.WriteLine("Journal Name: " + JournalName);
        Console.WriteLine("Journal Foundation: " + JournalFoundation);
        Console.WriteLine("Journal Description: " + JournalDescription);
        Console.WriteLine("Journal Telephone: " + JournalTelephone);
        Console.WriteLine("Journal Email: " + JournalEmail);
    }

    public string getJournalName()
    {
        return JournalName;
    }
    public void setJournalName(string name)
    {
        JournalName = name;
    }

    public string getJournalFoundation()
    {
        return JournalFoundation;
    }
    public void setJournalFoundation(string foundation)
    {
        JournalFoundation = foundation;
    }

    public string getJournalDescription()
    {
        return JournalDescription;
    }
    public void setJournalDescription(string description)
    {
        JournalDescription = description;
    }

    public string getJournalTelephone()
    {
        return JournalTelephone;
    }
    public void setJournalTelephone(string telephone)
    {
        JournalTelephone = telephone;
    }

    public string getJournalEmail()
    {
        return JournalEmail;
    }
    public void setJournalEmail(string email)
    {
        JournalEmail = email;
    }
    
}

class Program
{
    static void Main(string[] args)
    {
        Journal TestJournal = new Journal();
        
        TestJournal.CreateJournal();
        TestJournal.DisplayInformation();


    }
}


#endregion Task5

#region Task6

public class Market
{
    private string MarketName { get; set; }
    private string MarketAddress { get; set; }
    private string MarketProfile { get; set; }
    private string MarketTelephone { get; set; }
    private string MarketEmail { get; set; }

    public void CreateMarket()
    {
        Console.WriteLine("Enter market Name: ");
        MarketName = Console.ReadLine();
        Console.WriteLine("Enter market address: ");
        MarketAddress = Console.ReadLine();
        Console.WriteLine("Enter market profile description: ");
        MarketProfile = Console.ReadLine();
        Console.WriteLine("Enter market telephone: ");
        MarketTelephone = Console.ReadLine();
        Console.WriteLine("Enter market Email: ");
        MarketEmail = Console.ReadLine();
    }

    public void DisplayInformation()
    {
        Console.WriteLine("Market name: " + MarketName);
        Console.WriteLine("Market address: " + MarketAddress);
        Console.WriteLine("Market profile description: " + MarketProfile);
        Console.WriteLine("Market telephone: " + MarketTelephone);
        Console.WriteLine("Market Email: " + MarketEmail);
    }

    public string getMarketName()
    {
        return MarketName;
    }
    public void setMarketName(string name)
    {
        MarketName = name;
    }

    public string getMarketAddress()
    {
        return MarketAddress;
    }
    public void setMarketAddress(string address)
    {
        MarketAddress = address;
    }

    public string getMarketProjileDescription()
    {
        return MarketProfile;
    }
    public void setMarketProfileDescription(string description)
    {
        MarketProfile = description;
    }

    public string getMarketTelephone()
    {
        return MarketTelephone;
    }
    public void setMarketTelephone(string telephone)
    {
        MarketTelephone = telephone;
    }

    public string getMarketEmail()
    {
        return MarketEmail;
    }
    public void setMarketEmail(string email)
    {
        MarketEmail = email;
    }
    
}

class Program
{
    static void Main(string[] args)
    {
        Market TestMarket = new Market();
        
        TestMarket.CreateMarket();
        TestMarket.DisplayInformation();


    }
}

#endregion Task6



