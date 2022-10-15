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

string FAT32::getJmpInstruction()
{
	return this->_jmpInstruction;
}

string FAT32::getOEMID()
{
	return this->_OEMID;
}

int FAT32::getBytesPerSector()
{
	return this->_bytesPerSector;
}

int FAT32::getSectorsPerCluster()
{
	return this->_sectorsPerCluster;
}

int FAT32::getReservedSector()
{
	return this->_reservedSector;
}

int FAT32::getNumberOfFATs()
{
	return this->_numberOfFATs;
}

string FAT32::getMediaDescriptor()
{
	return this->_mediaDescriptor;
}

int FAT32::getSectorPerTrack()
{
	return this->_sectorPerTrack;
}

int FAT32::getNumberOfHeads()
{
	return this->_numberOfHeads;
}

ll FAT32::getHiddenSectors()
{
	return this->_hiddenSectors;
}

ll FAT32::getTotalSector()
{
	return this->_totalSector;
}

ll FAT32::getSectorPerFAT()
{
	return this->_sectorPerFAT;
}

string FAT32::getVersion()
{
	return this->_version;
}

int FAT32::getRootCluster()
{
	return this->_rootCluster;
}

int FAT32::getSystemInformation()
{
	return this->_systemInformation;
}

int FAT32::getBackupBootSector()
{
	return this->_backupBootSector;
}

int FAT32::getPhysicalDrive()
{
	return this->_physicalDrive;
}

string FAT32::getExtendedSignature()
{
	return this->_extendedSignature;
}

string FAT32::getSerialNumber()
{
	return this->_serialNumber;
}

string FAT32::getVolumeNumber()
{
	return this->_volumeNumber;
}

string FAT32::getFileSystem()
{
	return this->_fileSystem;
}

string FAT32::getBootstrapCode()
{
	return this->_bootstrapCode;
}

string FAT32::getSignature()
{
	return this->_signature;
}

vector<File*> FAT32::getListFile()
{
	return this->_listFile;
}

void FAT32::setJmpInstruction(string jmpInstruction)
{
	this->_jmpInstruction = jmpInstruction;
}

void FAT32::setOEMID(string OEMID)
{
	this->_OEMID = OEMID;
}

void FAT32::setBytesPerSector(int bytesPerSector)
{
	this->_bytesPerSector = bytesPerSector;
}

void FAT32::setSectorsPerCluster(int sectorsPerCluster)
{
	this->_sectorsPerCluster = sectorsPerCluster;
}

void FAT32::setReservedSector(int reservedSector)
{
	this->_reservedSector = reservedSector;
}

void FAT32::setNumberOfFATs(int numberOfFATs)
{
	this->_numberOfFATs = numberOfFATs;
}

void FAT32::setMediaDescriptor(string mediaDescriptor)
{
	this->_mediaDescriptor = mediaDescriptor;
}

void FAT32::setSectorPerTrack(int sectorPerTrack)
{
	this->_sectorPerTrack = sectorPerTrack;
}

void FAT32::setNumberOfHeads(int numberOfHeads)
{
	this->_numberOfHeads = numberOfHeads;
}

void FAT32::setHiddenSectors(ll hiddenSectors)
{
	this->_hiddenSectors = hiddenSectors;
}

void FAT32::setTotalSector(ll totalSector)
{
	this->_totalSector = totalSector;
}

void FAT32::setSectorPerFAT(int sectorPerFAT)
{
	this->_sectorPerFAT = sectorPerFAT;
}

void FAT32::setVersion(string version)
{
	this->_version = version;
}

void FAT32::setRootCluster(int rootCluster)
{
	this->_rootCluster = rootCluster;
}

void FAT32::setSystemInformation(int systemInformation)
{
	this->_systemInformation = systemInformation;
}

void FAT32::setBackupBootSector(int backupBootSector)
{
	this->_backupBootSector = backupBootSector;
}

void FAT32::setPhysicalDrive(int physicalDrive)
{
	this->_physicalDrive = physicalDrive;
}

