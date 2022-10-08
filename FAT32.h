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
	int _hiddenSectors;
	ll _totalSector;
	ll _sectorPerFAT;
	string _version;
	int _rootCluster;
	int _systemInformation;
	int _backupBootSector;
	string _physicalDrive;
	string _extendedSignature;
	string _serialNumber;
	string _volumeNumber;
	string _fileSystem;
	BYTE _bootstrapCode[420];
	string _signature;
	
	vector<File*> _listFile;

public:
};

