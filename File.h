#pragma once
#include <string>
#include <vector>

using namespace std;

#define ll long long

struct dateTime
{
	int date, month, year, hour, minute, second, milisecond;

	dateTime()
	{
		date = 0;
		month = 0;
		year = 1980;
		hour = 0;
		minute = 0;
		second = 0;
		milisecond = 0;
	}
};

class File
{
protected:
	string _name;
	ll _fileSize;
	ll _sector;
	string _attributes;
	dateTime _dateCreate;
	dateTime _lastAccess;
	dateTime _lastEdit;
	ll _clusterStart;
	vector<ll> _listSector;

public:
	File();
	~File();

	void setName(const string &);
	void setFileSize(const ll &);
	void setSector(const ll &);
	void setAttributes(const string &);
	void setDateCreate(const dateTime &);
	void setLastAccess(const dateTime &);
	void setLatstEdit(const dateTime &);
	void setClusterStart(const ll &);
	void setListSector(const vector<ll> &);

	string getName();
	ll getFileSize();
	ll getSector();
	string getAttributes();
	dateTime getDateCreate();
	dateTime getLastAccess();
	dateTime getLatstEdit();
	ll getClusterStart();
	vector<ll> getListSector();
};
