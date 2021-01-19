#include "ActionLoadStdyPlan.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map> 
using namespace std;

ActionLoadStdyPlan::ActionLoadStdyPlan(Registrar* p) :Action(p)
{

}

bool ActionLoadStdyPlan::Execute()
{
	StudyPlan* myStudyplan = pReg->getStudyPlay();
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Enter the name of the study plan to be loaded: SPC, CIE, ENV, NAN, PEU, REE ");
	string file_name = pGUI->GetSrting();
	int n = stoi(file_name);

	while (n > 7 || n < 1)
	{
		pGUI->PrintMsg("Error, please enter the name of your plan coorectly: SPC, CIE, ENV, NAN, PEU, REE ");
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
	while (finput.getline(line, size))
	{
		//parse the line
		pch = strtok_s(line, ",", &context);
		cout << pch << endl;
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
				myStudyplan->AddCourse(new Course(cc, "Lebron", 3), year, sem);
				pch = strtok_s(NULL, ",", &context);
			}

		}
		cout << endl;
	}

	myStudyplan->DrawMe(pGUI);


	// STEP 3: Close the file.
	finput.close();
	return true;


}

ActionLoadStdyPlan::~ActionLoadStdyPlan()
{
}
