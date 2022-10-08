#pragma once
#include <string>
#include <vector>

using namespace std;

#define ll long long

class File
{
protected:
	string _name;
	ll _size;
	ll _sector;
	string _status;
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

