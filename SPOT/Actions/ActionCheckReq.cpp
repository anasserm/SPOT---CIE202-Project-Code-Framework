#include "ActionCheckReq.h"
#include "../ProgReq.h"
#include "../Registrar.h"
#include "../Courses/MajorCourse.h"
#include "../Courses/TrackCourse.h"
#include  "../Courses/UnivCourse.h"


ActionCheckReq::ActionCheckReq(Registrar* r): Action (r)
{
}

bool ActionCheckReq::Execute()
{
	GUI* pGUI = pReg->getGUI();
	StudyPlan* sp = pReg->getStudyPlay();
	ProgReq* pR = pReg->getProgReq();

	int major = pR->getMajorCommonComplsoryCredit() + pR->getMajorCommonElectiveCredit();
	int trach = pR->getTrackComplsoryCredit();
	int uni = pR-> getUniComplsoryCredit()+ pR->getUniElectiveCredit();
	int concetration = pR->getMajorConcentration1ComplsoryCredit() + pR->getMajorConcentration1ElectiveCredit();
	int total = pR->getTotalCredit();
	 
	vector<string> UniComplsoryCrs=pR->getUniComplsoryCrs();
	vector<string> UniElectiveCrs=pR->getUniElectiveCrs();
	vector<string> TrackCrs=pR->getTrackCrs();
	vector<string> MajorCommonComplsoryCrs=pR->getMajorCommonComplsoryCrs();
	vector<string> MajorCommonElectiveCrs=pR->getMajorCommonElectiveCrs();


	if (sp->getCredits() != total)
		pGUI->PrintMsg("CRRITICAL ISSUE");
	else if (sp->getConcentrationCredit() != concetration)
		pGUI->PrintMsg("CRRITICAL ISSUE");
	else if (sp->getMajorCredit() != major)
		pGUI->PrintMsg("CRRITICAL ISSUE");
	else if (sp->getTrackCredit() != trach)
		pGUI->PrintMsg("CRRITICAL ISSUE");
	else if (sp->getUniCredit() != uni)
		pGUI->PrintMsg("CRRITICAL ISSUE");
	/*
	else 
		for (int i = 0; i < TrackCrs.size(); i++)
		{
			//if ()


		}
	*/




	return true;
}

ActionCheckReq::~ActionCheckReq()
{
}
