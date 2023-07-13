#include "iostream"
using namespace std;

#include <string>

//#include "CPU.h"
#include "RAM.h"
#include "VideoCard.h"
#include "MotherBoard.h"

class Computer
{
public:
    Motherboard* motherboard;
    RAM* operativka;
    VideoCard* videocard;


    Computer() = default;


    Computer(Motherboard &motherboard, RAM &operativka, VideoCard& videoCard)
    {
        this->motherboard = new Motherboard(motherboard);
        this->operativka = new RAM(operativka);
        this->videocard = new VideoCard(videoCard);
    }


    Computer(const Computer& c)
    {
        motherboard = c.motherboard;
        operativka = c.operativka;
        videocard = c.videocard;
    }
};
