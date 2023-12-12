using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_14_12_State_
{
    public class Character
    {

        public string TShirt { get;  set; }
        public string Pants { get;  set; }
        public string Shoes { get;  set; }

        IClothingState tshirtState;
        IClothingState pantsState;
        IClothingState shoesState;

        public Character()
        {
            tshirtState = new T_ShirtState();
            pantsState = new PantsState();
            shoesState = new ShoesState();
        }

        public void Dress()
        {
            tshirtState.Dress(this);
            pantsState.Dress(this);
            shoesState.Dress(this);
        }

        public  void NextTShirtState()
        {
            tshirtState.NextState();
        }
        public  void PreviousTShirtState() 
        {

            tshirtState.PreviousState();
        }
        public  void NextPantsState()
        {
            pantsState.NextState();

        }
        public  void PreviousPantsState()
        {
            pantsState.PreviousState();

        }
        public  void NextShoesState()
        {
            shoesState.NextState();

        }
        public  void PreviousShoesState()
        {
            shoesState.PreviousState();

        }
    }
}