void FAT32::setExtendedSignature(string extendedSignature)
{
	this->_extendedSignature = extendedSignature;
}

void FAT32::setSerialNumber(string serialNumber)
{
	this->_serialNumber = serialNumber;
}

void FAT32::setVolumeNumber(string volumeNumber)
{
	this->_volumeNumber = volumeNumber;
}

void FAT32::setFileSystem(string fileSystem)
{
	this->_fileSystem = fileSystem;
}

void FAT32::setBootstrapCode(string bootstrapCode)
{
	this->_bootstrapCode = bootstrapCode;
}

void FAT32::setSignature(string signature)
{
	this->_signature = signature;
}

void FAT32::setListFile(vector<File*> listFile)
{
	this->_listFile = listFile;
}

string getHex(BYTE *sector, int start, int end, bool reverse)
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

const int _fat32[29] = {3, 8, 2, 1, 2, 1, 2, 2, 1, 2, 2, 2, 4, 4, 4, 2, 2, 4, 2, 2, 12, 1, 1, 1, 4, 11, 8, 420, 2};
void FAT32::readBootSector(LPCWSTR drive)
{
	BYTE *sector = new BYTE[512];
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

		case 6:
		case 7:
		case 9:
		case 15:
		case 20:
		case 22:
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

string readNextCluster(BYTE *sector, int index)
{
	string result = "";
	int start = index * 4;

	result = getHex(sector, start, start + 4, 1);

	return result;
}

vector<ll> readCluster(BYTE *sector, int clusterStart)
{
	static string _EOF = "0FFFFFFF";

	vector<ll> result;
	if (clusterStart >= 2)
	{

		string cur = toHex(clusterStart);
		while (cur.compare(_EOF) != 0)
		{
			clusterStart = hexToDec(cur);
			result.push_back(clusterStart);
			cur = readNextCluster(sector, clusterStart);
		}
	}

	return result;
}

string getNameSupEntry(BYTE *sector, int start)
{
	string result = "";
	stringstream ss;

	for (int i = start + 1; i < start + 11; i += 2)
	{
		ss << hexToASCII(getHex(sector, i, i + 2, 1));
	}

	for (int i = start + 14; i < start + 26; i += 2)
	{
		ss << hexToASCII(getHex(sector, i, i + 2, 1));
	}

	for (int i = start + 28; i < start + 32; i += 2)
	{
		ss << hexToASCII(getHex(sector, i, i + 2, 1));
	}

	result = ss.str();

	return result;
}

string getNameMainEntry(BYTE *sector, int start)
{
	string result = "";

	result = result + hexToASCII(getHex(sector, start, start + 11, 0));

	return result;
}

dateTime readCreateDate(BYTE* sector, int start)
{
	dateTime result;
	string cur;
	cur = hexToBin(getHex(sector, start + 13, start + 16, 1));

	string temp = "";
	for (int i = 0; i < cur.length(); i++)
	{
		temp = temp + cur[i];

		if (i == 4)
		{
			result.hour = binToDec(temp);
			temp = "";
		}
		else if (i == 10)
		{
			result.minute = binToDec(temp);
			temp = "";
		}
		else if (i == 16)
		{
			result.second = binToDec(temp);
			temp = "";
		}
		else if (i == 23)
		{
			result.milisecond = binToDec(temp);
			temp = "";
		}
	}

	cur = hexToBin(getHex(sector, start + 16, start + 18, 1));

	temp = "";
	for (int i = 0; i < cur.length(); i++)
	{
		temp = temp + cur[i];

		switch (i)
		{
		case 6:
			result.year = binToDec(temp) + 1980;
			temp = "";
			break;

		case 10:
			result.month = binToDec(temp);
			temp = "";
			break;

		case 15:
			result.date = binToDec(temp);
			temp = "";
			break;
		}
	}

	return result;
}

dateTime readLastAccessDay(BYTE* sector, int start)
{
	dateTime result;

	string cur = hexToBin(getHex(sector, start + 18, start + 20, 1));
	string temp = "";
	for (int i = 0; i < cur.length(); i++)
	{
		temp = temp + cur[i];

		switch (i)
		{
		case 6:
			result.year = binToDec(temp) + 1980;
			temp = "";
			break;

		case 10:
			result.month = binToDec(temp);
			temp = "";
			break;

		case 15:
			result.date = binToDec(temp);
			temp = "";
			break;
		}
	}

	return result;
}

dateTime readLastEdit(BYTE* sector, int start)
{
	dateTime result;
	string cur = hexToBin(getHex(sector, start + 22, start + 24, 1));
	string temp = "";

	for (int i = 0; i < cur.length(); i++)
	{
		temp = temp + cur[i];
		switch (i)
		{
		case 4:
			result.hour = binToDec(temp);
			temp = "";
			break;

		case 10:
			result.minute = binToDec(temp);
			temp = "";
			break;

		case 15:
			result.second = binToDec(temp) * 2;
			temp = "";
			break;
		}
	}

	cur = hexToBin(getHex(sector, start + 24, start + 26, 1));
	temp = "";
	for (int i = 0; i < cur.length(); i++)
	{
		temp = temp + cur[i];

		switch (i)
		{
		case 6:
			result.year = binToDec(temp) + 1980;
			temp = "";
			break;

		case 10:
			result.month = binToDec(temp);
			temp = "";
			break;

		case 15:
			result.date = binToDec(temp);
			temp = "";
			break;
		}
	}
	
	return result;
}

ll readFileSize(BYTE* sector, int start)
{
	ll result = 0;

	result = hexToDec(getHex(sector, start + 28, start + 32, 1));

	return result;
}

ll readStartCluster(BYTE* sector, ll start)
{
	ll result = 0;
	//string cur = "";
	stringstream ss;

	ss << getHex(sector, start + 20, start + 22, 1);
	ss << getHex(sector, start + 26, start + 28, 1);

	result = hexToDec(ss.str());

	return result;
}

vector<ll> FAT32::readListSector(LPCWSTR drive, ll startCluster)
{
	vector<ll> result;

	LARGE_INTEGER readPointer;
	readPointer.QuadPart = this->_reservedSector * this->_bytesPerSector;
	ll size = this->_sectorPerFAT * this->_bytesPerSector;
	BYTE* sector = new BYTE[size];
	readByte(drive, readPointer, sector, size);

	vector<ll> listCluster = readCluster(sector, startCluster);

	for (int i = 0; i < listCluster.size(); i++)
	{
		for (int j = 0; j < this->_sectorsPerCluster; j++)
		{
			result.push_back((listCluster[i] - 2) * this->_sectorsPerCluster + this->_reservedSector + this->_numberOfFATs * this->_sectorPerFAT + j);
		}
	}

	return result;
}

void FAT32::printF(vector<File*> file)
{
	string temp = "   ";
	for (int i = 0; i < file.size(); i++)
	{
		cout << setw(20) << file[i]->getDateCreate();
		
		if (file[i]->isForder())
		{
			cout << setw(10) << "<DIR>" << setw(15) << temp;
		}
		else
		{
			cout << setw(10) << temp << setw(15) << file[i]->getFileSize();
		}
		cout << setw(5) << temp;
		cout << file[i]->getName() << endl;
	}
}

vector<File*> FAT32::readRDET(LPCWSTR drive, ll clusterStart)
{
	vector<File*> result;
	LARGE_INTEGER readPoint;
	readPoint.QuadPart = ((clusterStart - 2) * this->_sectorsPerCluster + this->_reservedSector + this->_numberOfFATs * this->_sectorPerFAT) * this->_bytesPerSector;
	ll size = this->_sectorsPerCluster * this->_bytesPerSector;
	BYTE* sector = new BYTE[size];

	if (readByte(drive, readPoint, sector, size))
	{
		string cur = "";
		File* folder;
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
				folder = new File;
				if (cur.compare("") == 0)
				{
					cur = getNameMainEntry(sector, i);
				}
				//cout << cur << endl;
				folder->setDateCreate(readCreateDate(sector, i));
				folder->setLastAccess(readLastAccessDay(sector, i));
				folder->setLatstEdit(readLastEdit(sector, i));
				folder->setFileSize(readFileSize(sector, i));
				folder->setClusterStart(readStartCluster(sector, i));
				folder->setName(cur);
				folder->setListSector(readListSector(drive, folder->getClusterStart()));
				folder->setAttributes(hexToDec(getHex(sector, i + 11, i + 12, 0)));
				result.push_back(folder);
				cur = "";
			}
		}
	}

	delete[] sector;
	return result;
}



