using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_14_12_State_
{
    class T_ShirtState : IClothingState
    {
        private string[] tshirtColors = { "Red T-Shirt", "Blue T-Shirt", "Green T-Shirt" };
        private int index = 0;

        public void Dress(Character character)
        {
            character.TShirt = tshirtColors[index];
            Console.WriteLine($"Wearing a {character.TShirt}");
        }

        public void NextState()
        {
            index = (index + 1) % tshirtColors.Length;
        }
        public void PreviousState()
        {
            index = (index - 1 + tshirtColors.Length) % tshirtColors.Length;
        }
    }
}
