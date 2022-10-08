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

/// <summary>
/// Chuyen hexa sang nhi phan
/// </summary>
/// <param name="hexdec">day hexa can chuyen</param>
/// <returns>day bin</returns>
string hexToBin(string hexdec)
{
    string result = "";
    int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            result += "0000";
            break;
        case '1':
            result += "0001";
            break;
        case '2':
            result += "0010";
            break;
        case '3':
            result += "0011";
            break;
        case '4':
            result += "0100";
            break;
        case '5':
            result += "0101";
            break;
        case '6':
            result += "0110";
            break;
        case '7':
            result += "0111";
            break;
        case '8':
            result += "1000";
            break;
        case '9':
            result += "1001";
            break;
        case 'A':
        case 'a':
            result += "1010";
            break;
        case 'B':
        case 'b':
            result += "1011";
            break;
        case 'C':
        case 'c':
            result += "1100";
            break;
        case 'D':
        case 'd':
            result += "1101";
            break;
        case 'E':
        case 'e':
            result += "1110";
            break;
        case 'F':
        case 'f':
            result += "1111";
            break;
        }
        i++;
    }

    return result;
}

/// <summary>
/// chuyen hexa sang dec
/// </summary>
/// <param name="hex">day hex can chuyen</param>
/// <returns>gia tri chuyen</returns>
long long hexToDec(string hex)
{
    long long result = 0;

    result = stoi(hex, 0, 16);

    return result;
}
