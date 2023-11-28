using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DZ_03_12.Interfaces;

namespace DZ_03_12.Classes
{
    internal class Truck : IAutomobile
    {
        public string Make { get; set; }
        public string Model { get; set; }
        public int Year { get; set; }
        public void GetModelInfo()
        {
            Console.WriteLine($"Truck information: Mark:{Make}, Model:{Model}, Year:{Year}");
        }
    }
}
