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
	ifstream finput("../Files/cata.txt");
	while (!finput.eof())
	{
		string title, name, crd, co, pre;
		char* pch;  char* ch;
		char* context = nullptr;
		const int size = 300;
		char line[size];
		finput.getline(line, size);
		
		// get course code name 
		pch = strtok_s(line, ",", &context);
		cout << pch<<endl;
		name = pch;
		// get course title 
		pch = strtok_s(NULL, ",", &context); 
		// get credits
		pch = strtok_s(NULL, ",", &context);
		char* c[1];
		c[0] = pch;
		int cre;
		cre = stoi(c[0]);
		
		Course* pCrs = new Course(name, title, cre);
		vector<string >CoReq = pCrs->getCoReq();
		vector<string >PreReq = pCrs->getPreReq();

		pch = strtok_s(NULL, ":", &context); cout << pch << endl;
		
		if (pch != NULL)
		{

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

	
		return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
