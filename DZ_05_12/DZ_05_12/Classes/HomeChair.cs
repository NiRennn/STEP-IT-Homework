using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Classes
{
    class HomeChair : IChair
    {
        public string material = "Wood";
        public int legs = 4;

        public void ChairInfo()
        {
            Console.WriteLine($"Chair material: {material}, count of legs: {legs}");
        }


        public void SitOnChair()
        {
            Console.WriteLine("Sit on an home chair.");
        }
    }
}
