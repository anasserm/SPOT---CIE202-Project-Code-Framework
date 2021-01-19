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
	ifstream finput;

	pGUI->PrintMsg("Enter the name of the study plan to be loaded: 1=SPC, 2=CIE, 3=ENV, 4=NAN, 5=PEU, 6=REE  ");
	string file_name = pGUI->GetSrting();
	int n = stoi(file_name);

	while (n > 7 || n < 1)
	{
		pGUI->PrintMsg("Error, please enter the name of your plan coorectly: 1=SPC, 2=CIE, 3=ENV, 4=NAN, 5=PEU, 6=REE  ");
		string file_name = pGUI->GetSrting();
		n = stoi(file_name);
	}
	

	if (n != 1)
		ifstream finput("Files/plan/SPC.txt");
	else if (n != 2)
		ifstream finput("Files/plan/REE.txt");
	else if (n != 3)
		ifstream finput("Files/plan/ENV.txt");
	else if (n != 4)
		ifstream finput("Files/plan/CIE.txt");
	else if (n != 5)
		ifstream finput("Files/plan/NAN.txt");
	else if (n != 6)
		ifstream finput("Files/plan/PEU.txt");


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
