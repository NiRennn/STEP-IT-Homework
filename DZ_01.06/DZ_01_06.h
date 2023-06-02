#include "iostream"
using namespace std;
#include <string>
#include "CPU.h"
#include "RAM.h"
#include "VideoCard.h"
#include "MotherBoard.h"

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
