#include "DZ_04.06.h"


void VideoCard :: createVideoCard()
{
    cout << "Enter video card memory size: ";
    cin >> videoMemorySize;
    cout << "Enter video card memory type: ";
    cin >> videoMemoryType;
    cout << "Enter GPU: ";
    cin >> GPU;
    cout << "Enter video card memory frequency: ";
    cin >> memoryFrequency;

}

void VideoCard :: printVideoCard() const
{
    cout << "Video card memory size: " << videoMemorySize << endl;
    cout << "Video memory type: " << videoMemoryType << endl;
    cout << "GPU: " << GPU << endl;
    cout << "Memory frequency: " << memoryFrequency << endl;
}