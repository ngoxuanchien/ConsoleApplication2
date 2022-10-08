#include "FAT32.h"

FAT32::FAT32()
{
	this->_sizeBootSector = 0;
	this->_sizeCluster = 0;
	this->_sizeFat = 0;
	this->_sizeSector = 0;
	this->_sizeVolume = 0;
	this->_numFat = 0;
}

FAT32::FAT32(LPCWSTR drive)
{
	this->_sizeBootSector = 0;
	this->_sizeCluster = 0;
	this->_sizeFat = 0;
	this->_sizeSector = 0;
	this->_sizeVolume = 0;
	this->_numFat = 0;

	//int t = readBootSectorFAT32(drive, this);

	//readBootSectorFAT32
}

FAT32::~FAT32()
{
	this->_sizeBootSector = 0;
	this->_sizeCluster = 0;
	this->_sizeFat = 0;
	this->_sizeSector = 0;
	this->_sizeVolume = 0;
	this->_numFat = 0;
}

void FAT32::setSizeSector(const ll& sizeSector)
{
	this->_sizeSector = sizeSector;
}

void FAT32::setSizeCluster(const ll& sizeCluster)
{
	this->_sizeCluster = sizeCluster;
}

void FAT32::setSizeFat(const ll& sizeFat)
{
	this->_sizeFat = sizeFat;
}

void FAT32::setSizeVolume(const ll& sizeVolume)
{
	this->_sizeVolume = sizeVolume;
}

void FAT32::setListFile(const vector<File*> listFile)
{
	this->_listFile = listFile;
}

void FAT32::setNumFat(const int& numFat)
{
	this->_numFat = numFat;
}

void FAT32::setSizeBootSector(const ll& sizeBootSector)
{
	this->_sizeBootSector = sizeBootSector;
}

void FAT32::setTypeFat(const string& typeFat)
{
	this->_typeFat = typeFat;
}

ll FAT32::getSizeSector()
{
	return ll(this->_sizeSector);
}

ll FAT32::getSizeCluster()
{
	return ll(this->_sizeCluster);
}

ll FAT32::getSizeFat()
{
	return ll(this->_sizeFat);
}

ll FAT32::getSizeVolume()
{
	return ll(this->_sizeVolume);
}

vector<File*> FAT32::getListFile()
{
	return vector<File*>(this->_listFile);
}

int FAT32::getNumFat()
{
	return this->_numFat;
}

ll FAT32::getSizeBootSector()
{
	return ll(this->_sizeBootSector);
}

string FAT32::getTypeFat()
{
	return string(this->_typeFat);
}

