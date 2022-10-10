#include "File.h"

File::File()
{
	this->_name = "";
	this->_fileSize = 0;
	this->_sector = 0;
	this->_attributes = 0;
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
	this->_attributes = 0;
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

void File::setAttributes(const int &attributes)
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
	string result = (string)this->_name;
	int index = result.length();
	//cout << (int)result[index - 1] << endl;
	//cout << sizeof(result[0]) << endl;
	int count = 0;
	//cout << result.length() << " ";
	while ((result[index - 1] == ' ' || result[index - 1] == char(-1) || result[index-1] == char(0)) && index >= 0)
	{
		//cout << "D" << endl;
		result.pop_back();
		index--;
		count++;
	}
	/*cout << count << endl;
	cout << result << " " << result.length() << endl;*/
	//cout << (int)result[index - 1] << endl;
	result[index] = '\0';
	this->_name = result;
	return string(result);
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
	string result = "";
	int temp = this->_attributes;

	if ((temp & 1) == 1)
	{
		result = result + " ReadOnly ";
	}

	if (((temp >> 1) & 1) == 1)
	{
		result = result + " Hidden ";
	}

	if (((temp >> 2) & 1) == 1)
	{
		result = result + " System ";
	}

	if (((temp >> 3) & 1) == 1)
	{
		result = result + " Volabel ";
	}

	if (((temp >> 4) & 1) == 1)
	{
		result = result + " Directory ";
	}

	if (((temp >> 5) & 1) == 1)
	{
		result = result + " Archive ";
	}

	return string(result);
}

string File::getDateCreate()
{
	string result = "";
	result = toString(this->_dateCreate.year) + "-" + toString(this->_dateCreate.month) + "-" + toString(this->_dateCreate.date) + "  " + toString(this->_dateCreate.hour) + ":" + toString(this->_dateCreate.minute);
	return result;
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

bool File::isForder()
{
	bool result = false;
	int temp = this->_attributes;

	if (((temp >> 4) & 1) == 1)
	{
		result = true;
	}

	return result;
}
