#pragma once
#include "Function.h"
#include "File.h"

class FAT32
{
private:
	ll _sizeSector;
	ll _sizeCluster;
	ll _sizeFat;
	ll _sizeVolume;
	int _numFat;
	ll _sizeBootSector;
	string _typeFat;
	vector<File*> _listFile;

public:
	FAT32();
	FAT32(LPCWSTR);
	~FAT32();

	// getter
	void setSizeSector(const ll&);
	void setSizeCluster(const ll&);
	void setSizeFat(const ll&);
	void setSizeVolume(const ll&);
	void setListFile(const vector<File*>);
	void setNumFat(const int&);
	void setSizeBootSector(const ll&);
	void setTypeFat(const string&);

	// sector
	ll getSizeSector();
	ll getSizeCluster();
	ll getSizeFat();
	ll getSizeVolume();
	vector<File*> getListFile();
	ll getRDETLocation();
	ll getFATLocation();
	int getNumFat();
	ll getSizeBootSector();
	string getTypeFat();

};

