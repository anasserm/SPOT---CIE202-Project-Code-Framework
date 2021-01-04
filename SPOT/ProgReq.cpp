#include "ProgReq.h"

void ProgReq::addUniComplsoryCrs(string s)
{
	UniComplsoryCrs.push_back(s);
}

void ProgReq::addUniElectiveCrs(string s)
{
	UniElectiveCrs.push_back(s);
}

void ProgReq::addTrackCrs(string s)
{
	TrackCrs.push_back(s);
}

void ProgReq::addMajorCommonComplsoryCrs(string s)
{
	MajorCommonComplsoryCrs.push_back(s);
}

void ProgReq::addMajorCommonElectiveCrs(string s)
{
	MajorCommonElectiveCrs.push_back(s);
}

vector<string> ProgReq::getUniComplsoryCrs()  
{
	return UniComplsoryCrs;
}

vector<string> ProgReq::getUniElectiveCrs()  
{
	return vector<string>(UniElectiveCrs);
}

vector<string> ProgReq::getTrackCrs()  
{
	return vector<string>(TrackCrs);
}

vector<string> ProgReq::getMajorCommonComplsoryCrs()  
{
	return vector<string>(MajorCommonComplsoryCrs);
}

vector<string> ProgReq::getMajorCommonElectiveCrs()  
{
	return vector<string>(MajorCommonElectiveCrs);
}

void ProgReq::setTotalCredit(int s)
{
	this->totalCredit = s;
}

void ProgReq::setUniComplsoryCredit(int s)
{
	this->UniComplsoryCredit = s;
}

void ProgReq::setUniElectiveCredit(int s)
{
	this->UniElectiveCredit = s;
}

void ProgReq::setTrackComplsoryCredit(int s)
{
	this->TrackComplsoryCredit = s;
}

void ProgReq::setMajorCommonComplsoryCredit(int s)
{
	this->MajorCommonComplsoryCredit = s;
}

void ProgReq::setMajorCommonElectiveCredit(int s)
{
	this->MajorCommonElectiveCredit = s;
}

void ProgReq::setNumOfConecntrations(int s)
{
	this->NumOfConecntrations = s;
}

void ProgReq::setMajorConcentration1ComplsoryCredit(int s)
{
	this->MajorConcentration1ComplsoryCredit = s;
}

void ProgReq::setMajorConcentration1ElectiveCredit(int s)
{
	this->MajorConcentration1ElectiveCredit = s;
}

int ProgReq::getTotalCredit()  
{
	return totalCredit;
}

int ProgReq::getUniComplsoryCredit()  
{
	return UniComplsoryCredit;
}

int ProgReq::getUniElectiveCredit()  
{
	return UniElectiveCredit;
}

int ProgReq::getTrackComplsoryCredit()  
{
	return TrackComplsoryCredit;
}

int ProgReq::getMajorCommonComplsoryCredit()  
{
	return MajorCommonComplsoryCredit;
}

int ProgReq::getMajorCommonElectiveCredit()  
{
	return MajorCommonElectiveCredit;
}

int ProgReq::getNumOfConecntrations()  
{
	return NumOfConecntrations;
}

int ProgReq::getMajorConcentration1ComplsoryCredit()  
{
	return MajorConcentration1ComplsoryCredit;
}

int ProgReq::getMajorConcentration1ElectiveCredit()  
{
	return MajorCommonElectiveCredit;
}

