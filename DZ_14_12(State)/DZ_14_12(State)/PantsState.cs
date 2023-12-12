using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_14_12_State_
{
     class PantsState : IClothingState
    {


        private string[] availableColors = { "Black", "Brown", "Gray" };
        private int currentIndex = 0;

        public void Dress(Character character)
        {
            character.Pants = availableColors[currentIndex];
            Console.WriteLine($"Wearing {character.Pants} pants.");
        }

        public void NextState()
        {
            currentIndex = (currentIndex + 1) % availableColors.Length;
        }

        public void PreviousState()
        {
            currentIndex = (currentIndex - 1 + availableColors.Length) % availableColors.Length;
        }
    }
}
