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

	pGUI->PrintMsg("Enter the name of the study plan to be loaded: SPC, CIE, ENV, NAN, PEU, REE ");
	string file_name = pGUI->GetSrting();

	while (file_name != "SPC" || file_name != "REE"  || file_name != "NAN"  || file_name != "ENV"  || file_name != "CIE"  || file_name != "PEU")
	{
		pGUI->PrintMsg("Error, please enter the name of the study plan coorectly: SPC, CIE, ENV, NAN, PEU, REE ");
		string file_name = pGUI->GetSrting();
	}

	if (file_name=="SPC")
	ifstream finput("Files/plan/SPC.txt");
	else if (file_name == "REE")
		ifstream finput("Files/plan/REE.txt");
	else if (file_name == "ENV")
		ifstream finput("Files/plan/ENV.txt");
	else if (file_name == "CIE")
		ifstream finput("Files/plan/CIE.txt");
	else if (file_name == "NAN")
		ifstream finput("Files/plan/NAN.txt");
	else if (file_name == "PEU")
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
