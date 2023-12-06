using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Classes
{
    class HomeTable : ITable
    {
        public string material = "Wood";
        public int legs = 5;
        public string form = "Circle";

        public void PutOnTable()
        {
            Console.WriteLine("Place on home table.");
        }

        public void TableInfo()
        {
            Console.WriteLine($"Table material: {material}, count of legs:{legs}, table form:{form}.");
        }
    }
}
