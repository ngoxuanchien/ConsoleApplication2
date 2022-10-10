#include "FAT32.h"
#include "NTFS.h"
using namespace std;

int main()
{

    FAT32 result;
    result.readBootSector(L"\\\\.\\D:");

    // Read NTFS PBS
    NTFS read;
    read.readPBS(L"\\\\.\\G:");
    read.xuat();
    //result.output();
    ///result.readFile(L"\\\\.\\D:");

    return 0;
}
