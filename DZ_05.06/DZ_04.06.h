#include "iostream"
using namespace std;
#include <string>
#include "CPU1.h"
#include "RAM1.h"
#include "VideoCard1.h"
#include "MotherBoard1.h"
#include "Component.h"

class Computer
{
public:
    Motherboard motherboard;
    CPU processor;
    RAM operativka;
    VideoCard videocard;


    Computer() = default;

    Computer(CPU processor,Motherboard motherboard, RAM operativka, VideoCard videocard )
    {
        this->processor = processor;
        this->motherboard = motherboard;
        this->operativka = operativka;
        this->videocard = videocard;
    }
};
