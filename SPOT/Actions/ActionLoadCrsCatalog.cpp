#include "ActionLoadCrsCatalog.h"
#include "..\CrsCatalog.h"
#include <fstream>
#include <vector>
#include <sstream>
#include "../Registrar.h"
#include <iostream>
#include <string>


ActionLoadCrsCatalog::ActionLoadCrsCatalog(Registrar*p) :Action(p)
{
}

bool ActionLoadCrsCatalog::Execute()
{
	GUI* pGUI = pReg->getGUI();
	
	CrsCatalog* Pcata = pReg->getCrsCatalog();
	ifstream finput("Files/cata.txt");
	while (!finput.eof())
	{
		string title, name, co, pre; int i = 0;
		char* pch;  char* ch;
		char* context = nullptr;
		const int size = 300;
		char line[size];
		finput.getline(line, size);
		string s = strtok_s(line, "", &context);
		i += s.size();
		// get course code name
		pch = strtok_s(line, ",", &context);
		name = pch;
		i -= name.size();
		// get course title
		pch = strtok_s(NULL, ",", &context); 
		title = pch;
		i -= title.size();
		// get credits
		pch = strtok_s(NULL, ",", &context); 
		string cr = pch;
		i -= cr.size();
		i = i - 3;
		int cre = stoi(pch);
		
		Course* pCrs = new Course(name, title, cre);
		vector<string >CoReq = pCrs->getCoReq();
		vector<string >PreReq = pCrs->getPreReq();

		 
		if (i > 0)
		{
			pch = strtok_s(NULL, ":", &context);
			if (pch[1] == 'P') // only prerequisit
			{
				pch = strtok_s(NULL, "", &context);
				ch = strtok_s(pch, "", &context);
				pre = ch;

				stringstream prereq(pre);
				while (prereq.good()) {
					string sub;
					getline(prereq, sub, ',');
					PreReq.push_back(sub);
				}
				PreReq.pop_back();

			}
			else // coreq is found 
			{

				ch = strtok_s(NULL, ":", &context);         // string of co + ,req
				co = ch;
				stringstream coreq(co);
				while (coreq.good()) {
					string substr;
					getline(coreq, substr, ',');              //get first string delimited by comma

					CoReq.push_back(substr);
				}
				if (CoReq.size() > 1)
				{
					CoReq.pop_back();
					CoReq.pop_back();
				}

				ch = strtok_s(NULL, ":", &context); // string of pre req

				if (ch != NULL)
				{
					pre = ch;
					stringstream prereq(pre);


					while (prereq.good()) {
						string sub;
						getline(prereq, sub, ',');          //get first string delimited by comma
						PreReq.push_back(sub);
					}

					PreReq.pop_back();

				}

			}

		}
		
		
		Pcata->addCrs(pCrs);
		
	}
	
	ifstream file("Files/crs.txt");
	while (!file.eof())
	{ 
		string type,code;
		char* pch; 
		char* context = nullptr;
		const int size = 50;
		char line[size];

		file.getline(line, size);
		vector<Course*> crs = Pcata->Courses;
		pch = strtok_s(line, ",", &context);
		code = pch;

		pch = strtok_s(NULL, ",", &context);
		type = pch;

		for (int i=0;i<crs.size();i++)
		{
			if (!code.compare(crs[i]->getCode()))
				crs[i]->setType(type);
			else 
				continue;
		}

	}

		return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
