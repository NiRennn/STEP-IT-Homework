#include <iostream>
using namespace std;


class VideoCard {
public:
    int videoMemorySize{};
    string videoMemoryType{};
    int GPU{};
    int memoryFrequency{};

    VideoCard() = default;

    VideoCard(int videoMemorySize, string videoMemoryType, int GPU, int memoryFrequency)
    {
        this->videoMemorySize = videoMemorySize;
        this->videoMemoryType = videoMemoryType;
        this->GPU = GPU;
        this->memoryFrequency = memoryFrequency;
    }




};


