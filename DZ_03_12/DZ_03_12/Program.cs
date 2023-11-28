using DZ_03_12.Classes;
using DZ_03_12.Factory;
using DZ_03_12.Interfaces;

IAutomobileFactory sedanFactory = new SedanFactory();
IAutomobileFactory suvFactory = new SUVFactory();
IAutomobileFactory truckFactory = new TruckFactory();


IAutomobile sedan = sedanFactory.CreateAutomobile();
IAutomobile suv = suvFactory.CreateAutomobile();
IAutomobile truck = truckFactory.CreateAutomobile();

sedan.GetModelInfo();
suv.GetModelInfo();
truck.GetModelInfo();


