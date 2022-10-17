#include"Header.h"

int main(int argc, char** argv)
{
    boolean quit = FALSE;
    while (!quit)
    {
        cout << endl;
        cout << endl << "WARNING!!!!" << endl;
        cout << "Our permanant disk which will be read below is D: from the USB" << endl;
        cout << "Make sure your USB is D: and formated with NTFS or FAT32 file system" << endl;
        cout << "If not, please replace D: in ReadSector (line 31 and 64 for FAT32 or 88 for NTFS) to your NTFS or FAT32 USB's file system or reformating your USB, then enter your choice and run the program" << endl;
        cout << "We are not responsible for your confusion in selecting and checking the USB's file system" << endl;
        cout << "Especially you must have files in your USB for FAT32 because if not it will affect the result of the output of RDET/SRDET reading file" << endl;
        cout << "This will lead to unexpected output" << endl;
        cout << "Sorry for this inconvenience !!!" << endl;
        cout << endl;
        cout << "Part 1: FAT32" << endl << "Part 2: NTFS" << endl << "Part 3: Exit" << endl;
        cout << "-> Enter your choice: ";
        int n;
        cin >> n;
        switch (n) 
        {
            case 1:
            {
                //READ BOOTSECTOR/FAT/RDET FROM FAT32

                BYTE sector[512];
                BYTE temp[100][100];
                vector<vector<string>> hexarr;
                ReadSector(L"\\\\.\\D:", 0, sector);
                for (int i = 0; i < 32; i++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        temp[i][j] = sector[i * 16 + j];
                    }
                }
                cout << "1. READ BOOT SECTOR" << endl;
                tohex(temp, hexarr);
                cout << endl;

                readFAT(hexarr);

                cout << endl << "2. READ RDET/SRDET" << endl;

                long int SB = docbyte(hexarr, 14, 0, 2);
                long int SF;
                long int NF = docbyte(hexarr, 0, 1, 1);
                if (docbyte(hexarr, 6, 1, 2) != 0)
                {
                    SF = docbyte(hexarr, 6, 1, 2);
                }
                else
                {
                    SF = docbyte(hexarr, 4, 2, 4);
                }
                long int SRDET = SB + SF * NF;

                BYTE sector1[512];
                BYTE temp1[100][100];
                vector<vector<string>> hexarr1;

                ReadSector(L"\\\\.\\D:", SB, sector1);
                for (int i = 0; i < 32; i++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        temp1[i][j] = sector1[i * 16 + j];
                    }
                }
                for (int i = 0; i <= 40; i++)
                    cout << "=";
                cout << endl;
                cout << "Bang FAT1:" << endl;
                tohex(temp1, hexarr1);
                cout << endl;
                readRDET(SRDET);
                break;
            }
            case 2:
            {
                cout << endl;

                BYTE sector[512];
                BYTE temp[100][100];
                vector<vector<string>> hexarr;
                ReadSector(L"\\\\.\\D:", 0, sector);
                for (int i = 0; i < 32; i++)
                {
                    for (int j = 0; j < 16; j++)
                    {
                        temp[i][j] = sector[i * 16 + j];
                    }
                }

                cout << "1. READ PARTITION BOOT SECTOR OF NTFS" << endl;
                tohex(temp, hexarr);
                cout << endl;

                readNTFS(hexarr);

                break;
            }
            case 3:
            {
                quit = TRUE;
                break;
            }
            default:
                cout << "Invalid input! Please enter week number between 1-2" << endl;
        }
    }
   
    return 0;
}