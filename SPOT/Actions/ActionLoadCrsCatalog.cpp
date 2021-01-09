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
	ifstream finput("Catalog.txt");
	string key = "Coreq";
	while (!finput.eof())
	{
		string title, name, crd, co, pre;
		char* pch;
		char* context = nullptr;
		const int size = 300;
		char line[size];
		finput.getline(line, size);

		// get course code name 
		pch = strtok_s(line, ",", &context);
		name = pch;
		// get course title 
		pch = strtok_s(NULL, ",", &context);
		title = pch;
		// get credits
		pch = strtok_s(NULL, ",", &context);
		int cre = stoi(pch);
		Course* pCrs = new Course(name, title, cre);

		pch = strtok_s(NULL, ":", &context);
		if (pch == key)
		{
			pch = strtok_s(NULL, ":", &context);         // string of co + ,req
			co = pch;
			list<string >CoReq = pCrs->getCoReq();
			list<string >PreReq = pCrs->getPreReq();
			stringstream coreq(co);
			while (coreq.good()) {
				string substr;
				getline(coreq, substr, ',');              //get first string delimited by comma
				CoReq.push_back(substr);
			}
			CoReq.pop_back();
			pch = strtok_s(NULL, ":", &context); // string of pre req
			pre = pch;

			stringstream prereq(pre);

			while (prereq.good()) {
				string sub;
				getline(prereq, sub, ',');          //get first string delimited by comma
				PreReq.push_back(sub);
			}
		}

		Pcata->addCrs(pCrs);

	}

	
		return true;
}

ActionLoadCrsCatalog::~ActionLoadCrsCatalog()
{
}
