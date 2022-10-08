#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
using namespace std;
struct FAT32_BOOT {
    BYTE JMP_instruction[3];
    char OEM_name[8];
    int bytes_per_sector;
    int sectors_per_cluster;
    int reserved_sectors;
    int num_FATs;
    BYTE media; //Loai volume
    int sectors_per_track;
    int num_heads;
    int hidden_sectors; //So sector an truoc volume
    int total_sectors;
    int sectors_per_FAT;
    int root_cluster;
    char FilSysType[8];
    BYTE drive_num;
};
struct NTFS_BOOT {
    BYTE JMP_instruction[3];
    char OEM_name[8];
    int bytes_per_sector;
    int sectors_per_cluster;
    BYTE media; //Loai volume
    int sectors_per_track;
    int num_heads;
    int hidden_sectors; //So sector an truoc volume
    int total_sectors;
    int MTF_clusterr;
    int MFTMirr_cluster;
    int clusters_per_fileRecSeg;
    int clusters_per_indexBlock;
    BYTE volume_serial[8];
    int checksum;
};
struct entry {
    char name[8];
    char name_extension[3];
    BYTE atrribute;
    int hour, minutes, doubleseconds;
    int year, month, day;
    int starting_cluster;
    int size;
    int isMain;
};

struct attributes {
    int read_only;
    int hidden;
    int system;
    int vollabel;
    int directory;
    int archive;
};

struct subEntry {
    int seq;
    char name_5[10];
    char name_6[12];
    char name_2[4];
};
char* getbits(BYTE x)
{
    char* s = new char[8];
    for (int i = 7; i >= 0; i--)
        s[7 - i] = (x & (1 << i)) ? 1 : 0;
    return s;
}
int BinToDec(char s[], int start, int end)
{
    int res = 0;
    for (int i = start; i < end; i++)
    {
        if ((int)s[i] == 1)
            res += pow(2, end - 1 - i);
    }
    return res;
}
int getReverseBytes(BYTE sector[512], int index_start, int num_bytes)
{
    char* bit = new char[num_bytes * 8];

    bit = getbits(sector[index_start + num_bytes - 1]);
    for (int i = 1; i < num_bytes; i++)
    {
        char* t = new char[8];
        t = getbits(sector[index_start + num_bytes - 1 - i]);
        for (int j = 0; j < 8; j++)
            bit[i * 8 + j] = t[j];
    }
    return BinToDec(bit, 0, num_bytes * 8);
}
int ReadSector(LPCWSTR drive, int readPoint, BYTE sector[512])
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

    SetFilePointer(device, readPoint, NULL, FILE_BEGIN);//Set a Point to Read

    if (!ReadFile(device, sector, 512, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
    }
}

