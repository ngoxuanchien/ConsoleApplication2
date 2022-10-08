#pragma once
#include <string>
#include <vector>

using namespace std;

#define ll long long

struct dateTime
{
	int date, month, year, hour, minute, second, milisecond;
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
	vector<ll> _listSec;

public:

	File();
	~File();

	// setter
	void setName(const string&);
	void setSize(const ll&);
	void setSector(const ll&);
	void setListSector(vector<ll>);

	// getter
	string getName();
	ll getSize();
	ll getSector();
	string getStatus();
	vector<ll> getListSector();

};