vector<File*> FAT32::readFile(LPCWSTR drive, ll clusterStart)
{
	if (clusterStart == 0)
	{
		clusterStart = this->_rootCluster;
	}
	LARGE_INTEGER readPointer;
	readPointer.QuadPart = this->_reservedSector * this->_bytesPerSector;
	ll size = this->_sectorPerFAT * this->_bytesPerSector;
	BYTE* sector = new BYTE[size];
	readByte(drive, readPointer, sector, size);

	vector<ll> rdet = readCluster(sector, clusterStart);

	vector<File*> result;
	for (int i = 0; i < rdet.size(); i++)
	{
		vector<File*> temp = readRDET(drive, rdet[i]);
		result.insert(result.end(), temp.begin(), temp.end());
	}
	
	this->_listFile = result;
	delete[] sector;
	return result;
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
	//cout << "Bootstrap code: " << this->_bootstrapCode << endl;
	cout << "Signature: " << this->_signature << endl;
}

bool FAT32::showFolder(LPCWSTR drive, const string& folder)
{
	bool result = false;

	if (folder.compare("") == 0)
	{
		result = false;
	}
	else
	{
		vector<File*> listFile = this->_listFile;
		for (int i = 0; i < listFile.size(); i++)
		{
			if (folder.compare(listFile[i]->getName()) == 0)
			{
				result = true;
				vector<File*> cur = readFile(drive, listFile[i]->getClusterStart());
				break;
			}
			else
			{
				// Do nothing
			}
		}

	}

	return result;
}

