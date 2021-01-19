#include "ActionLoadStdyPlan.h"

using namespace std;

ActionLoadStdyPlan::ActionLoadStdyPlan(Registrar* p) :Action(p)
{

}

bool ActionLoadStdyPlan::Execute()
{
	StudyPlan* myStudyplan = pReg->getStudyPlay();
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Enter the name of the study plan to be loaded: 1=SPC, 2=CIE, 3=ENV, 4=NAN, 5=PEU, 6=REE  ");
	string file_name = pGUI->GetSrting();
	int n = stoi(file_name);

	while (n > 7 || n < 1)
	{
		pGUI->PrintMsg("Error, please enter the name of your plan coorectly: 1=SPC, 2=CIE, 3=ENV, 4=NAN, 5=PEU, 6=REE  ");
		string file_name = pGUI->GetSrting();
		n = stoi(file_name);
	}
	
	string path;
	if (n == 1)
		path = "Files/plan/SPC.txt";
	else if (n == 2)
		path = "/Files/plan/REE.txt";
	else if (n == 3)
		path = "Files/plan/ENV.txt";
	else if (n == 4)
		path = "Files/plan/CIE.txt";
	else if (n == 5)
		path = "Files/plan/NAN.txt";
	else if (n == 6)
		path = "Files/plan/PEU.txt";

	ifstream finput(path);

	char* pch;
	char* context = nullptr;
	const int size = 300;
	char line[size];
	int count, x, y;
	graphicsInfo gInfo;
	int num;
	while (finput.getline(line, size))
	{
		//parse the line
		pch = strtok_s(line, ",", &context);
		while (pch != NULL)
		{

			pGUI->PrintMsg(pch);
			string year_s = pch;
			year_s = year_s.substr(5, 1);
			int year = stoi(year_s);

			pch = strtok_s(NULL, ",", &context);
			SEMESTER sem;
			static std::unordered_map<std::string, SEMESTER> const table = { {"Summer",SEMESTER::SUMMER}, {"Fall",SEMESTER::FALL}, {"Spring",SEMESTER::SPRING} };
			auto it = table.find(pch);
			sem = it->second;

			pch = strtok_s(NULL, ",", &context);
			
			while (pch != NULL) {
				Course_Code cc = pch;
				Course* pCrs = new Course(cc, "Lebron", 3);
				count = getnCourses(year, sem);
				x = semToX(count, sem);
				y = yearToY(year, count);

				//cin >> num;
				gInfo.x = x;
				gInfo.y = y;


				pCrs->setGfxInfo(gInfo);
				myStudyplan->AddCourse(pCrs, year, sem);
				pch = strtok_s(NULL, ",", &context);
			}

		}
	}

	myStudyplan->DrawMe(pGUI);


	// STEP 3: Close the file.
	finput.close();
	return true;
}


int ActionLoadStdyPlan::getnCourses(int year, SEMESTER sem) const {
	StudyPlan* pS = pReg->getStudyPlay();
	int countCourses = pS->getYearCourses(year, sem);


	return countCourses;
}

int ActionLoadStdyPlan::semToX(int count, SEMESTER sem) const
{
	GUI* pGUI = pReg->getGUI();
	int cellWidth = pGUI->getCellWidth();
	return ((int)sem + 1) * cellWidth + ((count % 4) * 75);
}

int ActionLoadStdyPlan::yearToY(int year, int count) const
{
	GUI* pGUI = pReg->getGUI();
	int cellHeight = pGUI->getCellHeight();
	int menuBarHight = pGUI->getMenuBarHgight();


	return ((year*cellHeight) + menuBarHight) + (count / 4) * 50;
}


ActionLoadStdyPlan::~ActionLoadStdyPlan()
{
}
