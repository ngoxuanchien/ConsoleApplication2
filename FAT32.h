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

	vector<File *> _listFile;

	// function
	vector<File*> readRDET(LPCWSTR, int);

public:
	FAT32();
	~FAT32();

	// getter
	string get_jmpInstruction();
	string get_OEMID();
	int get_bytesPerSector();
	int get_sectorsPerCluster();
	int get_reservedSector();
	int get_numberOfFATs();
	string get_mediaDescriptor();
	int get_sectorPerTrack();
	int get_numberOfHeads();
	ll get_hiddenSectors();
	ll get_totalSector();
	ll get_sectorPerFAT();
	string get_version();
	int get_rootCluster();
	int get_systemInformation();
	int get_backupBootSector();
	int get_physicalDrive();
	string get_extendedSignature();
	string get_serialNumber();
	string get_volumeNumber();
	string get_fileSystem();
	string get_bootstrapCode();
	string get_signature();
	vector<File *> get_listFile();

	// setter

	void set_jmpInstruction(string);
	void set_OEMID(string);
	void set_bytesPerSector(int);
	void set_sectorsPerCluster(int);
	void set_reservedSector(int);
	void set_numberOfFATs(int);
	void set_mediaDescriptor(string);
	void set_sectorPerTrack(int);
	void set_numberOfHeads(int);
	void set_hiddenSectors(ll);
	void set_totalSector(ll);
	void set_sectorPerFAT(int);
	void set_version(string);
	void set_rootCluster(int);
	void set_systemInformation(int);
	void set_backupBootSector(int);
	void set_physicalDrive(int);
	void set_extendedSignature(string);
	void set_serialNumber(string);
	void set_volumeNumber(string);
	void set_fileSystem(string);
	void set_bootstrapCode(string);
	void set_signature(string);
	void set_listFile(vector<File *>);

	void readBootSector(LPCWSTR);
	void readFile(LPCWSTR);
	void output();
};

