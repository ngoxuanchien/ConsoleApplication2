#include "Function.h"

using namespace std;

int main()
{
    BYTE* sector;
    sector = new BYTE[4096];
    LARGE_INTEGER readPoint;
    readPoint.QuadPart = 7532978176;
    if (readByte(L"\\\\.\\D:", readPoint, sector, 4096))
    {
        for (int i = 0; i < 4096; i++)
        {
            if (i % 16 == 0)
            {
                cout << endl;
            }
            cout << toHex(sector[i]) << " ";

        }
    }
    delete[] sector;

    return 0;
}
