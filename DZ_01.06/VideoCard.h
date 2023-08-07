#include <iostream>
using namespace std;


struct VideoCard {
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



    void createVideoCard();
    void printVideoCard() const;
};