bool FAT32::loadFile(LPCWSTR drive, string fileName)
{
	//cout << fileName << endl;
	bool result = false;
	vector<File*> listFile = this->_listFile;
	for (int i = 0; i < listFile.size(); i++)
	{
		//cout << listFile[i]->getName() << listFile[i]->getName().length() << endl;
		if (fileName.compare(listFile[i]->getName()) == 0)
		{
			vector<ll> listSec = listFile[i]->getListSector();
			long long size = this->_bytesPerSector;
			long long fileSize = listFile[i]->getFileSize();
			for (int j = 0; j < listSec.size(); j++)
			{
				LARGE_INTEGER readPoint;
				readPoint.QuadPart = listSec[j] * this->_bytesPerSector;
				BYTE* sector = new BYTE[size];
				string cur = "";
				readByte(drive, readPoint, sector, size);
				for (int k = 0; k < size; k++)
				{
					cur = cur + toHex(sector[k]);
				}
				cout << hexToASCII(cur);
				delete[] sector;
				fileSize -= size;
				if (fileSize <= 0)
				{
					break;
				}
			}
			result = true;
		}
		else
		{
			// Do nothing
		}
	}
	return result;
}

bool FAT32::fileInf(string file)
{
	bool result = false;

	if (file.compare("") == 0)
	{
		//print(this->_listFile);
		result = false;
	}
	else
	{
		vector<File*> listFile = this->_listFile;
		for (int i = 0; i < listFile.size(); i++)
		{
			if (file.compare(listFile[i]->getName()) == 0)
			{
				result = true;
				this->_listFile[i]->printFile();
				break;
			}
			else
			{
				// Do nothing
			}
		}

	}

	return result;
}

