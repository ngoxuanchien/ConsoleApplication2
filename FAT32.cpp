#include "FAT32.h"

FAT32::FAT32()
{
	this->_jmpInstruction = "";
	this->_OEMID = "";
	this->_bytesPerSector = 0;
	this->_sectorsPerCluster = 0;
	this->_reservedSector = 0;
	this->_numberOfFATs = 0;
	this->_mediaDescriptor = "";
	this->_numberOfHeads = 0;
	this->_hiddenSectors = 0;
	this->_sectorPerTrack = 0;
	this->_totalSector = 0;
	this->_sectorPerFAT = 0;
	this->_version = "";
	this->_rootCluster = 0;
	this->_systemInformation = 0;
	this->_backupBootSector = 0;
	this->_physicalDrive = 0;
	this->_extendedSignature = "";
	this->_serialNumber = "";
	this->_volumeNumber = "";
	this->_fileSystem = "";
	this->_bootstrapCode = "";
	this->_signature = "";
}

FAT32::~FAT32()
{
	this->_jmpInstruction = "";
	this->_OEMID = "";
	this->_bytesPerSector = 0;
	this->_sectorsPerCluster = 0;
	this->_reservedSector = 0;
	this->_numberOfFATs = 0;
	this->_mediaDescriptor = "";
	this->_numberOfHeads = 0;
	this->_hiddenSectors = 0;
	this->_sectorPerTrack = 0;
	this->_totalSector = 0;
	this->_sectorPerFAT = 0;
	this->_version = "";
	this->_rootCluster = 0;
	this->_systemInformation = 0;
	this->_backupBootSector = 0;
	this->_physicalDrive = 0;
	this->_extendedSignature = "";
	this->_serialNumber = "";
	this->_volumeNumber = "";
	this->_fileSystem = "";
	this->_bootstrapCode = "";
	this->_signature = "";
}

string getHex(BYTE* sector, int start, int end, bool reverse)
{
	string result = "";

	for (int i = start; i < end; i++)
	{
		if (!reverse)
		{
			result = result + toHex(sector[i]);
		}
		else
		{
			result = toHex(sector[i]) + result;
		}
	}

	return result;
}

const int _fat32[29] = { 3, 8, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 4, 4, 4, 2, 2, 4, 2, 2, 12, 1, 1, 1, 4, 11, 8, 420, 2 };
void FAT32::readBootSector(LPCWSTR drive)
{
	BYTE* sector = new BYTE[512];
	LARGE_INTEGER readPoint;
	readPoint.QuadPart = 0;
	readByte(drive, readPoint, sector, 512);

	int count = 0;
	string cur;
	for (int i = 0; i < 29; i++)
	{
		switch (i)
		{
		case 0:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_jmpInstruction = cur;
			break;

		case 1:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_OEMID = hexToASCII(cur);
			break;
			
		case 2:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_bytesPerSector = hexToDec(cur);
			break;
			
		case 3:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_sectorsPerCluster = hexToDec(cur);
			break;
			
		case 4:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_reservedSector = hexToDec(cur);
			break;

		case 5:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_numberOfFATs = hexToDec(cur);
			break;

		case 6: case 7: case 9: case 15: case 20: case 22:
			break;
		
		case 8:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_mediaDescriptor = cur;
			break;
		
		case 10:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_sectorPerTrack = hexToDec(cur);
			break;
		
		case 11:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_numberOfHeads = hexToDec(cur);
			break;
		case 12:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_hiddenSectors = hexToDec(cur);
			break;

		case 13:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_totalSector = hexToDec(cur);
			break;

		case 14:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_sectorPerFAT = hexToDec(cur);
			break;

		case 16:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_version = cur;
			break;

		case 17:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_rootCluster = hexToDec(cur);
			break;

		case 18:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_systemInformation = hexToDec(cur);
			break;
		
		case 19:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_backupBootSector = hexToDec(cur);
			break;

		case 21:
			cur = getHex(sector, count, count + _fat32[i], 1);
			this->_physicalDrive = hexToDec(cur);
			break;

		case 23:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_extendedSignature = cur;
			break;

		case 24:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_serialNumber = cur;
			break;

		case 25:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_volumeNumber = hexToASCII(cur);
			break;

		case 26:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_fileSystem = hexToASCII(cur);
			break;

		case 27:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_bootstrapCode = cur;
			break;

		case 28:
			cur = getHex(sector, count, count + _fat32[i], 0);
			this->_signature = cur;
			break;
		}
		count += _fat32[i];
	}
}

