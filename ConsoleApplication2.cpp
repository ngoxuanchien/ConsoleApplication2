#include "FAT32.h"
using namespace std;

int main()
{
    FAT32 result;
    result.readBootSector(L"\\\\.\\D:");
    //result.output();
    result.readFile(L"\\\\.\\D:");

    return 0;
}