FAT32_BOOT ReadHeadBootSectorFAT32(BYTE sector[512])
{
    FAT32_BOOT FAT32;
    for (int i = 0; i < 3; i++)
        FAT32.JMP_instruction[i] = sector[i];
    for (int i = 3; i < 11; i++)
    {
        FAT32.OEM_name[i - 3] = (char)sector[i];
    }
    FAT32.bytes_per_sector = getReverseBytes(sector, 11, 2);
    FAT32.sectors_per_cluster = sector[13];
    FAT32.reserved_sectors = getReverseBytes(sector, 14, 2);
    FAT32.num_FATs = sector[16];
    FAT32.media = sector[21];
    FAT32.sectors_per_track = getReverseBytes(sector, 24, 2);
    FAT32.num_heads = getReverseBytes(sector, 26, 2);
    FAT32.hidden_sectors = getReverseBytes(sector, 28, 4);
    FAT32.total_sectors = getReverseBytes(sector, 32, 4);
    FAT32.sectors_per_FAT = getReverseBytes(sector, 36, 2);
    FAT32.root_cluster = getReverseBytes(sector, 44, 4);
    for (int i = 82; i < 90; i++)
    {
        FAT32.FilSysType[i - 82] = (char)sector[i];
    }
    FAT32.drive_num = sector[64];
    return FAT32;

}
void PrintInformationVolumeFAT32(FAT32_BOOT FAT32)
{
    cout << "JMP instruction: ";
    for (int i = 0; i < 3; i++)
        printf("%.X", FAT32.JMP_instruction[i]);
    cout << endl;
    cout << "OEM name: ";
    for (int i = 0; i < 8; i++)
        cout << FAT32.OEM_name[i];
    cout << endl;
    cout << "Bytes/sector: " << FAT32.bytes_per_sector << endl;
    cout << "Sectors/cluster: " << FAT32.sectors_per_cluster << endl;
    cout << "Reserved sector: " << FAT32.reserved_sectors << endl;
    cout << "Number of FATs: " << FAT32.num_FATs << endl;
    cout << "Type volume: ";
    printf("%.4X", FAT32.media);
    cout << endl;
    cout << "Sectors/track: " << FAT32.sectors_per_track << endl;
    cout << "Number of heads: " << FAT32.num_heads << endl;
    cout << "Hiddent sectors: " << FAT32.hidden_sectors << endl;
    cout << "Total sector: " << FAT32.total_sectors << endl;
    cout << "Sectors/FAT: " << FAT32.sectors_per_FAT << endl;
    cout << "Root cluster: " << FAT32.root_cluster << endl;
    cout << "Type of FAT: ";
    for (int i = 0; i < 8; i++)
        cout << FAT32.FilSysType[i];
    cout << endl;
    cout << "Volume serial number: ";
    printf("%.4X", FAT32.drive_num);
    if (FAT32.drive_num == 0x80)
        cout << " Hard disk" << endl;
    else cout << " Floppy disk" << endl;
}

NTFS_BOOT ReadPartitionBootSectorNTFS(BYTE sector[512])
{
    NTFS_BOOT NTFS;
    for (int i = 0; i < 3; i++)
        NTFS.JMP_instruction[i] = sector[i];
    for (int i = 3; i < 11; i++)
    {
        NTFS.OEM_name[i - 3] = (char)sector[i];
    }
    NTFS.bytes_per_sector = getReverseBytes(sector, 11, 2);
    NTFS.sectors_per_cluster = sector[13];
    NTFS.media = sector[21];
    NTFS.sectors_per_track = getReverseBytes(sector, 24, 2);
    NTFS.num_heads = getReverseBytes(sector, 26, 2);
    NTFS.hidden_sectors = getReverseBytes(sector, 28, 4);
    NTFS.total_sectors = getReverseBytes(sector, 40, 8);
    NTFS.MTF_clusterr = getReverseBytes(sector, 48, 8);
    NTFS.MFTMirr_cluster = getReverseBytes(sector, 56, 8);
    NTFS.clusters_per_fileRecSeg = getReverseBytes(sector, 64, 4);
    NTFS.clusters_per_indexBlock = getReverseBytes(sector, 68, 4);
    for (int i = 72; i < 80; i++)
        NTFS.volume_serial[i - 72] = sector[i];
    NTFS.checksum = getReverseBytes(sector, 80, 4);
    return NTFS;
}
void PrintInformationVolumeNTFS(NTFS_BOOT NTFS)
{
    cout << "JMP instruction: ";
    for (int i = 0; i < 3; i++)
        printf("%.X", NTFS.JMP_instruction[i]);
    cout << endl;
    cout << "Media: ";
    for (int i = 0; i < 8; i++)
        cout << NTFS.OEM_name[i];
    cout << endl;
    cout << "Bytes/sector: " << NTFS.bytes_per_sector << endl;
    cout << "Sectors/cluster: " << NTFS.sectors_per_cluster << endl;
    cout << "Type volume: ";
    printf("%.4X", NTFS.media);
    cout << endl;
    cout << "Sectors/track: " << NTFS.sectors_per_track << endl;
    cout << "Number of heads: " << NTFS.num_heads << endl;
    cout << "Hidden sectors: " << NTFS.hidden_sectors << endl;
    cout << "Total sectors: " << NTFS.total_sectors << endl;
    cout << "MFT cluster number: " << NTFS.MTF_clusterr << endl;
    cout << "MFTMirr cluster number: " << NTFS.MFTMirr_cluster << endl;
    cout << "Clusters per File Record Segment (MFT entry): " << NTFS.clusters_per_fileRecSeg << endl;
    cout << "Sectors/index buffer: " << NTFS.clusters_per_indexBlock << endl;
    cout << "Volume serial number: ";
    for (int i = 0; i < 8; i++)
        printf("%.X", NTFS.volume_serial[i]);
    cout << endl;
    cout << "Checksum: " << NTFS.checksum << endl;
}
char* getAttribute(BYTE attr)
{
    char* s = getbits(attr);
    return s;
}

