#include "FAT32.h"
using namespace std;

bool ktDrive(char c)
{
    TCHAR szVolumeName[100];
    TCHAR szFileSystemName[10];
    string text = "D:\\";
    text[0] = c;
    LPWSTR wszDrive = ConvertString(text);

    if (::GetVolumeInformation(wszDrive,
        szVolumeName,
        sizeof(szVolumeName),
        nullptr,
        nullptr,
        nullptr,
        szFileSystemName,
        sizeof(szFileSystemName)) == TRUE)
    {
        return true;
    }
    return false;
}

int checkFileSystemName(LPCWSTR drive)
{
    TCHAR szVolumeName[100];
    TCHAR szFileSystemName[10];
    if (::GetVolumeInformation(L"D:\\",
        szVolumeName,
        sizeof(szVolumeName),
        nullptr,
        nullptr,
        nullptr,
        szFileSystemName,
        sizeof(szFileSystemName)) == TRUE)
    {
        std::wstring ws(szFileSystemName);
        string myVarS = string(ws.begin(), ws.end());
        if (myVarS.compare("FAT32") == 0)
        {
            return 1;
        }
        else if (myVarS.compare("NTFS") == 0)
        {
            return 2;
        }
        return 0;
    }
    return 0;
}

void LoadFAT32(string text)
{
    LPCWSTR drive = ConvertString(text);

    bool OK = true;
    string cur;
    FAT32 result;
    result.readBootSector(drive);
    text = text + ">";
    result.readFile(drive, result.getRootCluster());
    result.output();
    //string temp;
    cin.ignore();
    while (OK)
    {
        cout << text << " ";
        getline(cin, cur);
        
        //cur = "type readMe.txt";
        if (cur.compare("dir") == 0)
        {
            result.printF(result.getListFile());
        }
        else if (cur.substr(0, 2).compare("cd") == 0)
        {
            string temp = cur.substr(3, cur.length() - 2);
      
            if (result.showFolder(drive, temp))
            {
                if (temp.compare("..") == 0)
                {
                    while (text.back() != '\\')
                    {
                        text.pop_back();
                    }
                    text.pop_back();
                    text = text + ">";
                }
                else if (temp.compare(".") == 0)
                {
                    // do nothing
                }
                else
                {
                    text.pop_back();
                    text = text + "\\" + temp + ">";
                }
                
            }
            else
            {
                cout << "Error! Please try again!" << endl;
            }
            //cout << temp << endl;
        }
        else if (cur.substr(0, 4).compare("type") == 0)
        {
         
            //cout << cur.substr(cur.length() - 4, 4) << endl;
            if (cur.substr(cur.length() - 4, 4).compare(".txt") == 0)
            {
                string temp = cur.substr(5, cur.length() - 5);// << endl;
                if (!result.loadFile(drive, temp))
                {
                    cout << "Error! Please try again!" << endl;
                }
                else
                {
                    // do nothing
                }
            }
            else
            {
                cout << "Cannot open this file!" << endl;
            }
        }
        else if (cur.compare("help") == 0)
        {
            cout << "dir" << endl;
            cout << "type" << endl;
            cout << "cd + fileName" << endl;
        }
        else if (cur.compare("exit") == 0)
        {
            break;
        }
        else
        {
            //do nothing
        }
       
    }
}

void start()
{
    bool OK = true;
    char cur;

    vector<char> list;
    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (ktDrive(c))
        {
            list.push_back(c);
        }
    }

    while (OK)
    {
        cout << "Choose drive path to load: (";
        for (int i = 0; i < list.size(); i++)
        {
            if (i == list.size() - 1)
            {
                cout << list[i] << "): ";
            }
            else
            {
                cout << list[i] << ", ";

            }
        }
        cin >> cur;
        if (!ktDrive(cur))
        {
            cout << "Error! Please enter again!" << endl;
        }
        else
        {
            string text1 = "\\\\.\\D:";
            string text2 = "D:\\";
            text1[4] = cur;
            text2[0] = cur;
            int temp = checkFileSystemName(ConvertString(text2));
            if (temp == 0)
            {
                cout << "Can't read file!" << endl;
            }
            else if (temp == 1)
            {
                LoadFAT32(text1);
            }
        }
    }
}

int main()
{
    start();

    return 0;
}
