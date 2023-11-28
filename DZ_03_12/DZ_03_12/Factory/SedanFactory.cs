using DZ_03_12.Classes;
using DZ_03_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_03_12.Factory
{
    internal class SedanFactory : IAutomobileFactory
    {
        public IAutomobile CreateAutomobile()
        {
            return new Sedan { Make = "Toyota", Model = "Camry", Year = 2020 };
        }
    }
}
