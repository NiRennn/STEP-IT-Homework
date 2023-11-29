using DZ_03._12_Computers_.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03._12_Computers_.Classes
{
    public class GamingComputerBuilder : IComputerBuilder
    {
        private Computer computer = new Computer();


        public void BuildProcessor()
        {
            computer.Processor = "Intel Core i7";
        }

        public void BuildMemory()
        {
            computer.Memory = "32GB";
        }

        public void BuildVideoCard()
        {
            computer.VideoCard = "GeForce RTX 3060";
        }

        public void BuildHardDisk()
        {
            computer.HardDisk = "1TB ";
        }

        public Computer GetComputer()
        {
            return computer;
        }
    }
}
