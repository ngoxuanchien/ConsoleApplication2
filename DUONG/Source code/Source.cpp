#include"Header.h"

int spc = 0;
atribute readatr(string atri)
{
    atribute temp;
    temp.read_only = atri[7] & 1;
    temp.hidden = atri[6] & 1;
    temp.system = atri[5] & 1;
    temp.vollabel = atri[4] & 1;
    temp.directory = atri[3] & 1;
    temp.archive = atri[2] & 1;
    return temp;
}

int ReadSector(LPCWSTR  drive, int readPoint, BYTE sector[512])
{
    int retCode = 0;
    DWORD bytesRead;
    HANDLE device = NULL;

    device = CreateFile(drive,    // Drive to open
        GENERIC_READ,           // Access mode
        FILE_SHARE_READ | FILE_SHARE_WRITE,        // Share Mode
        NULL,                   // Security Descriptor
        OPEN_EXISTING,          // How to create
        0,                      // File attributes
        NULL);                  // Handle to template

    if (device == INVALID_HANDLE_VALUE) // Open Error
    {
       printf("CreateFile: %u\n", GetLastError());
        return 1;
    }

    SetFilePointer(device, readPoint*512, NULL, FILE_BEGIN);//Set a Point to Read

    if (!ReadFile(device, sector, 512, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
    }
}



void tohex (BYTE data[][COL], vector<vector<string>>&a)
{
    for (int i(0); i < 32; ++i)
    {
        a.emplace_back();
        for (int j = 0; j < 16; j++)
        {
            stringstream ss;
            ss << hex;
            ss << setw(2) << setfill('0') << (int)data[i][j];
            a.back().push_back(ss.str());
        }
    }
    int k = 0;
    cout << "      ";
    for (int i = 0; i < 16; i++)
    {
        cout << " ";
        if (i < 10)
            cout << i;
        else
            cout << char(i - 10 + 'A');

        if (i == 7)
            cout << " ";
        cout << " ";
    }
    cout << endl;

    int temp = 0;
    for (int i = 0; i < 32; i++)
    {
        if (0 == k)
            cout << "0x000  ";
        else if (k < 10 && k > 0)
        {
            cout << "0x0" << k << "0  ";
        }
        else if (k <= 15 && k >= 10)
        {
            char c = k + 87;
            cout << "0x0" << c << "0  ";
        }
        else if(k > 15 && k <= 25 )
        {
            cout <<"0x1" << temp << "0  ";
            temp++;
        }
        else
        {
            char c = k + 71;
            cout << "0x1" << c << "0  ";
        }
        for (int j = 0; j < 16; j++)
        {
            cout << a[i][j] << " ";
            if (j == 7)
                cout << " ";
        }
        cout << endl;
        k++;
    }
}

int toNumber(BYTE* sector, int position, int number)
{
    int k = 0;
    memcpy(&k, sector + position, number);
    return k;
}

string toString(BYTE* sector, int position, int number)
{
    char* tmp = new char[number + 1];
    memcpy(tmp, sector + position, number);
    string s = "";
    for (int i = 0; i < number; i++)
        if (tmp[i] != 0x00 && tmp[i] != char(0xff))
            s += tmp[i];

    return s;
}

string typeofFAT(vector<vector<string>> a)
{
    // initialize the ASCII code string as empty.
    string b = "No";
    if (a[3][6] == "00")
        return b;
    string ascii = "";
    for (int i = 6; i <= 14; i++)
    {
        // extract two characters from hex string
        string part = a[3][i];

        // change it into base 16 and
        // typecast as the character
        char ch = stoul(part, nullptr, 16);

        // add this char to final ASCII string
        ascii += ch;
    }
    return ascii;
}

bool isNumber(const string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

long int docbyte(vector<vector<string>> a, int n, int m, int sobytecandoc)
{
    long int sum = 0;
    string temp;
    for (int i = sobytecandoc - 1; i >= 0; i--)
    {
        //cout << a[m][n+i] << "," << endl;
        temp = temp + a[m][n + i];
    }
    //cout << temp << endl;
    return stol(temp, nullptr, 16);
}

//1:entry chinh       0:entry phu

int checkEntry(string a)
{
    if (a != "0f" && a != "0F")
        return 1;
    else
        return 2;
}

//convert hex to ascii
unsigned char hexval(unsigned char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    else if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    else if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    else abort();
}

string hex2ascii(const string& in, string& out)
{
    out.clear();
    out.reserve(in.length() / 2);
    for (string::const_iterator p = in.begin(); p != in.end(); p++)
    {
        unsigned char c = hexval(*p);
        p++;
        if (p == in.end()) break; // incomplete last digit - should report error
        c = (c << 4) + hexval(*p); // + takes precedence over <<
        out.push_back(c);
    }
    return out;
}

//hex to bin
void HexToBin(string &hexdec)
{
    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                << hexdec[i];
        }
        i++;
    }
}
string decToBinary(int n)
{
    string s = "";
    // Size of an integer is assumed to be 32 bits
    for (int i = 7; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            s += "1";
        else
            s += "0";
    }
    return s;
}

