

using DZ_03._12_Computers_.Classes;

var officeBuilder = new OfficeComputerBuilder();
var gamingBuilder = new GamingComputerBuilder();
var designerBuilder = new DesignerComputerBuilder();

var director = new ComputerDirector();




director.ConstructComuter(officeBuilder);

var officeComputer = officeBuilder.GetComputer();
Console.WriteLine("Office computer setup: ");
officeComputer.DisplayInformation();
Console.WriteLine("---------------------------");


director.ConstructComuter(gamingBuilder);

var gamingComputer = gamingBuilder.GetComputer();
Console.WriteLine("Gaming computer setup: ");
officeComputer.DisplayInformation();
Console.WriteLine("---------------------------");


director.ConstructComuter(designerBuilder);

var designerComputer = designerBuilder.GetComputer();
Console.WriteLine("Designer computer setup: ");
officeComputer.DisplayInformation();