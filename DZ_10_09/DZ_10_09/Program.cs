
#region Task1

public class Journal
{
    private string JournalName { get; set; }
    private string JournalFoundation { get; set; }
    private string JournalDescription { get; set; }
    private string JournalTelephone { get; set; }
    private string JournalEmail { get; set; }
    private int EmployeesCount { get; set; }


    public static Journal operator +(Journal TestJournal,int count)
    {
        TestJournal.EmployeesCount += count;
        return TestJournal;
    }
    public static Journal operator -(Journal TestJournal,int count)
    {
        TestJournal.EmployeesCount -= count;
        return TestJournal;
    }
    public static bool operator <(Journal TestJournal, int count)
    {
        return TestJournal.EmployeesCount < count;
    }
    public static bool operator >(Journal TestJournal, int count)
    {
        return TestJournal.EmployeesCount > count;
    }

    public static bool operator ==(Journal TestJournal, int count)
    {
        return TestJournal.EmployeesCount == count;
    }

    public static bool operator !=(Journal TestJournal, int count)
    {
        return TestJournal.EmployeesCount != count;
    }
    
    
    
    
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
        Console.WriteLine("Enter count of employees: ");
        EmployeesCount = Int32.Parse(Console.ReadLine());;
    }

    public void DisplayInformation()
    {
        Console.WriteLine("Journal Name: " + JournalName);
        Console.WriteLine("Journal Foundation: " + JournalFoundation);
        Console.WriteLine("Journal Description: " + JournalDescription);
        Console.WriteLine("Journal Telephone: " + JournalTelephone);
        Console.WriteLine("Journal Email: " + JournalEmail);
        Console.WriteLine("Count of employees: " + EmployeesCount);
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

    public int  getJournalCount()
    {
        return EmployeesCount;
    }

    public void setJournalCount(int count)
    {
        EmployeesCount = count;
    }
}

class Program
{
    static void Main()
    {
        Journal TestJournal = new Journal();
        
        
        TestJournal.CreateJournal();
        TestJournal.DisplayInformation();
        Console.WriteLine(" ");
        Console.WriteLine("Enter what to do with count of employees:\n " +
                          "1.Add employees(+)\n" +
                          "2.Reduce employees(-)\n" +
                          "3.Check for equality(==)\n" +
                          "4.Check for less(<)\n" +
                          "5.Check for greater(>)\n");
        
        
        int choice = Int32.Parse(Console.ReadLine());

        int count = 0;
        switch (choice)
        {
            case 1:
                Console.WriteLine("Enter count to add: ");
                count = Int32.Parse(Console.ReadLine());
                TestJournal += count;
                
                TestJournal.DisplayInformation();
                break; 
            case 2:
                Console.WriteLine("Enter count to reduce: ");
                count = Int32.Parse(Console.ReadLine());
                TestJournal -= count;
                
                TestJournal.DisplayInformation();
                
                break; 
            case 3:
                Console.WriteLine("Enter count to reduce: ");
                count = Int32.Parse(Console.ReadLine());
                Console.WriteLine(TestJournal == count);
                
                break; 
            case 4:
                Console.WriteLine("Enter a number to compare: ");
                count = Int32.Parse(Console.ReadLine());
                Console.WriteLine(TestJournal < count);
                
                break; 
            case 5:
                Console.WriteLine("Enter a number to compare: ");
                count = Int32.Parse(Console.ReadLine());
                Console.WriteLine(TestJournal > count);
                
                break;
        }



    }
}


#endregion Task1


#region Task2

public class Market
{
    private string MarketName { get; set; }
    private string MarketAddress { get; set; }
    private string MarketProfile { get; set; }
    private string MarketTelephone { get; set; }
    private string MarketEmail { get; set; }
    private int MarketSquare { get; set; }


    public static Market operator +(Market TestMarket, int count)
    {
        return TestMarket += count;
        return TestMarket;
    }
    public static Market operator -(Market TestMarket, int count)
    {
        return TestMarket -= count;
        return TestMarket;
    }

