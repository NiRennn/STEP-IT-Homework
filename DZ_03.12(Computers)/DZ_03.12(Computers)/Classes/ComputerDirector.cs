using DZ_03._12_Computers_.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03._12_Computers_.Classes
{
    public class ComputerDirector
    {

        public void ConstructComuter(IComputerBuilder builder)
        {
            builder.BuildProcessor();
            builder.BuildVideoCard();
            builder.BuildMemory();
            builder.BuildHardDisk();
        }
    }
}