void readFile(unsigned int start, int number)
{
    int k = 0;
   
    while (true)
    {
       if (number > 0)
       {
           if (number <= 512)
           {
               BYTE sector[512];
               ReadSector(L"\\\\.\\D:", start + k, sector);
               string line = toString(sector, 0x00, number);
               cout << "\t" << line << endl;
               number = number - 512;
            }
           else
           {
               BYTE sector[512];
               ReadSector(L"\\\\.\\D:", start + k, sector);
               string line = toString(sector, 0x00, 512);
               cout << "\t" << line << endl;
               number = number - 512;
               k = k + 1;
           }

        }
        else
        {
            break;
        }   
    }


}

void readRDET(int SRDET)
{
    int k = 0;
    string temp = "";
    int count = 0;
    while (true)
    {
        bool checkend = false;
        BYTE sector[512];
        ReadSector(L"\\\\.\\D:", SRDET+k, sector);
        for (int i = 0; i < 512; i = i + 32)
        {
            if (sector[i] == 0xe5)
            {
                continue;
            }
            if (sector[i] == 0x00)
            {
                checkend = true;
                break;
            }
            if (sector[0x0B + i]== 0x0f)
            {

                temp = toString(sector, 0x01 + i, 10) + toString(sector, 0x0E + i, 12) + toString(sector, 0x1C + i, 4) + temp;
                count++;
                
            }
            else
            {
                if (count != 0)
                {
                    unsigned int high = toNumber(sector, 0x14 + i, 2);
                    unsigned int low = toNumber(sector, 0x1A + i, 2);
                    unsigned int total = high + low;
                    cout << "ten thu muc tep tin :" << temp << endl;
                    cout << "kich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << endl;
                    cout << "trang thai : ";
                    int temp2 = toNumber(sector, 0x0b + i, 1);
                    atribute temp1;
                    string temp3 = decToBinary(temp2);
                    temp1 = readatr(temp3);
                    if (temp1.archive == 1)
                    {
                        cout << "archive" << " ";
                    }
                    if (temp1.hidden == 1)
                    {
                        cout << "hidden" << " ";
                    }
                    if (temp1.system == 1)
                    {
                        cout << "system" << " ";
                    }
                    if (temp1.read_only == 1)
                    {
                        cout << "read only" << " ";
                    }
                    if (temp1.vollabel == 1)
                    {
                        cout << "vollabel" << " ";
                    }
                    if (temp1.directory == 1)
                    {
                        cout << "directory" << " ";
                    }
                    cout << endl;

                    cout << "cluster bat dau : " << total << endl;
                    if (total != 0x0)
                    {
                        cout << "Chiem cac sector :";
                        for (int i = 0; i < spc; i++)
                        {
                            cout << (total - 2) * spc - SRDET + i << " ";
                        }
                        cout << endl;
                    }
                    if (temp1.directory == 1 && temp1.system != 1)
                    {
                        cout << "tap tin thu muc con : " << endl;
                        readSDET((total - 2) * spc + SRDET);
                        cout << "------------------------" << endl;
                    }
                    if (temp[temp.length() - 1] == 't' && temp[temp.length() - 2] == 'x' && temp[temp.length() - 3] == 't' && temp1.archive == 1)
                    {
                        readFile((total-2)*spc+SRDET, toNumber(sector, 0x1C + i, 4));
                    }
                    else if (temp[temp.length() - 1] != 't' && temp[temp.length() - 2] != 'x' && temp[temp.length() - 3] != 't' && temp1.archive == 1)
                    {
                        cout << "dung chuong trinh khac de doc " << endl;
                    }
                    temp = "";
                    count = 0;
                }
                else
                {
                    if (toString(sector, 0x08 + i, 3) != "   ")
                    {
                        unsigned int high = toNumber(sector, 0x14 + i, 2);
                        unsigned int low = toNumber(sector, 0x1A + i, 2);
                        unsigned int total = high + low;
                        cout << "ten thu muc tep tin:" << toString(sector, 0x00 + i, 8) << endl;
                        cout << "phan mo rong :" << toString(sector, 0x08 + i, 3) << endl;
                        cout << "kich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << " bytes" << endl;
                        cout << "trang thai : ";
                        int temp = toNumber(sector, 0x0b + i, 1);
                        atribute temp1;
                        string temp2 = decToBinary(temp);
                        temp1 = readatr(temp2);
                        if (temp1.archive == 1)
                        {
                            cout << "archive" << " ";
                        }
                        if (temp1.hidden == 1)
                        {
                            cout << "hidden" << " ";
                        }
                        if (temp1.system == 1)
                        {
                            cout << "system" << " ";
                        }
                        if (temp1.read_only == 1)
                        {
                            cout << "read only" << " ";
                        }
                        if (temp1.vollabel == 1)
                        {
                            cout << "vollabel" << " ";
                        }
                        if (temp1.directory == 1)
                        {
                            cout << "directory" << " ";
                        }
                        cout << endl;
                        cout << "cluster bat dau : " << total << endl;
                        if (total != 0x0)
                        {
                            cout << "Chiem cac sector :";
                            for (int i = 0; i < spc; i++)
                            {
                                cout << (total - 2) * spc - SRDET + i << " ";
                            }
                            cout << endl;
                        }
                        if (temp1.directory == 1 && temp1.system != 1)
                        {
                            cout << "tap tin thu muc con : " << endl;
                            readSDET((total - 2) * spc + SRDET);
                        }
                        cout << endl;
                        if (temp1.archive == 1 && toString(sector, 0x08 + i, 3) == "TXT")
                        {
                            readFile((total - 2)* spc + SRDET, toNumber(sector, 0x1C + i, 4));
                        
                        }
                    }
                    else
                    {
                        unsigned int high = toNumber(sector, 0x14 + i, 2);
                        unsigned int low = toNumber(sector, 0x1A + i, 2);
                        unsigned int total = high + low;
                        cout << "ten thu muc :" << toString(sector, 0x00 + i, 8) << endl;
                        cout << "kich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << endl;
                        cout << "trang thai : " ;
                        int temp = toNumber(sector, 0x0b+i, 1);
                        atribute temp1;
                        string temp2 = decToBinary(temp);
                        temp1 = readatr(temp2);
                        if (temp1.archive == 1)
                        {
                            cout << "archive" << " ";
                        }
                        if (temp1.hidden == 1)
                        {
                            cout << "hidden" << " ";
                        }
                        if (temp1.system == 1)
                        {
                            cout << "system" << " ";
                        }
                        if (temp1.read_only == 1)
                        {
                            cout << "read only" << " ";
                        }
                        if (temp1.vollabel == 1)
                        {
                            cout << "vollabel" << " ";
                        }
                        if (temp1.directory == 1)
                        {
                            cout << "directory" << " ";
                        }
                        cout << endl;
                        cout << "cluster bat dau : " << total << endl;
                        if (total != 0x0)
                        {
                            cout << "Chiem cac sector :";
                            for (int i = 0; i < spc; i++)
                            {
                                cout << (total - 2) * spc - SRDET + i << " ";
                            }
                            cout << endl;
                        }
                        if (temp1.directory == 1 && temp1.system != 1)
                        {
                            cout << "tap tin thu muc con : " << endl;
                            readSDET((total - 2)* spc + SRDET);
                            
                        }
                    }
                }
            }
            
        }
        if (checkend == true)
        {
            break;
        }
        else
        {
            k++;

        }
    }
}
void readSDET(int SRDET)
{
    int k = 0;
    string temp = "";
    int count = 0;
    while (true)
    {
        bool checkend = false;
        BYTE sector[512];
        ReadSector(L"\\\\.\\D:", SRDET + k, sector);
        for (int i = 64; i < 512; i = i + 32)
        {
            if (sector[i] == 0xe5)
            {
                continue;
            }
            if (sector[i] == 0x00)
            {
                checkend = true;
                break;
            }
            if (sector[0x0B + i] == 0x0f)
            {
                temp = toString(sector, 0x01 + i, 10) + toString(sector, 0x0E + i, 12) + toString(sector, 0x1C + i, 4) + temp;
                count++;
            }
            else
            {
                if (count != 0)
                {
                    unsigned int high = toNumber(sector, 0x14 + i, 2);
                    unsigned int low = toNumber(sector, 0x1A + i, 2);
                    unsigned int total = high + low;
                    cout << "\tten tap tin thu muc :" << temp << endl;
                    cout << "\tkich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << endl;
                    cout << "\ttrang thai : ";
                    int temp2 = toNumber(sector, 0x0b + i, 1);
                    atribute temp1;
                    string temp3 = decToBinary(temp2);
                    temp1 = readatr(temp3);
                    if (temp1.archive == 1)
                    {
                        cout << "archive" << " ";
                    }
                    if (temp1.hidden == 1)
                    {
                        cout << "hidden" << " ";
                    }
                    if (temp1.system == 1)
                    {
                        cout << "system" << " ";
                    }
                    if (temp1.read_only == 1)
                    {
                        cout << "read only" << " ";
                    }
                    if (temp1.vollabel == 1)
                    {
                        cout << "vollabel" << " ";
                    }
                    if (temp1.directory == 1)
                    {
                        cout << "directory" << " ";
                    }
                    cout << endl;
                    cout << "\tcluster bat dau : " << total << endl;
                    if (total != 0x0)
                    {
                        cout << "Chiem cac sector :";
                        for (int i = 0; i < spc; i++)
                        {
                            cout << (total - 2) * spc - SRDET + i << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    if (temp1.directory == 1 && temp1.system != 1)
                    {
                        cout << "tap tin thu muc con : " << endl;
                        readSDET((total - 2) * spc + SRDET);
                        cout << "------------------------" << endl;
                    }
                    if (temp[temp.length() - 1] == 't' && temp[temp.length() - 2] == 'x' && temp[temp.length() - 3] == 't' && temp1.archive == 1)
                    {
                        readFile((total - 2) * spc + SRDET, toNumber(sector, 0x1C + i, 4));
                    }
                    else if (temp[temp.length() - 1] != 't' && temp[temp.length() - 2] != 'x' && temp[temp.length() - 3] != 't' && temp1.archive == 1)
                    {
                        cout << "\tdung chuong trinh khac de doc " << endl;
                    }
                    temp = "";
                    count = 0;
                }
                else
                {
                    if (toString(sector, 0x08 + i, 3) != "   ")
                    {
                        unsigned int high = toNumber(sector, 0x14 + i, 2);
                        unsigned int low = toNumber(sector, 0x1A + i, 2);
                        unsigned int total = high + low;
                        cout << "\tten tap tin  thu muc :" << toString(sector, 0x00 + i, 8) << endl;
                        cout << "\tphan mo rong :" << toString(sector, 0x08 + i, 3) << endl;
                        cout << "\tkich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << " bytes" << endl;
                        cout << "\ttrang thai : ";
                        int temp = toNumber(sector, 0x0b + i, 1);
                        atribute temp1;
                        string temp2 = decToBinary(temp);
                        temp1 = readatr(temp2);
                        if (temp1.archive == 1)
                        {
                            cout << "archive" << " ";
                        }
                        if (temp1.hidden == 1)
                        {
                            cout << "hidden" << " ";
                        }
                        if (temp1.system == 1)
                        {
                            cout << "system" << " ";
                        }
                        if (temp1.read_only == 1)
                        {
                            cout << "read only" << " ";
                        }
                        if (temp1.vollabel == 1)
                        {
                            cout << "vollabel" << " ";
                        }
                        if (temp1.directory == 1)
                        {
                            cout << "directory" << " ";
                        }
                        cout << endl;
                        cout << "\tcluster bat dau : " << total << endl;
                        if (total != 0x0)
                        {
                            cout << "Chiem cac sector :";
                            for (int i = 0; i < spc; i++)
                            {
                                cout << (total - 2) * spc - SRDET + i << " ";
                            }
                            cout << endl;
                        }
                        cout << endl;
                        if (temp1.directory == 1 && temp1.system != 1)
                        {
                            cout << "\ttap tin thu muc con : " << endl;
                            readSDET((total - 2)* spc + SRDET);
                            cout << "------------------------" << endl;
                        }
                        if (temp1.archive == 1 && toString(sector, 0x08 + i, 3) == "TXT")
                        {
                            readFile((total - 2) * spc + SRDET, toNumber(sector, 0x1C + i, 4));
                        }
                        else
                        {
                            cout << "dung chuong trinh khac de doc " << endl;
                        }
                    }
                    else
                    {
                        unsigned int high = toNumber(sector, 0x14 + i, 2);
                        unsigned int low = toNumber(sector, 0x1A + i, 2);
                        unsigned int total = high + low;
                        cout << "\tten tap thu muc :" << toString(sector, 0x00 + i, 8) << endl;
                        cout << "\tkich thuoc : " << dec << toNumber(sector, 0x1C + i, 4) << endl;
                        cout << "\ttrang thai : ";
                        int temp = toNumber(sector, 0x0b + i, 1);
                        atribute temp1;
                        string temp2 = decToBinary(temp);
                        temp1 = readatr(temp2);
                        if (temp1.archive == 1)
                        {
                            cout << "archive" << " ";
                        }
                        if (temp1.hidden == 1)
                        {
                            cout << "hidden" << " ";
                        }
                        if (temp1.system == 1)
                        {
                            cout << "system" << " ";
                        }
                        if (temp1.read_only == 1)
                        {
                            cout << "read only" << " ";
                        }
                        if (temp1.vollabel == 1)
                        {
                            cout << "vollabel" << " ";
                        }
                        if (temp1.directory == 1)
                        {
                            cout << "directory" << " ";
                        }
                        cout << endl;
                        cout << "\tcluster bat dau : " << total << endl;
                        cout << "Chiem cac sector :";
                        if (total != 0x0)
                        {
                            cout << "Chiem cac sector :";
                            for (int i = 0; i < spc; i++)
                            {
                                cout << (total - 2) * spc - SRDET + i << " ";
                            }
                            cout << endl;
                        }
                        if (temp1.directory == 1 && temp1.system != 1)
                        {
                            cout << "tap tin thu muc con : " << endl;
                            readSDET((total - 2)* spc + SRDET);
                            cout << "------------------------" << endl;
                        }
                    }
                }
            }

        }
        if (checkend == true)
        {
            break;
        }
        else
        {
            k++;

        }
    }
}

void readBootSector(vector<vector<string>> hexarr)
{
    cout << "1. Read Bootsector" << endl;
    cout << endl;
    long int SV, NF, SB, SRDET, SF;
    if (typeofFAT(hexarr) != "No")
        cout << "Kieu FAT: " << typeofFAT(hexarr) << endl;
    else
        cout << "Kieu FAT: FAT32" << endl;
    if (docbyte(hexarr, 6, 1, 2) != 0)
    {
        cout << "Kich thuoc bang FAT : SF = " << docbyte(hexarr, 6, 1, 2) << endl;
        SF = docbyte(hexarr, 6, 1, 2);
    }
    else
    {
        cout << "Kich thuoc bang FAT : SF = " << docbyte(hexarr, 4, 2, 4) << endl;
        SF = docbyte(hexarr, 4, 2, 4);
    }
    cout << "So byte cho 1 sector: " << docbyte(hexarr, 11, 0, 2) << endl;
    spc = docbyte(hexarr, 13, 0, 1);
    cout << "So sector cho 1 cluster: " << docbyte(hexarr, 13, 0, 1) << endl;
    cout << "So sector tai vung boot sector: SB = " << docbyte(hexarr, 14, 0, 2) << endl;
    SB = docbyte(hexarr, 14, 0, 2);
    cout << "So bang FAT: NF = " << docbyte(hexarr, 0, 1, 1) << endl;
    NF = docbyte(hexarr, 0, 1, 1);
    cout << "So sector cua RDET:" << docbyte(hexarr, 1, 1, 2) << endl;
    cout << "1 entry = 32 byte --> " << docbyte(hexarr, 1, 1, 2) * 32 / docbyte(hexarr, 11, 0, 2) << " sector" << endl;
    SRDET = SB + SF * NF;
    if (docbyte(hexarr, 3, 1, 2) != 0)
    {
        cout << "Kich thuoc volume: SV = " << docbyte(hexarr, 3, 1, 2) << " sector" << endl;
        SV = docbyte(hexarr, 3, 1, 2);
    }
    else
    {
        cout << "Kich thuoc volume: SV = " << docbyte(hexarr, 0, 2, 4) << " sector" << endl;
        SV = docbyte(hexarr, 0, 2, 4);
    }
    cout << "Sector dau tien cua bang FAT1: " << SB << endl;
    cout << "Sector bat dau cua RDET: " << SB + NF * SF << endl;
    cout << "Sector bat dau cua DATA: " << SRDET << endl;
}

void readFAT(vector<vector<string>> hexarr)
{
    for (int i = 0; i <= 40; i++)
        cout << "=";
    cout << endl;
    cout << "Bang Boot Sector" << endl;
    cout << endl;
    readBootSector(hexarr);

}

void readVRB(vector<vector<string>> hexarr)
{
    cout << "1. Read VBR" << endl;
    cout << endl;
    cout << "So byte cua 1 sector: " << docbyte(hexarr, 11, 0, 2) << endl;
    cout << "So sector cua 1 cluster: " << docbyte(hexarr, 13, 0, 1) << endl;
    if (hexarr[1][5] == "F8" || hexarr[1][5] == "f8")
        cout << "Loai dia: Hard disk" << endl;
    else if (hexarr[1][5] == "F0" || hexarr[1][5] == "f0")
        cout << "Loai dia: High density floppy" << endl;
    else
        cout << "Loai dia: Can't find" << endl;
    cout << "Kich thuoc hien tai cua dia: " << docbyte(hexarr, 8, 2, 4) << " sectors => " << docbyte(hexarr, 8, 2, 4) * (512 / pow(10, 9)) << " GB" << endl;
    cout << "So mat dia (head hoac side): " << docbyte(hexarr, 10, 2, 2) << endl;
    cout << "Sector bat dau cua o dia logic: " << docbyte(hexarr, 12, 2, 4) << endl;
    cout << "So sector cua o dia logic: " << docbyte(hexarr, 8, 2, 8) << endl;
    cout << "Cluster bat dau cua MFT: " << docbyte(hexarr, 0, 3, 8) << endl;
    cout << "Cluster bat dau cua MFT du phong: " << docbyte(hexarr, 8, 3, 8) << endl;
    cout << "Cluster per MTF: " << docbyte(hexarr, 0, 4, 1) << " clusters" << endl;
    cout << "Cluster per index buffer: " << docbyte(hexarr, 4, 4, 1) << endl;
    cout << "The volume serial number: ";
    for (int i = 8; i < 16; i++)
        cout << hexarr[4][i] << " ";
    cout << endl;
}

void readNTFS(vector<vector<string>> hexarr)
{
    for (int i = 0; i <= 40; i++)
        cout << "=";
    cout << endl;
    cout << "Bang NTFS" << endl;
    cout << endl;
    readVRB(hexarr);
}



