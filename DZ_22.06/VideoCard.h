#include <iostream>
using namespace std;


struct VideoCard {
public:
    int *videoMemorySize{};
    string videoMemoryType{};
    int *GPU{};
    int *memoryFrequency{};

    VideoCard() = default;

    VideoCard(int videoMemorySize, string videoMemoryType, int GPU, int memoryFrequency)
    {
        this->videoMemorySize = new int(videoMemorySize);
        this->videoMemoryType = videoMemoryType;
        this->GPU = new int(GPU);
        this->memoryFrequency = new int(memoryFrequency);
    }



    void createVideoCard();
    void printVideoCard() const;
};


