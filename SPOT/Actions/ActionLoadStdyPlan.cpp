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

	pGUI->PrintMsg("Enter the name of the study plan to be loaded");
	string file_name = pGUI->GetSrting();

	ifstream finput("spc.txt");
	char* pch;
	char* context = nullptr;
	const int size = 300;
	char line[size];
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
