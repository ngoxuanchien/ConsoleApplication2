#pragma once

#include "Function.h"
#include<string>

# define ll long long

using namespace std;

class NTFS
{
private:
	ll _sizeSector;
	ll _sizeCluster;
	ll _sizeVolume;
	ll _mediaDescriptor;
	ll _sectorsPerTrack;
	ll _numberOfHeads;
	ll _hiddenSectors;
	ll _clusterMFT;
	ll _clusterMFTMirr;
	ll _clusterPerFileRecord;
	ll _clusterPerIndexBlock;
	string _serialNnumberVolume;
	string _bootstrapCode;
	string _signature;

public:
	NTFS();
	//NTFS(LPCWSTR);
	~NTFS();

	void setMediaDescriptor(const ll&);
	void setSectorsPerTrack(const ll&);
	void setNumberOfHeads(const ll&);
	void setHiddenSectors(const ll&);
	void setClusterMFT(const ll&);
	void setClusterMFTMirr(const ll&);
	void setClusterPerFileRecord(const ll&);
	void setClusterPerIndexBlock(const ll&);
	void setSerialNnumberVolume(const string&);
	void setBootstrapCode(const string&);
	void setSignature(const string&);

	ll getMediaDescriptor();
	ll getSectorsPerTrack();
	ll getNumberOfHeads();
	ll getHiddenSectors();
	ll getClusterMFT();
	ll getClusterMFTMirr();
	ll getClusterPerFileRecord();
	ll getClusterPerIndexBlock();
	string getSerialNnumberVolume();
	string getBootstrapCode();
	string getSignature();

	int readPBS(LPCWSTR);
	void xuat();
};

