

class BankAccount
{
    private double Balance;
    private string AccountName;
    
    public BankAccount(double startingBalance, string accountName)
    {
        Balance = startingBalance;
        AccountName = accountName;
        
    }

    public delegate void AccountOperation(double amount);

    public event AccountOperation DepositEvent;
    public event AccountOperation WithdrawEvent;
    
    public void Deposit(double amount)
    {
        Balance += amount;
        DepositEvent?.Invoke(amount);
    }

    public void Withdraw(double amount)
    {
        if (Balance >= amount)
        {


            Balance -= amount;
            DepositEvent?.Invoke(amount);
        }
        else
        {
            Console.WriteLine($"There is not enough money in the account {AccountName}");
        }
    }
    
    public void PrintInfo()
    {
        Console.WriteLine("******Bank Account Information******");
        Console.WriteLine($"Account Name: {AccountName}");
        Console.WriteLine($"Account Balance: {Balance}");
        Console.WriteLine("************************************");
    }
}


class Program
{
    static void Main(string[] args)
    {
        
        BankAccount account = new BankAccount(1000,"Igor Kostolomov");
        
        account.PrintInfo();

        Console.WriteLine(" ");

        account.DepositEvent += (amount) => Console.WriteLine($"Credited {amount} to account");
        account.WithdrawEvent += (amount) => Console.WriteLine($"{amount} debited from the account");

        Console.WriteLine("\n");
        
        account.Deposit(500);
        account.Withdraw(200);
        account.Withdraw(2000);
        
        account.PrintInfo();



    }
}