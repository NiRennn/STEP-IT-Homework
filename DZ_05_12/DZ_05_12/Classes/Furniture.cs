using DZ_05_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_05_12.Classes
{
    class Furniture
    {
        private IFurnitureFactory _factory;

        public Furniture(IFurnitureFactory factory)
        {
            _factory = factory;
        }

        public void UseFurniture()
        {
            var chair = _factory.CreateChair();
            var table = _factory.CreateTable();

            chair.SitOnChair();
            chair.ChairInfo();
            table.PutOnTable();
            table.TableInfo();
            Console.WriteLine(new string('=',65));

        }
    }
}
