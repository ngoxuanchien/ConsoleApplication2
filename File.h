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
	vector<ll> _listSec;

public:

	File();
	~File();

};

