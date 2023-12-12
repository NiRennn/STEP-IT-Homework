using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_14_12_State_
{
    class ShoesState : IClothingState
    {
        private string[] availableColors = { "White", "Black", "Brown" };
        private int currentIndex = 0;

        public void Dress(Character character)
        {
            character.Shoes = availableColors[currentIndex];
            Console.WriteLine($"Wearing {character.Shoes} shoes.");
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
