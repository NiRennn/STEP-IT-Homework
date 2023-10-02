



class Program
{
    static void Main()
    {
        
        MenuManagement Menu = new MenuManagement();
        Menu.LoadDictionaries();

        while (true)
        {
            Console.Clear();
            Console.WriteLine("Menu:");
            Console.WriteLine("1. Create new Dictionary");
            Console.WriteLine("2. Work with dictionary");
            Console.WriteLine("3. End program");

            int choice = Int32.Parse(Console.ReadLine());
            try
            {
                switch (choice)
                {
                    case 1:
                        Menu.CreateDictionary();
                        break;
                    case 2:
                        Menu.WorkWithDictionary();
                        break;
                    case 3:
                        Environment.Exit(0);
                        break;
                }
            }
            catch (Exception exception)
            {
                Console.WriteLine("Error: " + exception.Message);
                Console.WriteLine("Press <Enter> to continue");
                while(Console.ReadKey().Key != ConsoleKey.Enter){}
            }
        }
    }
    
    
    
    

    

    
        
    



}
