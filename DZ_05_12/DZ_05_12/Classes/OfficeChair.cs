using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Classes
{
    class OfficeChair : IChair
    {
        public string material = "Plastic";
        public int legs = 1;
        public int wheels = 5;
        public void ChairInfo()
        {
            Console.WriteLine($"Chair material: {material}, count of legs: {legs}, count of wheels: {wheels}.");
        }

        public void SitOnChair()
        {
            Console.WriteLine("Sit on an office chair.");
        }
    }
}