    public static bool operator ==(Market TestMarket, int count)
    {
        return TestMarket.MarketSquare == count;
    }
    public static bool operator !=(Market TestMarket, int count)
    {
        return TestMarket.MarketSquare != count;
    }
    public static bool operator <(Market TestMarket, int count)
    {
        return TestMarket.MarketSquare < count;
    }
    public static bool operator >(Market TestMarket, int count)
    {
        return TestMarket.MarketSquare > count;
    }
    
    
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
        Console.WriteLine("Enter market square: ");
        MarketSquare = Int32.Parse(Console.ReadLine());
    }

    public void DisplayInformation()
    {
        Console.WriteLine("Market name: " + MarketName);
        Console.WriteLine("Market address: " + MarketAddress);
        Console.WriteLine("Market profile description: " + MarketProfile);
        Console.WriteLine("Market telephone: " + MarketTelephone);
        Console.WriteLine("Market Email: " + MarketEmail);
        Console.WriteLine("Market square: " + MarketSquare);
    }

    
    
}

class Program
{
    static void Main()
    {
        Market TestMarket = new Market();
        
        TestMarket.CreateMarket();
        TestMarket.DisplayInformation();

        
         Console.WriteLine(" ");
         Console.WriteLine("Enter what to do with square:\n " +
                           "1.Add square(+)\n" +
                           "2.Reduce square(-)\n" +
                           "3.Check for equality(==)\n" +
                           "4.Check for less(<)\n" +
                           "5.Check for greater(>)\n");
         
         
         int choice = Int32.Parse(Console.ReadLine());

         int count = 0;
         switch (choice)
         {
             case 1:
                 Console.WriteLine("Enter count to add: ");
                 count = Int32.Parse(Console.ReadLine());
                 TestMarket += count;
                 
                 TestMarket.DisplayInformation();
                 break; 
             case 2:
                 Console.WriteLine("Enter count to reduce: ");
                 count = Int32.Parse(Console.ReadLine());
                 TestMarket -= count;
                 
                 TestMarket.DisplayInformation();
                 
                 break; 
             case 3:
                 Console.WriteLine("Enter count to reduce: ");
                 count = Int32.Parse(Console.ReadLine());
                 Console.WriteLine(TestMarket == count);
                 
                 break; 
             case 4:
                 Console.WriteLine("Enter a number to compare: ");
                 count = Int32.Parse(Console.ReadLine());
                 Console.WriteLine(TestMarket < count);
                 
                 break; 
             case 5:
                 Console.WriteLine("Enter a number to compare: ");
                 count = Int32.Parse(Console.ReadLine());
                 Console.WriteLine(TestMarket > count);
                 
                 break;
         }

    }
}







#endregion Task2



#region Task3

class Book
{
    public string BookName { get; set; }
    public string BookAuthor { get; set; }


    public Book(string bookName, string author)
    {
        BookName = bookName;
        BookAuthor = author;
    }

    public override string ToString()
    {
        return $"{BookName} - {BookAuthor}";
    }
    
}

class ListOfBooks
{
    List<Book> books = new List<Book>();

    public void AddBook(Book book)
    {
        books.Add(book);
    }

    public void DeleteBook(string bookName)
    {
        books.RemoveAll(book => book.BookName.Equals(bookName, StringComparison.OrdinalIgnoreCase));
    }

    public bool ContainsBook(string bookName)
    {
        return books.Any(book => book.BookName.Equals(bookName,StringComparison.OrdinalIgnoreCase));
    }


    public Book this[int index]
    {
        get
        {
            if (index >= 0 && index < books.Count)
            {
                return books[index];
            }
            else
            {
                throw new ArgumentException();
            }
        }
    }
    
    public IEnumerable<Book> GetEnumerable()
    {
        return books;
    }
    
}



class Program
{
    static void Main(string[] args)
    {
        ListOfBooks booksList = new ListOfBooks();
        
        booksList.AddBook(new Book("Tri towaricha", "Remark"));
        booksList.AddBook(new Book("Voina i mir", "Lev Tolstoi"));
        booksList.AddBook(new Book("Putb k uspehu", "Nikolai Sobolev"));

        Console.WriteLine("List of books: ");
        foreach (Book book in booksList.GetEnumerable())
        {
            Console.WriteLine(book);
        }
        
        booksList.DeleteBook("voina i mir");
        
        Console.WriteLine("List of books after deleting: ");
        foreach (Book book in booksList.GetEnumerable())
        {
            Console.WriteLine(book);
        }


        Console.WriteLine(booksList.ContainsBook("Putb k uspehu"));


    }
}

#endregion
























