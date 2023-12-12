using DZ_10_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_10_12.Classes
{
    class SharedNPC : INPC
    {
        public string Race;
        public string ClothColor;
        public int Health;

        public SharedNPC(string race,string clothColor,int health)
        {
            this.Race = race;
            this.ClothColor = clothColor;
            this.Health = health;
        }
        public void DisplayPosition(int x, int y)
        {
            Console.WriteLine($"NPC is located at coordinates: {x},{y}.\nRace: {Race}\nCloth: {ClothColor}\nHealth: {Health}.");
            Console.WriteLine("-------------------------------------");
        }
    }
}
