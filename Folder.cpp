#include "Folder.h"

Folder::Folder()
{
}

Folder::~Folder()
{
}

void Folder::setListFile(vector<File*>& listFile)
{
	this->_listFile = listFile;
}

vector<File*> Folder::getListFile()
{
	return vector<File*>(this->_listFile);
}

void Folder::addFolder(File* folder)
{
	this->_listFile.push_back(folder);
}
