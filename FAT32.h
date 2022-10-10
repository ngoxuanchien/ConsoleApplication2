#pragma once
#include "Function.h"
#include "Folder.h"
#include <iomanip>


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

	vector<File *> _listFile;

	// function
	vector<File*> readRDET(LPCWSTR, ll);
	vector<ll> readListSector(LPCWSTR, ll);

public:
	FAT32();
	~FAT32();

	// getter
	string getJmpInstruction();
	string getOEMID();
	int getBytesPerSector();
	int getSectorsPerCluster();
	int getReservedSector();
	int getNumberOfFATs();
	string getMediaDescriptor();
	int getSectorPerTrack();
	int getNumberOfHeads();
	ll getHiddenSectors();
	ll getTotalSector();
	ll getSectorPerFAT();
	string getVersion();
	int getRootCluster();
	int getSystemInformation();
	int getBackupBootSector();
	int getPhysicalDrive();
	string getExtendedSignature();
	string getSerialNumber();
	string getVolumeNumber();
	string getFileSystem();
	string getBootstrapCode();
	string getSignature();
	vector<File*> getListFile();

	// setter

	void setJmpInstruction(string);
	void setOEMID(string);
	void setBytesPerSector(int);
	void setSectorsPerCluster(int);
	void setReservedSector(int);
	void setNumberOfFATs(int);
	void setMediaDescriptor(string);
	void setSectorPerTrack(int);
	void setNumberOfHeads(int);
	void setHiddenSectors(ll);
	void setTotalSector(ll);
	void setSectorPerFAT(int);
	void setVersion(string);
	void setRootCluster(int);
	void setSystemInformation(int);
	void setBackupBootSector(int);
	void setPhysicalDrive(int);
	void setExtendedSignature(string);
	void setSerialNumber(string);
	void setVolumeNumber(string);
	void setFileSystem(string);
	void setBootstrapCode(string);
	void setSignature(string);
	void setListFile(vector<File *>);

	void printF(vector<File*>);
	void readBootSector(LPCWSTR);
	vector<File*> readFile(LPCWSTR, ll);
	void output();
	bool showFolder(LPCWSTR, const string&);
	bool loadFile(LPCWSTR, string);
};

