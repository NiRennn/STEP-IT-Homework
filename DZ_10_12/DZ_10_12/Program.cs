
using DZ_10_12.Classes;
using DZ_10_12.Interfaces;

NPCFactory npcFactory = new NPCFactory();

INPC human = npcFactory.GetNPC("Human", "Blue pants,black t-shirt", 100);
INPC elf = npcFactory.GetNPC("Elf", "Cloak with hood", 80);
INPC orc = npcFactory.GetNPC("Orc", "Iron armor", 120);

human.DisplayPosition(111, 15);
elf.DisplayPosition(452, 77);
orc.DisplayPosition(650, 140);