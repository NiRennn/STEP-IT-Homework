using DZ_03._12_Computers_.Classes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03._12_Computers_.Interfaces
{
    public interface IComputerBuilder
    {
        void BuildProcessor();
        void BuildMemory();
        void BuildVideoCard();
        void BuildHardDisk();
        
        Computer GetComputer();

    }
}
