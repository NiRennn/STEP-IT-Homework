#include <iostream>
using namespace std;
#include "Component.h"


class VideoCard : public Component{
public:
    int videoMemorySize{};
    string videoMemoryType{};
    int GPU{};
    int memoryFrequency{};

    VideoCard() = default;

    VideoCard(string make, string model, string serialNumber, int videoMemorySize, string videoMemoryType, int GPU, int memoryFrequency) : Component(make, model, serialNumber)
    {
        this->videoMemorySize = videoMemorySize;
        this->videoMemoryType = videoMemoryType;
        this->GPU = GPU;
        this->memoryFrequency = memoryFrequency;
    }



    void createVideoCard();
    void printVideoCard() const;
};


