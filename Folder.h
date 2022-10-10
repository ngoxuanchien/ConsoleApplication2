#pragma once
#include "File.h"

class Folder:protected File
{
private:
	vector<File*> _listFile;

public:
	Folder();
	~Folder();

	void setListFile(vector<File*>&);
	
	vector<File*> getListFile();
	void addFolder(File*);
};

