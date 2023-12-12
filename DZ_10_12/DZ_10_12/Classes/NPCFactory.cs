using DZ_10_12.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_10_12.Classes
{
    class NPCFactory
    {
        private Dictionary<string, INPC> NPCflyweights = new Dictionary<string, INPC>();

        public INPC GetNPC(string race, string clothColor, int health)
        {
            string key = $"{race}_{clothColor}_{health}";

            if (!NPCflyweights.ContainsKey(key))
            {
                NPCflyweights[key] = new SharedNPC(race, clothColor, health);
            }

            return NPCflyweights[key];
        }
    }
}
