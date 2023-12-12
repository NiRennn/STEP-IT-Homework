using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_14_12_State_
{
     interface IClothingState
    {
        void Dress(Character character);
        void NextState();
        void PreviousState();
    }
}
