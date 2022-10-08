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
