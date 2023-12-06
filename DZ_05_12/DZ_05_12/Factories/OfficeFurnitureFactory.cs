﻿using DZ_05_12.Classes;
using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Factories
{
    class OfficeFurnitureFactory : IFurnitureFactory
    {
        public IChair CreateChair()
        {
            return new OfficeChair();
        }

        public ITable CreateTable()
        {
            return new OfficeTable();

        }
    }
}
