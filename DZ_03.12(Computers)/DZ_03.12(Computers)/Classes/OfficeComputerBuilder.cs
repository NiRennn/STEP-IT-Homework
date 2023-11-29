using DZ_03._12_Computers_.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03._12_Computers_.Classes
{
    public class OfficeComputerBuilder : IComputerBuilder
    {
        private Computer computer = new Computer();


        public void BuildProcessor()
        {
            computer.Processor = "Intel Core i5";
        }

        public void BuildMemory()
        {
            computer.Memory = "8GB";
        }

        public void BuildVideoCard()
        {
            computer.VideoCard = "Integrated";
        }

        public void BuildHardDisk()
        {
            computer.HardDisk = "240GB";
        }

        public Computer GetComputer()
        {
            return computer;
        }
    }
}
