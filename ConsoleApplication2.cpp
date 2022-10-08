#include "Function.h"

using namespace std;

int main()
{
    BYTE* sector;
    sector = new BYTE[4096];
    LARGE_INTEGER readPoint;
    readPoint.QuadPart = 7532978176;
    string temp = "";
    if (readByte(L"\\\\.\\D:", readPoint, sector, 4096))
    {
        for (int i = 0; i < 4096; i++)
        {
            /*if (i % 16 == 0)
            {
                cout << endl;
            }*/
            temp = temp + toHex(sector[i]);

        }
    }
    cout << hexToASCII(temp);
    delete[] sector;

   /* for (int i = 0; i < 100; i++)
    {
        cout << toHex(i) << " : " << HexToBin(toHex(i)) << endl;
    }
    cout << endl;*/

    return 0;
}
