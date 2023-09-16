


#region Task1
class Money
{

    private int Dollars;
    private int Cents;

    public Money(int dollars, int cents)
    {
        Dollars = dollars;
        Cents = cents;
    }
    
    public void PrintMoney()
    {
        Console.WriteLine($"{Dollars} dollars and {Cents} cents.");
    }

    public void SetMoney(int dollars, int cents)
    {
        Dollars = dollars;
        Cents = cents;
    }

    public int GetDollars()
    {
        return Dollars;
    }

    public int GetCents()
    {
        return Cents;
    }
}

class Product
{
    public string Name { get; set; }
    public Money Cost { get; set; }

    public Product(string name, int dollars, int cents)
    {
        Name = name;
        Cost = new Money(dollars, cents);
    }

    public void ReduceCost(int dollars, int cents)
    {
        int NewDollars = Cost.GetDollars() - dollars;
        int NewCents = Cost.GetCents() - cents;


        if (NewCents < 0)
        {
            NewDollars -= 1;
            NewCents += 100;
        }
        else if (NewCents > 100)
        {
            NewDollars += 1;
            NewCents -= 100;
        }
        Cost.SetMoney(NewDollars, NewCents);
    }

    public void PrintProduct()
    {
        Console.WriteLine($"Name of product: {Name}. Cost: {Cost.GetDollars()} dollars {Cost.GetCents()} cents.");
    }
    
    
}



class Prgram
{
    static void Main(string[] args)
    {
        
        Money money = new Money(100,60);
        money.PrintMoney();

        Product product = new Product("Apple", 15, 30);
        product.PrintProduct();

        Console.WriteLine("New Product cost: ");
        product.ReduceCost(4,15);
        
        product.PrintProduct();




    }

}
#endregion Task1



#region Task2


class Device
{
    protected string Name;
    protected string Characteristics;
    
    public Device(string name, string characteristics)
    {
        Name = name;
        Characteristics = characteristics;
    }


    public virtual void Sound()
    {
        Console.WriteLine($"Sound of {Name} : ............");
    }


    public virtual void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }


    public virtual void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
}

class Kettle : Device
{
    public Kettle(string name, string characteristics) : base(name, characteristics){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: PSHSHSHSHSHSHSHSHS");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
}


class Microwave : Device
{
    public Microwave(string name, string characteristics) : base(name, characteristics){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: BWWWWWWWWWWWWWWWWWWWWWWWW");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    
}


class Car : Device
{
    public Car(string name, string characteristics) : base(name, characteristics){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: VIVIVIVIVIVIVI(Tipa zhiguli zavoditsya)");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    
}

class Boat : Device
{
    public Boat(string name, string characteristics) : base(name, characteristics){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: VSHOOOOVSHOOOOO");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    
}



class Program
{
    static void Main(string[] args)
    {
        Device kettle = new Kettle("Bork", "Boils water");
        Device car = new Car("Porsche Cayenne", "Headlights often disappear");
        Device boat = new Boat("Buster", "Walks quickly on water");
        Device microwave = new Microwave("Philipps", "Heats food well");

        kettle.Show();
        kettle.Desc();
        kettle.Sound();

        Console.WriteLine();
        
        car.Show();
        car.Desc();
        car.Sound();
        
        Console.WriteLine();
        
        boat.Show();
        boat.Desc();
        boat.Sound();
        
        Console.WriteLine();
        
        microwave.Show();
        microwave.Desc();
        microwave.Sound();

    }
}



#endregion Task2


#region Task3

class MusicalInstrument
{
    protected string Name;
    protected string Characteristics;
    protected string History;
    
    public MusicalInstrument(string name, string characteristics, string history)
    {
        Name = name;
        Characteristics = characteristics;
        History = history;
    }


    public virtual void Sound()
    {
        Console.WriteLine($"Sound of {Name} : ............");
    }
    
    public virtual void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }
    
    public virtual void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    public virtual void IHistory()
    {
        Console.WriteLine($"History: {History}");
    }
}

class Violin  : MusicalInstrument
{
    public Violin(string name, string characteristics, string history) : base(name, characteristics, history){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: TUTUTUTUTUTUU");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }

    public override void IHistory()
    {
        Console.WriteLine($"History: {History}");
    }
}


class Trombone  : MusicalInstrument
{
    public Trombone(string name, string characteristics,string history) : base(name, characteristics,history){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: BUUUUMBUUUUUUUUBUUUU");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    public override void IHistory()
    {
        Console.WriteLine($"History: {History}");
    }
    
}


class Ukulele : MusicalInstrument
{
    public Ukulele(string name, string characteristics,string history) : base(name, characteristics,history){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: TRUNTRUNTRUNTRUNTRUNTRUNTRUNTR");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    public override void IHistory()
    {
        Console.WriteLine($"History: {History}");
    }
}

class Cello : MusicalInstrument
{
    public Cello(string name, string characteristics,string history) : base(name, characteristics,history){}

    public override void Sound()
    {
        Console.WriteLine($"Sound of {Name}: UUUUUIIIUUUUIIIIUUUUU");
    }

    public override void Show()
    {
        Console.WriteLine($"Name: {Name}");
    }

    public override void Desc()
    {
        Console.WriteLine($"Characteristics: {Characteristics}");
    }
    
    public override void IHistory()
    {
        Console.WriteLine($"History: {History}");
    }
}



class Program
{
    static void Main(string[] args)
    {
        MusicalInstrument violin = new Violin("Nazvanie skripki", "Krasivo zvuchit","Bila sozdana davno");
        MusicalInstrument trombone = new Trombone("Nazvanie trombona", "Krasivo zvuchit","Bila sozdana davno");
        MusicalInstrument ukulele = new Ukulele("Nazvanie ukulele", "Krasivo zvuchit","Bila sozdana davno");
        MusicalInstrument cello = new Cello("Nazvanie violoncheli", "Krasivo zvuchit","Bila sozdana davno");

        violin.Show();
        violin.Desc();
        violin.Sound();
        violin.IHistory();

        Console.WriteLine();
        
        trombone.Show();
        trombone.Desc();
        trombone.Sound();
        trombone.IHistory();
        
        Console.WriteLine();
        
        ukulele.Show();
        ukulele.Desc();
        ukulele.Sound();
        ukulele.IHistory();
        
        Console.WriteLine();
        
        cello.Show();
        cello.Desc();
        cello.Sound();
        cello.IHistory();

    }
}


#endregion Task3


#region Task4

using System.Formats.Asn1;

abstract class Worker
{
    public string Name;


    public Worker(string name)
    {
        Name = name;
    }

    public abstract void Print();


}

class President : Worker
{
    public President(string name) : base(name) {}

    public override void Print()
    {
        Console.WriteLine($"President's name: {Name}");
    }
    
}

class Security : Worker
{
    public Security(string name) : base(name) {}
    
    public override void Print()
    {
        Console.WriteLine($"Security's name: {Name}");
    }
}

class Manager : Worker
{
    public Manager(string name) : base(name) {}
    
    public override void Print()
    {
        Console.WriteLine($"Manager's name: {Name}");
    }
}

class Engineer : Worker
{
    public Engineer(string name) : base(name) {}
    
    public override void Print()
    {
        Console.WriteLine($"Engineer's name: {Name}");
    }
}


class Program
{
    static void Main()
    {
        Worker worker = new President("Igor");
        Worker worker2 = new Engineer("Andrey");
        Worker worker3 = new Manager("Ivan");
        Worker worker4 = new Security("Vova");

        worker.Print();
        worker2.Print();
        worker3.Print();
        worker4.Print();

    }
}



#endregion Task4