attributes readAttr(char* s)
{
    attributes tmp;
    tmp.read_only = s[7] & 1;
    tmp.hidden = s[6] & 1;
    tmp.system = s[5] & 1;
    tmp.vollabel = s[4] & 1;
    tmp.directory = s[3] & 1;
    tmp.archive = s[2] & 1;
    return tmp;
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


subEntry readSubEntry(BYTE sector[512], int index_start)
{
    subEntry  sEnt;
    sEnt.seq = getReverseBytes(sector, index_start, 1);
    for (int i = 1; i < 11; i++)
        sEnt.name_5[i - 1] = (char)sector[index_start + i];
    for (int i = 14; i < 26; i++)
        sEnt.name_6[i - 14] = (char)sector[index_start + i];
    for (int i = 28; i < 32; i++)
        sEnt.name_2[i - 28] = (char)sector[index_start + i];
    return sEnt;
}
string getSubEntry(subEntry sEnt)
{
    char s[27];
    //cout << "Day la entry phu\n";
    //cout << "Ten: ";
    for (int i = 0; i < 10; i++)
        if (s[i]<255)
            s[i] = (char)sEnt.name_5[i];
    for (int i = 10; i < 22; i++)
        if (s[i] < 255)
            s[i] = (char)sEnt.name_6[i - 10];
    for (int i = 22; i < 26; i++)
        if (s[i] < 255)
            s[i] =(char) sEnt.name_2[i - 22];
    string res;
    for (int i = 0; i < 26; i++)
        res = res + s[i];
    return res;
}
entry readEntry(BYTE sector[512], int index_start)
{
    entry ent; subEntry sEnt;
    char t[32];
    ent.isMain = getReverseBytes(sector, index_start + 11, 1);
    for (int i = 0; i < 8; i++)
        ent.name[i] = (char)sector[index_start + i];
    for (int i = 8; i < 11; i++)
        ent.name_extension[i - 8] = (char)sector[index_start + i];
    ent.atrribute = sector[index_start + 11];
    ent.starting_cluster = getReverseBytes(sector, index_start + 26, 2);;

    for (int i = 0; i < 16; i++)
        t[i] = getbits(sector[index_start + 22 + i / 8])[i % 8];
    ent.hour = BinToDec(t, 0, 5);
    ent.minutes = BinToDec(t, 5, 11);
    ent.doubleseconds = BinToDec(t, 11, 16);
    for (int i = 0; i < 16; i++)
        t[i] = getbits(sector[index_start + 25 - i / 8])[i % 8];
    ent.year = BinToDec(t, 0, 7);
    ent.month = BinToDec(t, 7, 11);
    ent.day = BinToDec(t, 11, 16);
    ent.size = getReverseBytes(sector, index_start + 28, 3);
    return ent;
}

vector<int> readFat(BYTE fat[512], int start_cluster)
{
    vector<int> temp;
    temp.push_back(start_cluster);
    int i = start_cluster;
    while (fat[i] != 255)
    {
        temp.push_back(i);
        i++;
    }
    return temp;
}


void printEntry(entry ent, string subEntry, int spc, int SRDET)
{
    cout << "Name: ";
    if (subEntry.length() != 0)
        cout << subEntry;
    else 
        for (int i = 0; i < 8; i++)
            cout << ent.name[i];
    cout << endl;
    cout << "File name extension: ";
    for (int i = 0; i < 3; i++)
        cout << ent.name_extension[i];
    cout << endl;
    cout << "Time created: " << ent.hour << ":" << ent.minutes << ":" << ent.doubleseconds << " " << 1980 + ent.year << "-" << ent.month << "-" << ent.day << endl;
    cout << "Starting cluster: " << ent.starting_cluster << endl;
    if (ent.starting_cluster != 0x0)
    {
        cout << "Occupied sectors :";
        for (int i = 0; i < spc; i++)
        {
            cout << -((ent.starting_cluster - 2) * spc - SRDET + i) << " ";
        }
        cout << endl;
    }
    cout << "File size: " << ent.size << endl;
    char* s;
    s = getAttribute(ent.atrribute);
    attributes tmp; tmp = readAttr(s);
    cout << "Attribute: ";
    if (tmp.read_only == 1)
        cout << "Read-only";
    else if (tmp.hidden == 1)
        cout << "Hidden";
    else if (tmp.system == 1)
        cout << "System file";
    else if (tmp.vollabel == 1)
        cout << "Volumn label";
    else if (tmp.directory == 1)
        cout << "Directory";
    else if (tmp.archive == 1)
        cout << "Archive";
    else  printf("%.X", ent.atrribute);

    cout << endl;
}
void printFileTXT(LPCWSTR disk, unsigned int start, int num)
{
    for (int k = 0; k < num; k++)
    {
        BYTE sector[512];
        ReadSector(disk, start, sector);
        for (int i = 0; i < 512; i++)
        {
            cout << (char)sector[i];
        }
    }
}

vector <entry> readRDET(LPCWSTR DRIVE ,BYTE sector[512], int sectors_p_cluster, int bytes_p_sector, int SRDET)
{
    vector <entry> list_text;
    int i = 64;
    bool flag = false;
    string sEntName;
    while (1)
    {
        entry ent;
        ent = readEntry(sector, i);
        char* s = getAttribute(ent.atrribute);
        attributes attr = readAttr(s);
        if (ent.isMain == 15)
        {
            subEntry sEnt;
            sEnt = readSubEntry(sector, i);
            string t = sEntName;
            sEntName=getSubEntry(sEnt)+t;
        }
        else
        {
            printEntry(ent, sEntName,sectors_p_cluster, SRDET);
            if (ent.name_extension[0] == 'T' and ent.name_extension[1] == 'X' and ent.name_extension[2] == 'T')
            {
                int numsector = 1;
                cout << "NOI DUNG TAP TIN" << endl;
                printFileTXT(DRIVE, (SRDET + (ent.starting_cluster - 2) * sectors_p_cluster)*bytes_p_sector ,numsector);
            }
            cout << endl;
            sEntName = "";
            flag = false;
            if (!ent.atrribute)
                break;
        }
        if (ent.name_extension == "TXT")
            list_text.push_back(ent);
        i += 32;
    }
    return list_text;
}

int main(int argc, char** argv)
{
    BYTE sector[512];
    FAT32_BOOT fat32;
    NTFS_BOOT ntfs;
    vector <entry> list_text;
    LPCWSTR DRIVE;
    vector <int> num;
    ReadSector(L"\\\\.\\F:", 0, sector);
    fat32 = ReadHeadBootSectorFAT32(sector);

    int SRDET = fat32.reserved_sectors + fat32.num_FATs * fat32.sectors_per_FAT;

    ReadSector(L"\\\\.\\F:", SRDET * 512, sector);
    list_text = readRDET(L"\\\\.\\F:",sector, fat32.sectors_per_cluster, fat32.bytes_per_sector, SRDET);

}