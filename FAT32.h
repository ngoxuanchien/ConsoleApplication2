#pragma once
#include "Function.h"
#include "File.h"

class FAT32
{
private:
	string _jmpInstruction;
	string _OEMID;
	int _bytesPerSector;
	int _sectorsPerCluster;
	int _reservedSector;
	int _numberOfFATs;
	string _mediaDescriptor;
	int _sectorPerTrack;
	int _numberOfHeads;
	ll _hiddenSectors;
	ll _totalSector;
	ll _sectorPerFAT;
	string _version;
	int _rootCluster;
	int _systemInformation;
	int _backupBootSector;
	int _physicalDrive;
	string _extendedSignature;
	string _serialNumber;
	string _volumeNumber;
	string _fileSystem;
	string _bootstrapCode;
	string _signature;
	
	vector<File*> _listFile;

	vector<File*> readRDET(LPCWSTR, int);

public:
	FAT32();
	~FAT32();

	void readBootSector(LPCWSTR);
	void readFile(LPCWSTR);
	void output();
};

