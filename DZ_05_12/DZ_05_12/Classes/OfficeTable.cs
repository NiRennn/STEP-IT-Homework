using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Classes
{
    class OfficeTable : ITable
    {
        public string material = "Chipboard";
        public string form = "Rectangle";
        public int legs = 4;


        public void PutOnTable()
        {
            Console.WriteLine("Place on office table");
        }

        public void TableInfo()
        {
            Console.WriteLine($"Table material: {material}, count of legs:{legs}, table form:{form}.");
        }
    }
}
