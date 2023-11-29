using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03._12_Computers_.Classes
{
    public class Computer
    {
        public string Processor;
        public string Memory;
        public string VideoCard;
        public string HardDisk;

        public void DisplayInformation()
        {
            Console.WriteLine($"Processor: {Processor}\n" +
                $"Memory: {Memory}\n" +
                $"VideoCard: {VideoCard}\n" +
                $"HardDisk: {HardDisk}");

        }
    }
}
