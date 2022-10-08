#include "File.h"

File::File()
{
	this->_name = "";
	this->_fileSize = 0;
	this->_sector = 0;
	this->_attributes = "";
	this->_dateCreate;
	this->_lastAccess;
	this->_lastEdit;
	this->_clusterStart = 0;
}

File::~File()
{
	this->_name = "";
	this->_fileSize = 0;
	this->_sector = 0;
	this->_attributes = "";
	this->_dateCreate;
	this->_lastAccess;
	this->_lastEdit;
	this->_clusterStart = 0;
}

void File::setName(const string &name)
{
	this->_name = name;
}

void File::setFileSize(const ll &fileSize)
{
	this->_fileSize = fileSize;
}

void File::setSector(const ll &sector)
{
	this->_sector = sector;
}

void File::setAttributes(const string &attributes)
{
	this->_attributes = attributes;
}

void File::setDateCreate(const dateTime &dateCreate)
{
	this->_dateCreate = dateCreate;
}

void File::setLastAccess(const dateTime &lastAccess)
{
	this->_lastAccess = lastAccess;
}

void File::setLatstEdit(const dateTime &lastEdit)
{
	this->_lastEdit = lastEdit;
}

void File::setClusterStart(const ll &clusterStart)
{
	this->_clusterStart = clusterStart;
}

void File::setListSector(const vector<ll> &listSector)
{
	this->_listSector = listSector;
}

string File::getName()
{
	return string(this->_name);
}

ll File::getFileSize()
{
	return ll(this->_fileSize);
}

ll File::getSector()
{
	return ll(this->_sector);
}

string File::getAttributes()
{
	return string(this->_attributes);
}

dateTime File::getDateCreate()
{
	return dateTime(this->_dateCreate);
}

dateTime File::getLastAccess()
{
	return dateTime(this->_lastAccess);
}

dateTime File::getLatstEdit()
{
	return dateTime(this->_lastEdit);
}

ll File::getClusterStart()
{
	return ll(this->_clusterStart);
}

vector<ll> File::getListSector()
{
	return vector<ll>(this->_listSector);
}