string getNextCluster(BYTE* sector, int index)
{
	string result = "";
	int start = index * 4;

	result = getHex(sector, start, start + 4, 1);

	return result;
}

vector<int> getCluster(BYTE* sector, int clusterStart)
{
	static string _EOF = "0FFFFFFF";

	vector<int> result;

	string cur = toHex(clusterStart);
	while (cur.compare(_EOF) != 0)
	{
		clusterStart = hexToDec(cur);
		result.push_back(clusterStart);
		cur = getNextCluster(sector, clusterStart);
	}

	return result;
}

string getNameSupEntry(BYTE* sector, int start)
{
	string result = "";

	for (int i = start + 1; i < start + 11; i += 2)
	{
		result = result + hexToASCII(getHex(sector, i, i + 2, 1));
	}

	for (int i = start + 14; i < start + 26; i += 2)
	{
		result = result + hexToASCII(getHex(sector, i, i + 2, 1));
	}

	for (int i = start + 28; i < start + 32; i += 2)
	{
		result = result + hexToASCII(getHex(sector, i, i + 2, 1));
	}

	return result;
}

string getNameMainEntry(BYTE* sector, int start)
{
	string result = "";

	result = result + hexToASCII(getHex(sector, start, start + 11, 0));

	return result;
}

vector<File*> FAT32::readRDET(LPCWSTR drive, int clusterStart)
{
	vector<File*> result;
	LARGE_INTEGER readPoint;
	readPoint.QuadPart = ((clusterStart - 2) + this->_reservedSector + this->_numberOfFATs * this->_sectorPerFAT) * this->_bytesPerSector;
	ll size = this->_sectorsPerCluster * this->_bytesPerSector;
	BYTE* sector = new BYTE[size];

	if (readByte(drive, readPoint, sector, size))
	{
		string cur = "";
		for (int i = 0; i < size; i += 32)
		{
			if (getHex(sector, i, i + 1, 0).compare("00") == 0 || getHex(sector, i, i + 1, 0).compare("E5") == 0)
			{
				continue;
			}

			if (getHex(sector, i + 11, i + 12, 0).compare("0F") == 0)
			{
				cur = getNameSupEntry(sector, i) + cur;
			}
			else
			{
				if (cur.compare("") == 0)
				{
					cur = getNameMainEntry(sector, i);
				}
				cout << cur << endl;
				cur = "";
			}
			
		}
	}

	return result;
}

void FAT32::readFile(LPCWSTR drive)
{
	LARGE_INTEGER readPointer;
	readPointer.QuadPart = 1797120;
	BYTE* sector = new BYTE[7490048];
	readByte(drive, readPointer, sector, 7490048);

	vector<int> rdet = getCluster(sector, this->_rootCluster);

	for (int i = 0; i < rdet.size(); i++)
	{
		readRDET(drive, rdet[i]);
	}
	cout << endl;

	delete[] sector;
}

void FAT32::output()
{
	cout << "Jump Code: " << this->_jmpInstruction << endl;
	cout << "OEM_ID: " << this->_OEMID << endl;
	cout << "Byte per sector: " << this->_bytesPerSector << endl;
	cout << "Sectors per cluster: " << this->_sectorsPerCluster << endl;
	cout << "Sectors per BootSector: " << this->_reservedSector << endl;
	cout << "Number of FATs: " << this->_numberOfFATs << endl;
	cout << "Media descriptor: " << this->_mediaDescriptor << endl;
	cout << "Sectors per track: " << this->_sectorPerTrack << endl;
	cout << "Number of heads: " << this->_numberOfHeads << endl;
	cout << "Hidden sectors: " << this->_hiddenSectors << endl;
	cout << "Total sectors: " << this->_totalSector << endl;
	cout << "Sectors per fat: " << this->_sectorPerFAT << endl;
	cout << "Version: " << this->_version << endl;
	cout << "Root cluster: " << this->_rootCluster << endl;
	cout << "System Information sector: " << this->_systemInformation << endl;
	cout << "Backup Boot sector: " << this->_backupBootSector << endl;
	cout << "Physical drive: " << this->_physicalDrive << endl;
	cout << "Extended Signature: " << this->_extendedSignature << endl;
	cout << "Serial Number: " << this->_serialNumber << endl;
	cout << "Volume label: " << this->_volumeNumber << endl;
	cout << "File system: " << this->_fileSystem << endl;
	cout << "Bootstrap code: " << this->_bootstrapCode << endl;
	cout << "Signature: " << this->_signature << endl;
}
