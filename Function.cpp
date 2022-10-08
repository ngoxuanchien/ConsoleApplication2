#include "Function.h"

/// <summary>
/// doc byte tu o cung
/// </summary>
/// <param name="drive">o dia can doc</param>
/// <param name="readPoint">vi tri can doc</param>
/// <param name="sector">ket qua duoc luu</param>
/// <param name="size">so byte can doc</param>
/// <returns>0 hoac 1</returns>
int readByte(LPCWSTR drive, LARGE_INTEGER readPoint, BYTE* sector, int size)
{
	//sector = new BYTE[size];
	DWORD bytesRead;
	HANDLE device = NULL;

    device = CreateFile(drive,              // Drive to open
        GENERIC_READ,                       // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE, // Share Mode
        NULL,                               // Security Descriptor
        OPEN_EXISTING,                      // How to 
        0,                                  // File attributes
        NULL);                              // Handle to template

    if (device == INVALID_HANDLE_VALUE) // Open 
    {
        printf("CreateFile: %u\n", GetLastError());
        return 0;
    }

    SetFilePointerEx(device, readPoint, NULL, FILE_BEGIN); // Set a Point to Read	

    if (!ReadFile(device, sector, size, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
        return 0;
    }
    else
    {
        CloseHandle(device);
        return 1;
    }
}

/// <summary>
/// chuyen byte sang hexa
/// </summary>
/// <param name="data">byte can chuyen</param>
/// <returns>day hexa chuyen duoc</returns>
string toHex(int data)
{

    static vector<char> hexMap = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    string result = "";

    while (data > 0)
    {
        int cur = data % 16;
        result = hexMap[cur] + result;
        data = data / 16;
    }

    while (result.length() < 2)
    {
        result = "0" + result;
    }

    return result;
}

/// <summary>
/// chuyen day hexa sang chuoi ascii
/// </summary>
/// <param name="hex">day hexa can chuyen</param>
/// <returns>chuoi ascii chuyen duoc</returns>
string hexToASCII(string hex)
{
    string ascii = "";

    for (size_t i = 0; i < hex.length(); i += 2)
    {
        string part = hex.substr(i, 2);

        char ch = stoul(part, nullptr, 16);

        ascii += ch;
    }

    return ascii;
}
