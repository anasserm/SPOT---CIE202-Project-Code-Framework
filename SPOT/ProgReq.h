#pragma once

#include <string>
#include <vector>
using namespace std;

class ProgReq
{
	int totalCredit;
	int UniComplsoryCredit;
	int UniElectiveCredit;
	int TrackComplsoryCredit;
	int MajorCommonComplsoryCredit;
	int MajorCommonElectiveCredit;
	int NumOfConecntrations;
	int MajorConcentration1ComplsoryCredit;
	int MajorConcentration1ElectiveCredit;

	vector<string> UniComplsoryCrs;
	vector<string> UniElectiveCrs;
	vector<string> TrackCrs;
	vector<string> MajorCommonComplsoryCrs;
	vector<string> MajorCommonElectiveCrs;
	
public:

	void addUniComplsoryCrs(string s);
	void addUniElectiveCrs(string s);
	void addTrackCrs(string s);
	void addMajorCommonComplsoryCrs(string s);
	void addMajorCommonElectiveCrs(string s);

	vector<string> getUniComplsoryCrs()  ;
	vector<string> getUniElectiveCrs()  ;
	vector<string> getTrackCrs()  ;
	vector<string> getMajorCommonComplsoryCrs()  ;
	vector<string> getMajorCommonElectiveCrs() ;

	void setTotalCredit(int s);
	void setUniComplsoryCredit(int s);
	void setUniElectiveCredit(int s);
	void setTrackComplsoryCredit(int s);
	void setMajorCommonComplsoryCredit(int s);
	void setMajorCommonElectiveCredit(int s);
	void setNumOfConecntrations(int s);
	void setMajorConcentration1ComplsoryCredit(int s);
	void setMajorConcentration1ElectiveCredit(int s);


	int getTotalCredit( );
	int getUniComplsoryCredit( ) ;
	int getUniElectiveCredit( ) ;
	int getTrackComplsoryCredit( ) ;
	int getMajorCommonComplsoryCredit( ) ;
	int getMajorCommonElectiveCredit( ) ;
	int getNumOfConecntrations( ) ;
	int getMajorConcentration1ComplsoryCredit( ) ;
	int getMajorConcentration1ElectiveCredit( ) ;





};

